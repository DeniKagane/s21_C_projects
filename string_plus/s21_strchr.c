#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = (char *)str;
  while (*res != '\0') {
    if (*res == c) {
      break;
    }
    res++;
  }
  if (*res == '\0' && c != '\0') {
    res = S21_NULL;
  }
  return res;
}