#pragma coral_test expect UseWhileMutBorrowedError

int main() {
	int a = 5;
	int *restrict ref1 = &a;
	const int *ref2 = ref1;
	int *restrict ref3 = &a;
    const int *ref4 = ref1;
	
	return 0;
}
