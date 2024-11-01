#include "../s21_decimal.h"

int s21_256_add(s21_256 v1, s21_256 v2, s21_256 *result) {
  s21_256 zero = {0, 0, {0}};

  *result = zero;

  s21_256 ten;
  s21_from_int_to_256(10, &ten);

  int remainder = 0;
  int sign1 = v1.sign;
  int sign2 = v2.sign;
  int status = 0;

  if (sign1 == 1 && sign2 == 0) {
    v1.sign = 0;
    status = s21_256_sub(v2, v1, result);
  } else if (sign1 == 0 && sign2 == 1) {
    v2.sign = 0;
    status = s21_256_sub(v1, v2, result);
  } else {
    if (v1.exp != v2.exp) {
      s21_256_leveling(v1, v2, &v1, &v2);
    }

    for (int i = 0; i < 256; i++) {
      result->value[i] = s21_256_bit_summ(v1.value[i], v2.value[i], &remainder);
    }
    result->sign = v1.sign;
    result->exp = v1.exp;
  }
  return status;
}