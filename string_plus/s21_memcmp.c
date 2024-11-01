#include "s21_string.h"

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  const unsigned char *str1 = s1, *str2 = s2;
  int res = 0;
  for (size_t i = 0; i < n; i++) {
    res = *str1 - *str2;
    if (*str1 != *str2) break;
    str1++;
    str2++;
  }
  return res;
}