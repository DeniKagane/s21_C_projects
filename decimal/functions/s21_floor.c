#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int status;
  s21_decimal minus_one = {{1, 0, 0, 0}};
  s21_set_sign(&minus_one, 1);

  if (s21_get_sign(value) == 0) {
    status = s21_truncate(value, result);
  } else {
    status = s21_truncate(value, result);
    s21_add(*result, minus_one, result);
  }

  return status;
}