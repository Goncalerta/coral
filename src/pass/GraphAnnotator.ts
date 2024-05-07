import FlowNode from "clava-flow/flow/node/FlowNode";
import ConditionNode from "clava-flow/flow/node/condition/ConditionNode";
import ExpressionNode from "clava-flow/flow/node/instruction/ExpressionNode";
import FunctionEntryNode from "clava-flow/flow/node/instruction/FunctionEntryNode";
import ReturnNode from "clava-flow/flow/node/instruction/ReturnNode";
import ScopeEndNode from "clava-flow/flow/node/instruction/ScopeEndNode";
import ScopeStartNode from "clava-flow/flow/node/instruction/ScopeStartNode";
import SwitchNode from "clava-flow/flow/node/instruction/SwitchNode";
import VarDeclarationNode from "clava-flow/flow/node/instruction/VarDeclarationNode";
import LivenessNode from "clava-flow/flow/transformation/liveness/LivenessNode";
import BaseGraph from "clava-flow/graph/BaseGraph";
import { GraphTransformation } from "clava-flow/graph/Graph";
import {
    BinaryOp,
    BuiltinType,
    Call,
    ElaboratedType,
    EnumDecl,
    ExprStmt,
    Expression,
    FunctionJp,
    If,
    Literal,
    Loop,
    MemberAccess,
    Param,
    ParenExpr,
    ParenType,
    PointerType,
    QualType,
    RecordJp,
    ReturnStmt,
    Scope,
    TagType,
    Type,
    TypedefType,
    UnaryOp,
    Vardecl,
    Varref,
} from "clava-js/api/Joinpoints.js";
import LifetimeReassignmentError from "coral/error/struct/LifetimeReassignmentError";
import UnexpectedLifetimeAssignmentError from "coral/error/struct/UnexpectedLifetimeAssignmentError";
import CoralGraph from "coral/graph/CoralGraph";
import CoralNode from "coral/graph/CoralNode";
import Access from "coral/mir/Access";
import Loan from "coral/mir/Loan";
import Path from "coral/mir/path/Path";
import PathDeref from "coral/mir/path/PathDeref";
import PathMemberAccess from "coral/mir/path/PathMemberAccess";
import PathVarRef from "coral/mir/path/PathVarRef";
import BorrowKind from "coral/mir/ty/BorrowKind";
import BuiltinTy from "coral/mir/ty/BuiltinTy";
import RefTy from "coral/mir/ty/RefTy";
import StructTy from "coral/mir/ty/StructTy";
import Ty from "coral/mir/ty/Ty";
import CoralPragma from "coral/pragma/CoralPragma";
import LifetimeBoundPragma from "coral/pragma/LifetimeBoundPragma";
import LifetimeAssignmentPragma from "coral/pragma/lifetime/LifetimeAssignmentPragma";
import LfPath from "coral/pragma/lifetime/path/LfPath";
import LfPathDeref from "coral/pragma/lifetime/path/LfPathDeref";
import LfPathMemberAccess from "coral/pragma/lifetime/path/LfPathMemberAccess";
import LfPathVarRef from "coral/pragma/lifetime/path/LfPathVarRef";
import RegionVariable from "coral/regionck/RegionVariable";
import Regionck from "coral/regionck/Regionck";
import Query from "lara-js/api/weaver/Query.js";

export default class GraphAnnotator implements GraphTransformation {
    #regionck?: Regionck;

    apply(graph: BaseGraph.Class): void {
        if (!graph.is(CoralGraph.TypeGuard)) {
            throw new Error("GraphAnnotator can only be applied to CoralGraphs");
        }

        const coralGraph = graph.as(CoralGraph.Class);

        for (const functionEntry of coralGraph.functions) {
            this.#regionck = coralGraph.getRegionck(functionEntry);
            this.#annotateFunction(functionEntry);
        }
    }

    #annotateFunction(functionEntry: FunctionEntryNode.Class) {
        this.#annotateFunctionSignature(functionEntry.jp);

