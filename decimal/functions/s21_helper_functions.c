#include "../s21_decimal.h"

int s21_get_sign(s21_decimal value) {
  return (value.bits[3] & 0x80000000) >> 31;
}

int s21_get_exp(s21_decimal value) {
  return (value.bits[3] & 0x00FF0000) >> 16;
}

int s21_set_exp(s21_decimal *value, int exp) {
  int res = 1;
  if (value != NULL && exp >= 0 && exp < 29) {
    int sign = s21_get_sign(*value);
    value->bits[3] = exp << 16;
    s21_set_sign(value, sign);
  } else
    res = 0;
  return res;
}

void s21_set_sign(s21_decimal *val, int sign) {
  if (sign == 1) {
    val->bits[3] = val->bits[3] | (~INT_MAX);
  } else {
    val->bits[3] = val->bits[3] & INT_MAX;
  }
}

int s21_set_zero_decimal(s21_decimal *value) {
  int res = 0;
  if (value) {
    for (int i = 0; i <= 3; i++) {
      value->bits[i] = 0;
    }
  } else
    res = 1;

  return res;
}

int s21_get_bit(s21_decimal value, int n, int byteNum) {
  int res = (value.bits[byteNum] >> n) & 1;

  return res;
}

int s21_set_bit(s21_decimal *value, int n, int byteNum) {
  value->bits[byteNum] |= 1u << n;

  return 0;
}