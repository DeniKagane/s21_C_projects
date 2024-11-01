#include "../s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  return s21_is_greater(a, b) ^ 1 && s21_is_equal(a, b) == 0;
}
