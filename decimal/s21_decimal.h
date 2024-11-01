#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  int sign;
  int exp;
  unsigned int value[256];
} s21_256;

#define MAX_FLOAT 79228162514264337593543950335.0f

// Преобразователи
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Арифметические операторы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Сравненительные операторы
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);

// Другие функции
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

// Вспомогательные функции
int s21_get_sign(s21_decimal value);
int s21_get_exp(s21_decimal value);
int s21_set_exp(s21_decimal *value, int exp);
void s21_set_sign(s21_decimal *value, int sign);
int s21_set_zero_decimal(s21_decimal *value);
int s21_get_bit(s21_decimal value, int n, int byteNum);
int s21_getBit(s21_decimal num, int curBit);
int s21_set_bit(s21_decimal *value, int n, int byteNum);
int s21_left_shift(s21_decimal *value);
int s21_copy_decimal(s21_decimal src, s21_decimal *dest);
int s21_copy_to_buffer_no_exp(s21_decimal src, s21_decimal *dest);
int s21_apply_lshift(s21_decimal *value, int n);
int s21_decimal_pow(s21_decimal *value, int n);
int s21_invert_decimal(s21_decimal *value);
int s21_zero_decimal(s21_decimal a, s21_decimal b);
int s21_check_decimal(s21_decimal *v);

// Утилиты для s21_256
int s21_256_mul(s21_256 v1, s21_256 v2, s21_256 *res);
int s21_256_add(s21_256 v1, s21_256 v2, s21_256 *result);
int s21_256_sub(s21_256 v1, s21_256 v2, s21_256 *result);
int s21_256_div(s21_256 v1, s21_256 v2, s21_256 *result);
int s21_256_mod(s21_256 v1, s21_256 v2, s21_256 *result);

int s21_256_is_greater(s21_256 v1, s21_256 v2);
int s21_256_is_equal(s21_256 v1, s21_256 v2);

int s21_from_256_to_decimal(s21_256 src, s21_decimal *dst);
int s21_from_decimal_to_256(s21_decimal src, s21_256 *dst);
int s21_from_int_to_256(int src, s21_256 *dst);
int s21_from_float_to_256(float src, s21_256 *dst);
int s21_from_256_to_float(s21_256 src, float *dst);

int s21_256_validate(s21_256 v);
int s21_256_is_value_zero(s21_256 *v);
int s21_256_check_max_value(s21_256 v);
int s21_256_left_shift(s21_256 *v);
int s21_256_bit_summ(int bit1, int bit2, int *remainder);
int s21_256_mult_10(s21_256 *v, int n);
int s21_256_leveling(s21_256 v1, s21_256 v2, s21_256 *v1l, s21_256 *v2l);
int s21_parser_string(const char *str, s21_256 *dst);
void s21_normalise(char *str_num, int *exp);
int s21_256_inversion(s21_256 *v);
int divide_256(s21_256 v1, s21_256 v2, s21_256 *res, s21_256 *rem);
s21_256 s21_256_max();
s21_256 s21_256_min();

// Для отладки
void prn_decimal(s21_decimal v);
void prn_256(s21_256 v);

#endif  // S21_DECIMAL_H
