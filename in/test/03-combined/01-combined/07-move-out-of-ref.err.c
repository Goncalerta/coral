#pragma coral_test expect MoveBehindReferenceError

#pragma coral move
#pragma coral lf %a
struct A {
  #pragma coral lf a = %a
  const int *a;
};

#pragma coral lf a = %a
#pragma coral lf a->%a = %b
#pragma coral lf return = %b
const int *test(struct A *restrict a) {
  *a;
  return a->a;
}