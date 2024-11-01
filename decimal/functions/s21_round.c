#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int status = 0;
  s21_decimal trancated = {{0}};
  s21_decimal fraction = {{0}};
  s21_decimal half = {{5, 0, 0, 0}};
  s21_set_exp(&half, 1);
  s21_decimal one = {{1, 0, 0, 0}};

  if (!result) {
    status = 1;
  } else {
    status = s21_truncate(value, &trancated);

    s21_sub(value, trancated, &fraction);

    if (s21_is_greater_or_equal(fraction, half) == 1) {
      s21_add(trancated, one, result);
    } else {
      *result = trancated;
    }
  }
  return status;
}