        for (const node of functionEntry.reachableNodes) {
            if (!node.is(FlowNode.TypeGuard)) {
                continue;
            }

            if (!node.is(LivenessNode.TypeGuard)) {
                node.init(new LivenessNode.Builder());
            }

            const coralNode = node.init(new CoralNode.Builder()).as(CoralNode.Class);

            if (node.is(ScopeStartNode.TypeGuard)) {
                const scopeStartNode = node.as(ScopeStartNode.Class);
                this.#annotateScope(coralNode, scopeStartNode.jp, "start");
            } else if (node.is(ScopeEndNode.TypeGuard)) {
                const scopeEndNode = node.as(ScopeEndNode.Class);
                this.#annotateScope(coralNode, scopeEndNode.jp, "end");
            } else if (node.is(VarDeclarationNode.TypeGuard)) {
                const varDeclarationNode = node.as(VarDeclarationNode.Class);
                if (varDeclarationNode.jp instanceof Param) {
                    continue;
                }
                this.#annotateVarDecl(coralNode, varDeclarationNode.jp);
            } else if (node.is(ExpressionNode.TypeGuard)) {
                const expressionNode = node.as(ExpressionNode.Class);
                this.#annotateExpr(coralNode, expressionNode.jp);
            } else if (node.is(SwitchNode.TypeGuard)) {
                const switchNode = node.as(SwitchNode.Class);
                this.#annotateExpr(coralNode, switchNode.jp.condition);
            } else if (node.is(ReturnNode.TypeGuard)) {
                const returnNode = node.as(ReturnNode.Class);
                this.#annotateExpr(coralNode, returnNode.jp.returnExpr);
            } else if (node.is(ConditionNode.TypeGuard)) {
                const conditionNode = node.as(ConditionNode.Class);
                const $jp = conditionNode.jp;
                if ($jp instanceof If) {
                    this.#annotateExpr(coralNode, $jp.cond);
                } else if ($jp instanceof Loop) {
                    this.#annotateExpr(coralNode, ($jp.cond as ExprStmt).expr);
                }
            }
        }
    }

    #annotateFunctionSignature($jp: FunctionJp) {
        const coralPragmas = CoralPragma.parse($jp.pragmas);
        
        // Static lifetime
        this.#regionck!.newRegionVar(RegionVariable.Kind.UNIVERSAL, "%static");

        // Lifetime Bounds
        const potentialBoundPragmas = coralPragmas.filter(
            (p) =>
                p.name === LifetimeAssignmentPragma.keyword &&
                p.tokens.some((token) => token === "="),
        );
        const lifetimeBoundPragmas = LifetimeBoundPragma.parse(potentialBoundPragmas);
        for (const lifetimeBoundPragma of lifetimeBoundPragmas) {
            if (lifetimeBoundPragma.bound === undefined) {
                continue;
            }
            this.#regionck!.bounds.push(lifetimeBoundPragma);
        }
        
        // Other lifetimes
        const potentialAssignmentPragmas = coralPragmas.filter(
            (p) =>
                p.name === LifetimeAssignmentPragma.keyword &&
                p.tokens.some((token) => token !== "="),
        );
        const lifetimeAssignmentPragmas = LifetimeAssignmentPragma.parse(
            potentialAssignmentPragmas,
        );
        let lifetimeAssignments = new Map<
            string,
            [LfPath, RegionVariable, LifetimeAssignmentPragma][]
            >();
        let lifetimes = new Map<string, RegionVariable>();
        for (const lifetimeAssignmentPragma of lifetimeAssignmentPragmas) {
            const lfPath = lifetimeAssignmentPragma.lhs;
            let regionVar = lifetimes.get(lifetimeAssignmentPragma.rhs);
            if (regionVar === undefined) {
                regionVar = this.#regionck!.newRegionVar(
                    RegionVariable.Kind.UNIVERSAL,
                    lifetimeAssignmentPragma.rhs,
                );
                lifetimes.set(lifetimeAssignmentPragma.rhs, regionVar);
            }
            
            if (lifetimeAssignments.has(lfPath.varName)) {
                lifetimeAssignments.get(lfPath.varName)!.push([lfPath, regionVar, lifetimeAssignmentPragma]);
            } else {
                lifetimeAssignments.set(lfPath.varName, [
                    [lfPath, regionVar, lifetimeAssignmentPragma],
                ]);
            }
        }

        // Return type
        const returnTy = this.#parseType(
            $jp.returnType,
            lifetimeAssignments.get("return"),
            RegionVariable.Kind.UNIVERSAL,
        );
        this.#regionck!.registerReturnTy(returnTy);

        // Params
        for (const $param of $jp.params) {
            const ty = this.#parseType(
                $param.type,
                lifetimeAssignments.get($param.name),
                RegionVariable.Kind.UNIVERSAL,
            );
            this.#regionck!.registerTy($param, ty);
        }
    }

    #annotateScope(node: CoralNode.Class, $scope: Scope, type: "start" | "end") {
        const vars = [];
        for (const $jp of Query.searchFrom($scope, "vardecl")) {
            const $vardecl = $jp as Vardecl;
            let $vardeclScope = $vardecl.parent;
            while (!($vardeclScope instanceof Scope)) {
                $vardeclScope = $vardeclScope.parent;
            }

            if ($vardeclScope.astId !== $scope.astId) {
                continue;
            }
            vars.push($vardecl);
        }

        if ($scope.parent instanceof FunctionJp) {
            const $fn = $scope.parent as FunctionJp;
            $fn.params.forEach((param) => {
                vars.push(param);
            });
        }

        if (type === "start") {
            node.varsEnteringScope = vars;
        } else {
            for (const $vardecl of vars) {
                const ty = this.#regionck!.getTy($vardecl);
                if (ty === undefined) {
                    throw new Error("Variable " + $vardecl.name + " not found");
                }
                node.accesses.push(
                    new Access(
                        new PathVarRef($vardecl, ty),
                        Access.Mutability.STORAGE_DEAD,
                        Access.Depth.SHALLOW,
                    ),
                );
            }
            node.varsLeavingScope = vars;
        }
    }

    #annotateVarDecl(node: CoralNode.Class, $vardecl: Vardecl) {
        const ty = this.#parseType($vardecl.type);
        this.#regionck!.registerTy($vardecl, ty);

        if ($vardecl.hasInit) {
            this.#annotateExpr(node, $vardecl.init);

            node.accesses.push(
                new Access(
                    new PathVarRef($vardecl, ty),
                    Access.Mutability.WRITE,
                    Access.Depth.SHALLOW,
                ),
            );
        }
    }

    #annotateExpr(node: CoralNode.Class, $expr: Expression | undefined) {
        if ($expr === undefined || $expr instanceof Literal) {
            return;
        }

        if ($expr instanceof BinaryOp) {
            this.#annotateBinaryOp(node, $expr);
        } else if ($expr instanceof UnaryOp) {
            this.#annotateUnaryOp(node, $expr);
        } else if ($expr instanceof Call) {
            this.#annotateFunctionCall(node, $expr);
        } else if ($expr instanceof Varref) {
            this.#annotateReadAccess(node, $expr);
        } else if ($expr instanceof ParenExpr) {
            this.#annotateExpr(node, $expr.subExpr);
        } else if ($expr instanceof MemberAccess) {
            this.#annotateReadAccess(node, $expr);
        } else {
            // TODO Unhandled:
            // Member Access -> this.#annotateReadAccess
            // UnaryExprOrType
            // ArrayAccess
            // Cast

            // TODO initializer expressions (e.g. `{1, 2}`) are not handled
            throw new Error(
                "Unhandled expression annotation for jp: " + $expr.joinPointType,
            );
        }
    }

    #annotateBinaryOp(node: CoralNode.Class, $binaryOp: BinaryOp) {
        if ($binaryOp.isAssignment) {
            this.#annotateExpr(node, $binaryOp.right);
            const path = this.#parseLvalue($binaryOp.left);
            node.accesses.push(
                new Access(path, Access.Mutability.WRITE, Access.Depth.SHALLOW),
            );
        } else {
            this.#annotateExpr(node, $binaryOp.left);
            this.#annotateExpr(node, $binaryOp.right);
        }
    }

    #annotateUnaryOp(node: CoralNode.Class, $unaryOp: UnaryOp) {
        if ($unaryOp.operator === "&") {
            const reborrow =
                Query.searchFrom($unaryOp, "unaryOp", { operator: "*" }).get() !==
                undefined;
            this.#annotateReference(node, $unaryOp, reborrow);
        } else if ($unaryOp.operator === "*") {
            this.#annotateReadAccess(node, $unaryOp);
        } else {
            this.#annotateExpr(node, $unaryOp.operand);
        }
    }

    #annotateReference(
        node: CoralNode.Class,
        $expr: Expression,
        reborrow: boolean,
        ty?: Ty,
    ) {
        let $parent = $expr.parent;
        while ($parent instanceof ParenExpr) {
            $parent = $parent.parent;
        }

        let leftTy: Ty | undefined;
        if ($parent instanceof BinaryOp && $parent.isAssignment) {
            leftTy = this.#parseLvalue($parent.left).ty;
        } else if ($parent instanceof Vardecl) {
            leftTy = this.#regionck!.getTy($parent);
        } else if ($parent instanceof ReturnStmt) {
            leftTy = this.#regionck!.getReturnTy();
        } else {
            // Assuming the weakest borrow is ok for `ref1;` but is not sound for `*(&a) = 5;`
            // Loan could be assumed to be the weakest borrow, but there is the risk that that is not sound.
            throw new Error("leftTy not found to annotate reference.");
        }

        if (!(leftTy instanceof RefTy)) {
            throw new Error(
                `Cannot borrow from non-reference type ${leftTy?.toString()}`,
            );
        }

        let loanedPath: Path | undefined;
        if ($expr instanceof UnaryOp && $expr.operator === "&") {
            loanedPath = this.#parseLvalue($expr.operand);
        } else {
            loanedPath = new PathDeref($expr, this.#parseLvalue($expr));
        }

        const regionVar = this.#regionck!.newRegionVar(RegionVariable.Kind.EXISTENTIAL);

        node.loan = new Loan(node, regionVar, reborrow, leftTy, loanedPath, ty);

        node.accesses.push(
            new Access(
                loanedPath,
                Access.Mutability.fromBorrowKind(leftTy.borrowKind),
                Access.Depth.DEEP,
            ),
        );
    }

    #annotateFunctionCall(node: CoralNode.Class, $call: Call) {
        // TODO
        throw new Error("Unimplemented annotateFunctionCall");
        // for (const $expr of $call.args) {
        //     const path = this.#parseLvalue($expr);
        //     // TODO: Set correct AccessMutability and AccessDepth (require knowing the function declaration)
        //     node.scratch("_coral").accesses.push(
        //         new Access(path, Access.Mutability.READ, Access.Depth.DEEP),
        //     );
        //     // TODO: Identify & mark moves
        // }
    }

    #annotateReadAccess(node: CoralNode.Class, $expr: Varref | UnaryOp | MemberAccess) {
        const path = this.#parseLvalue($expr);

        if (path.ty instanceof RefTy) {
            this.#annotateReference(node, $expr, true, path.ty.referent);
        } else {
            node.accesses.push(
                new Access(path, Access.Mutability.READ, Access.Depth.DEEP),
            );
        }
    }

    #parseType(
        $type: Type,
        lifetimeAssignments: [LfPath, RegionVariable, LifetimeAssignmentPragma][] = [],
        regionType: RegionVariable.Kind = RegionVariable.Kind.EXISTENTIAL,
        isConst = false,
        isRestrict = false,
    ): Ty {
        if ($type instanceof QualType) {
            if ($type.qualifiers.includes("const")) {
                isConst = true;
            }
            if ($type.qualifiers.includes("restrict")) {
                isRestrict = true;
            }
            $type = $type.unqualifiedType;
        }

        if ($type instanceof BuiltinType) {
            if (lifetimeAssignments.length > 0) {
                throw new UnexpectedLifetimeAssignmentError(lifetimeAssignments[0][2]);
            }
            return new BuiltinTy($type.builtinKind, $type, isConst);
        } else if ($type instanceof PointerType) {
            const innerLfs = lifetimeAssignments
                .filter(([lfPath]) => !(lfPath instanceof LfPathVarRef))
                .map(
                    ([lfPath, regionVar, pragma]): [
                        LfPath,
                        RegionVariable,
                        LifetimeAssignmentPragma,
                    ] => {
                        if (lfPath instanceof LfPathDeref) {
                            return [(lfPath as LfPathDeref).inner, regionVar, pragma];
                        } else if (lfPath instanceof LfPathMemberAccess) {
                            const lfPathInner = lfPath.inner;
                            if (!(lfPathInner instanceof LfPathDeref)) {
                                throw new UnexpectedLifetimeAssignmentError(pragma);
                            }
                            return [
                                new LfPathMemberAccess(lfPathInner.inner, lfPath.member),
                                regionVar,
                                pragma,
                            ];
                        }
                        throw new Error("Unhandled LfPath");
                    },
                );
            const inner = this.#parseType($type.pointee, innerLfs, regionType);
            if (inner.isConst && isRestrict) {
                throw new Error("Cannot have a restrict pointer to a const type");
            }
            const outer = lifetimeAssignments.filter(
                ([lfPath]) => lfPath instanceof LfPathVarRef,
            );
            if (outer.length > 1) {
                throw new LifetimeReassignmentError(outer[0][2], outer[0][2]);
            }
            let regionVar: RegionVariable;
            if (outer.length === 0) {
                regionVar = this.#regionck!.newRegionVar(regionType);
            } else {
                regionVar = outer[0][1];
            }
            return new RefTy(
                inner.isConst ? BorrowKind.SHARED : BorrowKind.MUTABLE,
                inner,
                $type,
                regionVar,
                isConst,
            );
        } else if ($type instanceof TypedefType) {
            return this.#parseType(
                $type.underlyingType,
                lifetimeAssignments,
                regionType,
                isConst,
                isRestrict,
            );
        } else if ($type instanceof ElaboratedType) {
            return this.#parseType(
                $type.namedType,
                lifetimeAssignments,
                regionType,
                isConst,
                isRestrict,
            );
        } else if ($type instanceof ParenType) {
            return this.#parseType(
                $type.innerType,
                lifetimeAssignments,
                regionType,
                isConst,
                isRestrict,
            );
        } else if ($type instanceof TagType) {
            const $decl = $type.decl;
            if ($decl instanceof RecordJp) {
                const invalidMetaRegionVarAssignment = lifetimeAssignments.find(
                    ([lfPath]) => !(lfPath instanceof LfPathMemberAccess),
                );
                if (invalidMetaRegionVarAssignment !== undefined) {
                    throw new UnexpectedLifetimeAssignmentError(
                        invalidMetaRegionVarAssignment[2],
                    );
                }

                const structDef = this.#regionck!.structDefs.get($decl);

                const regionVars = new Map<string, RegionVariable>();

                for (const [lfPath, regionVar, pragma] of lifetimeAssignments) {
                    const memberAccess = lfPath as LfPathMemberAccess;
                    const memberAccessInner = memberAccess.inner;
                    if (!(memberAccessInner instanceof LfPathVarRef)) {
                        throw new UnexpectedLifetimeAssignmentError(pragma);
                    }

                    regionVars.set(memberAccess.member, regionVar);
                }

                for (const metaRegionVar of structDef.metaRegionVars) {
                    if (!regionVars.has(metaRegionVar.name)) {
                        regionVars.set(
                            metaRegionVar.name,
                            this.#regionck!.newRegionVar(regionType),
                        );
                    }
                }

                return new StructTy(structDef, regionVars, isConst);
            } else if ($decl instanceof EnumDecl) {
                if (lifetimeAssignments.length > 0) {
                    throw new UnexpectedLifetimeAssignmentError(
                        lifetimeAssignments[0][2],
                    );
                }
                return new BuiltinTy(`enum ${$decl.name}`, $decl, isConst);
            } else {
                // TypedefNameDecl;
                //     TypedefDecl;
                throw new Error("Unhandled parseType TagType: " + $decl.joinPointType);
            }
        } else {
            // UndefinedType;
            // AdjustedType;
            // ArrayType;
            //     VariableArrayType;
            // FunctionType;
            throw new Error("Unhandled parseType: " + $type.joinPointType);
        }
    }

    #parseLvalue($expr: Expression): Path {
        if ($expr instanceof Varref) {
            const ty = this.#regionck!.getTy($expr.vardecl);
            // TODO will there not be problems if the order of the nodes is different?
            if (ty === undefined) {
                throw new Error("Variable " + $expr.name + " not found");
            }

            return new PathVarRef($expr, ty);
        } else if ($expr instanceof ParenExpr) {
            return this.#parseLvalue($expr.subExpr);
        } else if ($expr instanceof UnaryOp) {
            if ($expr.operator === "*") {
                const innerPath = this.#parseLvalue($expr.operand);
                return new PathDeref($expr, innerPath);
            } else {
                throw new Error("Unhandled parseLvalue unary op: " + $expr.operator);
            }
        } else if ($expr instanceof MemberAccess) {
            let inner = this.#parseLvalue($expr.base);
            if ($expr.arrow) {
                inner = new PathDeref($expr, inner);
            }

            return new PathMemberAccess($expr, inner, $expr.name);
        } else {
            throw new Error("Unhandled parseLvalue: " + $expr.joinPointType);
        }
    }
}
