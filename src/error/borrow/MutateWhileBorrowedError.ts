import CoralError from "coral/error/CoralError";
import ErrorMessageBuilder from "coral/error/ErrorMessageBuilder";
import Access from "coral/mir/Access";
import Loan from "coral/mir/Loan";
import { Joinpoint } from "clava-js/api/Joinpoints.js";

export default class MutateWhileBorrowedError extends CoralError {
    constructor($invalidUse: Joinpoint, loan: Loan, $nextUse: Joinpoint, access: Access) {
        super(
            new ErrorMessageBuilder(
                `Cannot write to '${access.path.toString()}' while borrowed`,
                $invalidUse,
            )
                .code(
                    loan.node.jp,
                    `(${loan.borrowKind}) borrow of '${loan.loanedPath.toString()}' occurs here`,
                )
                .code(
                    $invalidUse,
                    `write to '${access.path.toString()}' occurs here, while borrow is still active`,
                )
                .code($nextUse, "borrow is later used here")
                .toString(),
        );
        this.name = this.constructor.name;
    }
}
