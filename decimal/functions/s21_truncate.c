#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int status = 0;
  s21_256 res = {0, 0, {0}};
  char str[256] = {'\0'};
  float val;
  int sign = s21_get_sign(value);

  s21_set_sign(&value, 0);

  if (!result) {
    status = 1;
  } else {
    s21_from_decimal_to_float(value, &val);
    sprintf(str, "%f", val);
    char *str_tmp = str;

    while (*str_tmp != '.' && *str_tmp != '\0') {
      str_tmp++;
    }

    *str_tmp = '\0';

    s21_256 buff = {0, 0, {0}};
    int l = strlen(str) - 1;

    for (int i = 0; i <= l; i++) {
      int num = str[i] - 48;
      s21_from_int_to_256(num, &buff);
      s21_256_mult_10(&buff, l - i);
      s21_256_add(buff, res, &res);
    }
    res.sign = sign;
  }

  s21_from_256_to_decimal(res, result);

  return status;
}