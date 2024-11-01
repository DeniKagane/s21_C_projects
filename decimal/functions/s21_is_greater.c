#include "../s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  s21_256 v1 = {0, 0, {0}};
  s21_256 v2 = {0, 0, {0}};

  s21_from_decimal_to_256(a, &v1);
  s21_from_decimal_to_256(b, &v2);

  return s21_256_is_greater(v1, v2);
}
