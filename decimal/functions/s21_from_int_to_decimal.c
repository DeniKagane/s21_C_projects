#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (dst) {
    s21_set_zero_decimal(dst);
    if (src < 0) {
      if (src != INT_MIN) {
        src = -src;
      }
      s21_set_sign(dst, 1);
    }
    dst->bits[0] = src;
  } else
    res = 1;
  return res;
}