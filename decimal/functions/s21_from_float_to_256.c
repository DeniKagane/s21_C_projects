#include "../s21_decimal.h"

int s21_from_float_to_256(float src, s21_256 *dst) {
  s21_256 zero = {0, 0, {0}};
  int status = 0;

  if (fabs(src) < 1E-28 || isnan(src)) {
    *dst = zero;
    status = 2;
  } else if (fabsf(src) > MAX_FLOAT || isinf(src)) {
    status = 1;
  }

  if (src == 0.0) {
    status = 0;
  } else if (dst != NULL && status == 0) {
    *dst = zero;
    int sign = 0;

    if (src < 0) {
      sign = 1;
      src = -(src);
    }

    char str[128] = {0};
    sprintf(str, "%.28E", src);
    s21_parser_string(str, dst);
    dst->sign = sign;
  }
  return status;
}

int s21_parser_string(const char *str, s21_256 *dst) {
  int error = 0;
  int int_index = 0;

  char str_exp[16] = {'\0'};
  char str_num[128] = {'\0'};

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'E') {
      i++;
      for (int j = 0; str[i] != '\0'; j++) {
        str_exp[j] = str[i];
        i++;
      }
    } else if (str[i] != '.') {
      str_num[int_index++] = str[i];
    }
  }

  int exp = atoi(str_exp);

  s21_normalise(str_num, &exp);

  s21_256 buff;
  int i = strlen(str_num) - 1;
  int power = 0;

  for (; i >= 0; i--) {
    int num = str_num[i] - 48;
    s21_from_int_to_256(num, &buff);
    s21_256_mult_10(&buff, power);
    s21_256_add(buff, *dst, dst);
    power++;
  }
  dst->exp = exp;

  return error;
}

void s21_normalise(char *str_num, int *exp) {
  char *tmp;
  if (*exp < 0) {
    tmp = str_num + (strlen(str_num) + *exp);
    while (*tmp) {
      *tmp = '\0';
      tmp++;
    }
    *exp = 28;
  } else {
    int diff = *exp;
    *exp = 28 - diff;
  }

  tmp = str_num + strlen(str_num) - 1;
  while (*tmp == '0' && *exp > 0) {
    *tmp = '\0';
    tmp--;
    *exp -= 1;
  }
}
