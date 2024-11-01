#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  s21_256 v = {0, 0, {0}};
  s21_256 ten = {0, 0, {0}};
  s21_from_int_to_256(10, &ten);

  s21_from_decimal_to_256(src, &v);

  s21_from_256_to_float(v, dst);

  return s21_256_validate(v);
}