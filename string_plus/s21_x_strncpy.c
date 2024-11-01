#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  while (*src != '\0' && n != 0) {
    *tmp = *src;
    tmp++;
    src++;
    n--;
  }
  while (*tmp != '\0' && *src == '\0' && n != 0) {
    *tmp = '\0';
    tmp++;
    n--;
  }
  return dest;
}