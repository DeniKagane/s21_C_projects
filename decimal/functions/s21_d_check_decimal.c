#include "../s21_decimal.h"

int s21_check_decimal(s21_decimal *v) {
  int res = 1;

  if (v) {
    for (int i = 0; i < 32; i++) {
      if (i < 16 || (i > 23 && i < 31)) {
        if (s21_get_bit(*v, i, 3) == 1) {
          res = 0;
          break;
        }
      } else {
        int exp = s21_get_exp(*v);
        if (exp < 0 || exp > 28) {
          res = 0;
          break;
        }
      }
    }
  } else
    res = 0;
  return res;
}