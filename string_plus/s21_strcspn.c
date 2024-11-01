#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  const char *tmp = str1;
  size_t i = 0;
  size_t chrnum = s21_strlen(str1);
  while (*str2 != '\0') {
    while (*str1 != '\0') {
      if (*str1 != *str2) {
        str1++;
        i++;
      } else
        break;
    }
    str2++;
    if (i <= chrnum) {
      chrnum = i;
    }
    i = 0;
    str1 = tmp;
  }
  return chrnum;
}
