#include "s21_sprintf.h"

char *parse_char(args arg, char *str, va_list var) {
  if (arg.length == 'l') {
    wchar_t w_ch = va_arg(var, wchar_t);
    str = format_wchar(arg, str, w_ch);
  } else {
    char ch = va_arg(var, int);
    str = format_char(arg, str, ch);
  }
  return str;
}

char *parse_int(args arg, char *str, va_list var) {
  long int num = 0;
  switch (arg.length) {
    case 'h':
      num = (short)va_arg(var, int);
      break;
    case 'l':
      num = va_arg(var, long);
      break;
    case 0:
      num = va_arg(var, int);
  }
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 10);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  return str_plus_str(str, str_num);
}

char *parse_float(args arg, char *str, va_list var) {
  long double num = 0;
  if (!arg.has_precision) arg.precision = 6;
  if (arg.length == 'L') {
    num = va_arg(var, long double);
  } else {
    num = va_arg(var, double);
  }
  char str_num[SIZE] = {'\0'};
  if (arg.specifier == 'f') {
    double_to_string(num, str_num, arg);
  } else if (arg.specifier == 'e' || arg.specifier == 'E') {
    double_to_sc_notation(num, str_num, arg);
  } else {
    double_to_gG_format(arg, num, str_num);
  }
  format_flags(str_num, arg);
  return str_plus_str(str, str_num);
}

char *parse_string(args arg, char *str, va_list var) {
  char tmp_str[SIZE] = {'\0'};
  if (arg.length == 'l') {
    wchar_t *wstr = va_arg(var, wchar_t *);
    format_wstring(arg, tmp_str, wstr);
  } else {
    char *sstr = va_arg(var, char *);
    format_string(arg, tmp_str, sstr);
  }
  str = str_plus_str(str, tmp_str);
  return str;
}

char *parse_unsigned(args arg, char *str, va_list var) {
  uint64_t num = va_arg(var, uint64_t);
  switch (arg.length) {
    case 'h':
      num = (uint16_t)num;
      break;
    case 'l':
      num = (uint64_t)num;
      break;
    case 0:
      num = (uint32_t)num;
      break;
  }
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 10);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

char *parse_octal(args arg, char *str, va_list var) {
  char str_num[SIZE] = {'\0'};
  unsigned int num = va_arg(var, unsigned int);
  num_to_str(num, str_num, 8);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

char *parse_hex(args arg, char *str, va_list var) {
  uint64_t num = va_arg(var, uint64_t);
  switch (arg.length) {
    case 0:
      num = (uint32_t)num;
      break;
    case 'h':
      num = (uint16_t)num;
      break;
    case 'l':
      num = (uint64_t)num;
      break;
  }
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 16);
  if (arg.specifier == 'X') to_upper(str_num);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

char *parse_pointer(args arg, char *str, va_list var) {
  uint64_t num = va_arg(var, uint64_t);
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 16);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}