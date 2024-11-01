#include "s21_sprintf.h"

char *format_wchar(args arg, char *str, wchar_t w_char) {
  int width = arg.width;
  if (!arg.fl.minus && width) {
    for (int i = 1; i < width; i++) {
      *str++ = ' ';
      if (i == width - 1) wcstombs(str++, &w_char, SIZE);
    }
  } else if (width) {
    wcstombs(str++, &w_char, SIZE);
    ;
    for (int i = 1; i < width; i++) *str++ = ' ';
  } else {
    wcstombs(str++, &w_char, SIZE);
  }
  return str;
}

char *format_char(args arg, char *str, char ch) {
  int width = arg.width;
  if (!arg.fl.minus && width) {
    for (int i = 1; i < width; i++) {
      *str++ = ' ';
      if (i == width - 1) *str++ = ch;
    }
  } else if (width) {
    str[0] = ch;
    str++;
    for (int i = 1; i < width; i++) *str++ = ' ';
  } else {
    str[0] = ch;
    str++;
  }
  return str;
}

void format_precision(char *str_num, args arg) {
  char tmp[SIZE] = {'\0'};
  int sign = 0;
  int len = s21_strlen(str_num);
  if (str_num[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }
  if (arg.precision > len) {
    int i;
    for (i = sign; i < arg.precision - len + sign; i++) {
      tmp[i] = '0';
    }
    int j;
    for (j = sign; str_num[j]; j++, i++) {
      tmp[i] = str_num[j];
    }
    tmp[i] = '\0';  // Add null terminator to the end of the string
    s21_strcpy(str_num, tmp);
  }
  if (arg.precision == 0 && str_num[0] == '0') {
    str_num[0] = '\0';
  }
}

void format_flags(char *str_num, args arg) {
  char tmp[SIZE] = {'\0'};

  if (arg.fl.hash || arg.specifier == 'p') {
    if ((arg.specifier == 'o' && s21_strlen(str_num) < arg.precision &&
         arg.has_precision) ||
        (arg.specifier == 'o' && !arg.has_precision)) {
      tmp[0] = '0';
      s21_strcpy(tmp + 1, str_num);
      s21_strcpy(str_num, tmp);
    }

    if (arg.specifier == 'x' || arg.specifier == 'X' || arg.specifier == 'p') {
      tmp[0] = '0';
      tmp[1] = arg.specifier == 'p' ? 'x' : arg.specifier;
      s21_strcpy(tmp + 2, str_num);
      s21_strcpy(str_num, tmp);
    }
  }

  size_t len = s21_strlen(str_num);
  size_t width = arg.width;

  if (width > len) {
    int delta = width - len;
    if (!arg.fl.minus) {
      s21_memset(tmp, arg.fl.zero ? '0' : ' ', delta);
      s21_strcpy(tmp + delta, str_num);
    } else {
      s21_strcpy(tmp, str_num);
      s21_memset(tmp + len, ' ', delta);
    }
    s21_strcpy(str_num, tmp);
  }

  bool sign = str_num[0] == '-';

  if (arg.fl.plus) {
    tmp[0] = sign ? '-' : '+';
    s21_strcpy(tmp + 1, sign ? str_num + 1 : str_num);
    s21_strcpy(str_num, tmp);
  } else if (arg.fl.space && !sign) {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, str_num);
    s21_strcpy(str_num, tmp);
  }
}

void format_string(args arg, char *str, char *sstr) {
  char tmp[SIZE] = {'\0'};
  s21_strcpy(tmp, sstr);
  if (arg.has_precision) tmp[arg.precision] = '\0';
  int len = s21_strlen(tmp);
  int delta = arg.width - len;

  if (arg.fl.minus && delta > 0) {
    s21_strcpy(str, tmp);
    s21_memset(str + len, ' ', delta);
  } else if (delta > 0) {
    s21_memset(str, ' ', delta);
    s21_strcpy(str + delta, tmp);
  } else {
    s21_strcpy(str, tmp);
  }
}

void format_wstring(args arg, char *str, wchar_t *wstr) {
  char tmp[SIZE] = {'\0'};
  wcstombs(tmp, wstr, SIZE);
  if (arg.has_precision) tmp[arg.precision] = '\0';
  int len = s21_strlen(tmp);
  int delta = arg.width - len;
  if (arg.fl.minus && delta > 0) {
    s21_strcpy(str, tmp);
    s21_memset(str + len, ' ', delta);
  } else if (delta > 0) {
    s21_memset(str, ' ', delta);
    s21_strcpy(str + delta, tmp);
  } else {
    s21_strcpy(str, tmp);
  }
}