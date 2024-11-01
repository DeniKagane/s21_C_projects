#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;

  if (s21_check_decimal(&src)) {
    *dst = (int)(src.bits[0] / pow(10, s21_get_exp(src)));
    if (s21_get_sign(src) == 1) {
      *dst = *dst * (-1);
    }
  } else {
    res = 1;
  }

  return res;
}