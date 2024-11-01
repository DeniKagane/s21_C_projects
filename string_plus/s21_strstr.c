#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *p = S21_NULL;
  s21_size_t n = s21_strlen(needle);
  if (*needle == 0) {
    p = (char *)haystack;
  }
  while ((*haystack) && (*needle)) {
    if (s21_memcmp(haystack, needle, n) != 0) {
      haystack++;
    } else {
      p = (char *)haystack;
      break;
    }
  }
  return p;
}
