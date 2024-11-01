#include "s21_sprintf.h"

bool is_flag(const char ch) {
  bool res = 0;
  switch (ch) {
    case '-':
    case '+':
    case ' ':
    case '#':
    case '0':
      res = 1;
      break;
  }
  return res;
}

bool is_digit(const char ch) { return ch >= '0' && ch <= '9'; };

int char_to_int(const char ch) { return is_digit(ch) ? ch - 48 : -1; }

bool is_spec(const char ch) {
  bool res = 0;
  switch (ch) {
    case 'c':
    case 'd':
    case 'i':
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
    case 'o':
    case 's':
    case 'u':
    case 'x':
    case 'X':
    case 'p':
    case 'n':
    case '%':
      res = 1;
      break;
  }
  return res;
}

void num_to_str(int64_t num, char *str_num, int base) {
  char tmp[SIZE] = {'\0'};
  int idx = SIZE - 2;
  bool sign = num < 0;
  num = sign ? -num : num;

  if (num == 0) {
    tmp[idx] = '0';
    idx--;
  }

  while (num > 0) {
    tmp[idx] = "0123456789abcdef"[num % base];
    num /= base;
    idx--;
  }

  int j = 0;
  if (sign) {
    str_num[j++] = '-';
  }

  for (int i = idx + 1; tmp[i]; i++, j++) {
    str_num[j] = tmp[i];
  }
}

void double_to_string(long double num, char *str_num, args arg) {
  char buff[SIZE] = {'\0'};
  int idx = SIZE - 2;
  bool sign = num < 0 ? 1 : 0;
  num = sign ? num * -1 : num;
  long double div = 0;
  long double mod = modfl(num, &div);

  if (arg.precision == 0) {
    div = roundl(num);
    mod = 0;
  }

  char fractions[SIZE] = {'\0'};
  for (int i = 0; i < arg.precision; i++) {
    mod *= 10;
    fractions[i] = (int)mod + '0';
  }

  long long right = roundl(mod);
  long long left = div;

  if (!right) {
    for (int i = 0; i < arg.precision; idx--, i++) {
      buff[idx] = '0';
    }
  } else {
    for (int i = s21_strlen(fractions); right || i > 0;
         right /= 10, idx--, i--) {
      buff[idx] = (int)(right % 10 + 0.05) + '0';
    }
  }

  if ((arg.has_precision && arg.precision != 0) ||
      (!arg.has_precision && num == 0) || s21_strlen(fractions)) {
    buff[idx--] = '.';
  }

  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) {
      buff[idx] = (int)(left % 10) + '0';
    }
  }

  int i = 0;
  if (sign) {
    str_num[i++] = '-';
  }

  for (int j = idx + 1; buff[j]; j++, i++) {
    str_num[i] = buff[j];
  }
}

void normalize_double(long double *num, int *exp, char *exp_sign) {
  if ((*num) != 0.) {
    if (fabsl(*num) < 1) {
      while ((int)(*num) == 0) {
        (*exp)++;
        (*num) *= 10;
      }
    } else {
      (*exp_sign) = '+';
      while ((int)(*num) / 10 != 0) {
        (*exp)++;
        (*num) /= 10;
      }
    }
  }
}

void norm_double_to_sc_not(char *str_num, int exp, char exp_sign, args arg) {
  int len = s21_strlen(str_num);
  if (arg.specifier == 'g')
    arg.specifier = 'e';
  else if (arg.specifier == 'G')
    arg.specifier = 'E';
  str_num[len] = arg.specifier;
  str_num[len + 1] = exp_sign;
  str_num[len + 3] = exp % 10 + '0';
  exp /= 10;
  str_num[len + 2] = exp % 10 + '0';
  str_num[len + 4] = '\0';
}

void remove_zeros(char *str_num) {
  size_t len = s21_strlen(str_num);
  if (s21_memchr(str_num, '.', len)) {
    for (int i = len - 1; i > 0; i--) {
      if (str_num[i] == '0')
        str_num[i] = '\0';
      else
        break;
    }
  }
}

void remove_point(char *str_num) {
  size_t len = s21_strlen(str_num);
  for (int i = len - 1; i > 0; i--) {
    if (str_num[i] == '.')
      str_num[i] = '\0';
    else
      break;
  }
}

void remove_exp(char *str_num, int exp) {
  if (exp == 0) {
    size_t len = s21_strlen(str_num);
    str_num[len - 4] = '\0';
  }
}

void remove_end(char *str_num) {
  remove_zeros(str_num);
  remove_point(str_num);
}

int double_to_sc_notation(long double num, char *str_num, args arg) {
  char exp_sign = (fabsl(num) >= 1 || num == 0.0) ? '+' : '-';
  int exp = 0;
  normalize_double(&num, &exp, &exp_sign);
  double_to_string(num, str_num, arg);
  if ((arg.specifier == 'g' || arg.specifier == 'G') && !arg.fl.hash)
    remove_end(str_num);
  norm_double_to_sc_not(str_num, exp, exp_sign, arg);
  return exp;
}

void double_to_gG_format(args arg, long double num, char *str_num) {
  if (arg.precision == 1) arg.precision = 0;
  // обычное дробое число
  if (num < 0.) arg.precision++;
  double_to_string(num, str_num, arg);
  set_gG_size(str_num, arg.precision);
  if (!arg.fl.hash) remove_end(str_num);
  // научная нотация
  char str_num1[SIZE] = {'\0'};
  int exp = double_to_sc_notation(num, str_num1, arg);
  remove_exp(str_num1, exp);
  // сравнение
  size_t len = s21_strlen(str_num);
  size_t len1 = s21_strlen(str_num1);
  if (len1 < len || arg.precision < 2) s21_strcpy(str_num, str_num1);
}

void *to_upper(char *str) {
  for (int i = 0; str[i]; i++)
    str[i] = (str[i] >= 97 && str[i] <= 122) ? str[i] - 32 : str[i];
  return str;
}

char *str_plus_str(char *str, char *str_num) {
  for (int i = 0; str_num[i]; i++) {
    *str++ = str_num[i];
  }
  return str;
}
