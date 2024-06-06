#pragma coral_test expect MoveBehindReferenceError

#pragma coral move
struct C {
    int a;
};

int main() {
    struct C a;
    a.a = 0;
    struct C *restrict ref1 = &a;
    *ref1;

    return 0;
}
