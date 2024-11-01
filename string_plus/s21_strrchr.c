#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = (char *)str + s21_strlen(str);
  while (*res != c && res != str) {
    res--;
  }
  if (res == str && str[0] != c) {
    res = S21_NULL;
  }
  return res;
}