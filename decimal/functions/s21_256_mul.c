#include "../s21_decimal.h"

int s21_256_mul(s21_256 v1, s21_256 v2, s21_256 *res) {
  s21_256 zero = {0, 0, {0}};

  *res = zero;

  int sign1 = v1.sign;
  int sign2 = v2.sign;
  int exp1 = v1.exp;
  int exp2 = v2.exp;
  int status = 0;

  if (!s21_256_is_equal(v1, zero) && !s21_256_is_equal(v2, zero)) {
    for (int i = 0; i < 256; i++) {
      if (v2.value[i] == 1) {
        s21_256 resBuffer = *res;
        s21_256_add(v1, resBuffer, res);
      }
      s21_256_left_shift(&v1);
    }
    res->exp = exp1 + exp2;
    if ((sign1 ^ sign2) == 1)
      res->sign = 1;
    else
      res->sign = 0;
  }
  return status;
}