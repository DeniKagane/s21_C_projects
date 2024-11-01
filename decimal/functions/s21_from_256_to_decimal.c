#include "../s21_decimal.h"

int s21_from_256_to_decimal(s21_256 src, s21_decimal *dst) {
  s21_256 ten = {0, 0, {0}};
  s21_from_int_to_256(10, &ten);

  s21_set_zero_decimal(dst);

  int check = s21_256_check_max_value(src);

  while ((check == 0) && (src.exp > 0)) {
    s21_256_div(src, ten, &src);
    check = s21_256_check_max_value(src);
    src.exp--;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      if (src.value[i * 32 + j]) s21_set_bit(dst, j, i);
    }
  }

  s21_set_sign(dst, src.sign);
  s21_set_exp(dst, src.exp);

  return 0;
}