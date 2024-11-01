#include "../s21_decimal.h"

int s21_256_div(s21_256 v1, s21_256 v2, s21_256 *result) {
  s21_256 res;
  s21_256 rem;

  int status = divide_256(v1, v2, &res, &rem);

  s21_256_add(res, rem, result);

  return status;
}

int divide_256(s21_256 v1, s21_256 v2, s21_256 *res, s21_256 *rem) {
  s21_256 zero = {0, 0, {0}};

  s21_256 remainder = zero;
  s21_256 upper = zero;
  s21_from_int_to_256(1, &upper);
  s21_256_mult_10(&upper, 27);

  int exp = 0;
  int sign;
  int status = 0;

  *rem = zero;
  *res = zero;
  if (s21_256_is_value_zero(&v2)) {
    status = 3;
  } else if (s21_256_is_value_zero(&v1)) {
    status = 0;
  } else {
    if (v1.sign != v2.sign) {
      sign = 1;
    } else {
      sign = 0;
    }

    v1.sign = 0;
    v2.sign = 0;

    s21_256_leveling(v1, v2, &v1, &v2);

    v1.exp = 0;
    v2.exp = 0;

    while (s21_256_is_greater(v1, v2) == 0) {
      s21_256_mult_10(&v1, 1);
      exp++;
    }

    for (int i = 255; i >= 0; i--) {
      s21_256_left_shift(&remainder);
      if (v1.value[i] == 1) {
        remainder.value[0] = 1;
      }

      if (s21_256_is_greater(remainder, v2) ||
          s21_256_is_equal(remainder, v2)) {
        s21_256 divBuffer = zero;
        s21_256_sub(remainder, v2, &divBuffer);
        remainder = divBuffer;
        res->value[i] = 1;
      }
    }

    if (!s21_256_is_equal(remainder, zero)) {
      while (s21_256_is_greater(upper, *res) &&
             s21_256_is_greater(upper, remainder) && exp < 28) {
        s21_256_mult_10(&remainder, 1);
        s21_256_mult_10(res, 1);
        exp++;
      }

      s21_256 remBuffer = remainder;
      remainder = zero;

      for (int i = 255; i >= 0; i--) {
        s21_256_left_shift(&remainder);
        if (remBuffer.value[i] == 1) {
          remainder.value[0] = 1;
        }

        if (s21_256_is_greater(remainder, v2) ||
            s21_256_is_equal(remainder, v2)) {
          s21_256 divBuffer = zero;
          s21_256_sub(remainder, v2, &divBuffer);
          remainder = divBuffer;
          rem->value[i] = 1;
        }
      }
    }
    res->exp = exp;
    rem->exp = exp;
    res->sign = sign;
    rem->sign = sign;
  }
  return status;
}