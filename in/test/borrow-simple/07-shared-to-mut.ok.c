int main() {
    const float a = 5.0;
    const float *ptr1, *ptr2;

    ptr1 = &a;
    ptr2 = &a;
    
    const float b = *ptr1;
    const float c = *ptr2;

    float *restrict ptr3 = ptr1;

    *ptr3 += 6.0;

    return 0;
}
