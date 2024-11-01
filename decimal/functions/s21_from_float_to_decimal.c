#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;

  s21_256 res = {0, 0, {0}};
  status = s21_from_float_to_256(src, &res);
  if (status == 0) {
    s21_from_256_to_decimal(res, dst);
  } else
    s21_set_zero_decimal(dst);
  return status;
}
