#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i;
  for (i = 0; i < n - 1 && str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      break;
    }
  }
  if (str1[i] == '\0' && str2[i] != '\0') {
    res = -str2[i];
  }
  if (str1[i] != '\0' && str2[i] == '\0') {
    res = str1[i];
  }
  return res;
}