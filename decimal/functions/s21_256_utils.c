#include "../s21_decimal.h"

int s21_256_inversion(s21_256 *v) {
  for (int i = 0; i < 256; i++) {
    if (v->value[i] == 0) {
      v->value[i] = 1;
    } else {
      v->value[i] = 0;
    }
  }
  return 0;
}

int s21_256_is_value_zero(s21_256 *v) {
  int res = 1;
  for (int i = 0; i < 256; i++) {
    if (v->value[i] != 0) {
      res = 0;
      break;
    }
  }
  if (res) {
    v->exp = 0;
    v->sign = 0;
  }
  return res;
}

int s21_256_check_max_value(s21_256 v) {
  int res = 1;
  for (int i = 255; i > 95; i--) {
    if (v.value[i] != 0) {
      res = 0;
      break;
    }
  }
  return res;
}

s21_256 s21_256_max() {
  s21_256 res = {0, 0, {0}};
  for (int i = 0; i < 96; i++) {
    res.value[i] = 1;
  }
  return res;
}

s21_256 s21_256_min() {
  s21_256 res = {0, 0, {0}};
  res.exp = 28;
  res.value[0] = 1;
  return res;
}

int s21_256_validate(s21_256 v) {
  int status = 0;
  float tmp;
  v.sign = 0;

  if (!s21_256_is_value_zero(&v)) {
    s21_from_256_to_float(v, &tmp);

    if (s21_256_is_greater(v, s21_256_max()) || isinf(tmp)) {
      status = 1;
    } else if (s21_256_is_greater(s21_256_min(), v) || isnan(tmp)) {
      status = 2;
    }
  }
  return status;
}

int s21_256_is_equal(s21_256 v1, s21_256 v2) {
  int res = 1;
  if (!s21_256_is_value_zero(&v1) || !s21_256_is_value_zero(&v2)) {
    if (v1.sign == v2.sign) {
      if (v1.exp != v2.exp) {
        s21_256_leveling(v1, v2, &v1, &v2);
      }

      for (int i = 0; i < 256; i++) {
        if (v1.value[i] != v2.value[i]) {
          res = 0;
          break;
        }
      }
    } else {
      res = 0;
    }
  }
  return res;
}

int s21_256_is_greater(s21_256 v1, s21_256 v2) {
  int res = 1;

  if (s21_256_is_equal(v1, v2)) {
    res = 0;
  } else {
    int i = 255;
    s21_256_leveling(v1, v2, &v1, &v2);
    for (; i >= 0; i--) {
      if (v1.value[i] != v2.value[i]) {
        break;
      }
    }
    if ((v1.sign == 1) && (v2.sign == 0)) {
      res = 0;
    } else if ((v1.sign == 1) && (v2.sign == 1)) {
      if ((v1.value[i] == 1) && (v2.value[i] == 0)) {
        res = 0;
      }
    } else if ((v1.sign == 0) && (v2.sign == 0)) {
      if ((v1.value[i] == 0) && (v2.value[i] == 1)) {
        res = 0;
      }
    }
  }
  return res;
}

int s21_256_left_shift(s21_256 *v) {
  for (int i = 254; i >= 0; i--) {
    v->value[i + 1] = v->value[i];
  }
  v->value[0] = 0;
  return v->value[255];
}

int s21_256_leveling(s21_256 v1, s21_256 v2, s21_256 *v1l, s21_256 *v2l) {
  s21_256 zero = {0, 0, {0}};
  s21_256 tens = zero;
  s21_from_int_to_256(10, &tens);
  int exp;

  *v1l = zero;
  *v2l = zero;

  if (v1.exp == v2.exp) {
    exp = v1.exp;
  } else if (v1.exp < v2.exp) {
    s21_256_mult_10(&v1, v2.exp - v1.exp);
    v1.exp = v2.exp;
    exp = v2.exp;
  } else {
    s21_256_mult_10(&v2, v1.exp - v2.exp);
    v2.exp = v1.exp;
    exp = v1.exp;
  }

  *v1l = v1;
  *v2l = v2;

  return exp;
}

int s21_256_mult_10(s21_256 *v, int n) {
  s21_256 ten;
  s21_from_int_to_256(10.0f, &ten);

  for (int i = 0; i < n; i++) {
    s21_256_mul(*v, ten, v);
  }

  return 0;
}

int s21_256_bit_summ(int bit1, int bit2, int *remainder) {
  int result = bit1 + bit2 + (*remainder);

  if (result == 0 || result == 1) {
    *remainder = 0;
  } else if (result == 2) {
    *remainder = 1;
    result = 0;
  } else if (result == 3) {
    *remainder = 1;
    result = 1;
  }

  return result;
}
