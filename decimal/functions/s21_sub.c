#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_256 v1;
  s21_256 v2;
  s21_256 res;

  s21_from_decimal_to_256(value_1, &v1);
  s21_from_decimal_to_256(value_2, &v2);

  s21_256_sub(v1, v2, &res);

  int status = s21_256_validate(res);

  s21_from_256_to_decimal(res, result);

  return status;
}