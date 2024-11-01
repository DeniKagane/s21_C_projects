#include "s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  while (*str1 != '\0') {
    for (const char* s = str2; *s != '\0'; s++) {
      if (*str1 == *s) return (char*)str1;
    }
    str1++;
  }
  return S21_NULL;
}