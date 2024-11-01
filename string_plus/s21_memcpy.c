#include "s21_string.h"

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  unsigned char* d = (unsigned char*)dest;
  const unsigned char* s = (const unsigned char*)src;

  for (s21_size_t index = 0; index < n; index++) {
    d[index] = s[index];
  }

  return dest;
}