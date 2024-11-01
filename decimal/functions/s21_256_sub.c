#include "../s21_decimal.h"

int s21_256_sub(s21_256 v1, s21_256 v2, s21_256 *result) {
  s21_256 zero = {0, 0, {0}};
  s21_256 one = zero;
  s21_from_int_to_256(1, &one);

  s21_256 buff = zero;

  *result = zero;

  int sign;
  int status = 1;
  int remainder = 0;

  if (v1.sign == 1 && v2.sign == 0) {
    v2.sign = 1;
    status = s21_256_add(v1, v2, result);
  } else if (v1.sign == 0 && v2.sign == 1) {
    v2.sign = 0;
    status = s21_256_add(v1, v2, result);
  } else {
    sign = v1.sign;
    v1.sign = 0;
    v2.sign = 0;
    if (v1.exp != v2.exp) {
      s21_256_leveling(v1, v2, &v1, &v2);
    }
    if (!s21_256_is_equal(v1, v2)) {
      if (s21_256_is_greater(v1, v2)) {
        s21_256_inversion(&v2);

        for (int i = 0; i < 256; i++) {
          buff.value[i] =
              s21_256_bit_summ(v2.value[i], one.value[i], &remainder);
        }
        remainder = 0;

        for (int i = 0; i < 256; i++) {
          result->value[i] =
              s21_256_bit_summ(v1.value[i], buff.value[i], &remainder);
        }
      } else {
        s21_256_inversion(&v1);

        for (int i = 0; i < 256; i++) {
          buff.value[i] =
              s21_256_bit_summ(v1.value[i], one.value[i], &remainder);
        }
        remainder = 0;

        for (int i = 0; i < 256; i++) {
          result->value[i] =
              s21_256_bit_summ(v2.value[i], buff.value[i], &remainder);
        }

        if (sign)
          sign = 0;
        else
          sign = 1;
      }

      result->exp = v1.exp;
      result->sign = sign;
    }
  }

  return status;
}