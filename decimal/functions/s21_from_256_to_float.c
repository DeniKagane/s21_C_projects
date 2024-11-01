#include "../s21_decimal.h"

int s21_from_256_to_float(s21_256 src, float *dst) {
  int status = 0;

  if (dst == NULL) {
    status = 1;
  } else {
    *dst = 0;
    float tmp = 0;
    int sign;
    if (src.sign == 1) {
      sign = -1;
    } else {
      sign = 1;
    }

    for (int i = 0; i < 256; i++) {
      if (src.value[i] == 1) {
        tmp += (float)pow(2.0, i);
      }
    }
    tmp = tmp / ((float)pow(10, src.exp));
    tmp = tmp * sign;
    *dst = tmp;
  }
  return status;
}