#include "../s21_decimal.h"

int s21_from_int_to_256(int src, s21_256 *dst) {
  s21_256 zero = {0, 0, {0}};
  int res = 0;
  if (dst) {
    *dst = zero;
    if (src < 0) {
      if (src != INT_MIN) {
        src = -src;
      }
      dst->sign = 1;
    }
    for (int i = 0; i < 31; i++) {
      int tmp = (src >> i) & 1;
      dst->value[i] = tmp;
    }
  } else
    res = 1;
  return res;
}