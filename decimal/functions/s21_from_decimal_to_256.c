#include "../s21_decimal.h"

int s21_from_decimal_to_256(s21_decimal src, s21_256 *dst) {
  s21_256 zero = {0, 0, {0}};
  int res = 0;
  if (s21_check_decimal(&src)) {
    *dst = zero;
    dst->exp = s21_get_exp(src);
    dst->sign = s21_get_sign(src);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 32; j++) {
        dst->value[i * 32 + j] = s21_get_bit(src, j, i);
      }
    }
  } else
    res = 1;

  return res;
}