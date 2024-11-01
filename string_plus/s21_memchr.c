#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *tmp = (unsigned char *)str;
  unsigned char *res = S21_NULL;
  while ((tmp != S21_NULL) && n != 0) {
    if (*tmp != (unsigned char)c) {
      tmp++;
      n--;
    } else {
      res = tmp;
      break;
    }
  }
  return res;
}
