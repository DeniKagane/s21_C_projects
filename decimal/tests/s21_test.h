#ifndef _DECIMAL_TEST_
#define _DECIMAL_TEST_

#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../s21_decimal.h"

#define S21_TRUE 1
#define S21_FALSE 0
#define CONVERTERS_S21_TRUE 0
#define CONVERTERS_S21_FALSE 1
#define S21_MAX_UINT 4294967295       // 0b11111111111111111111111111111111
#define MAX_INT 2147483647            // 0b01111111111111111111111111111111
#define EXPONENT_MINUS_1 2147549184   // 0b10000000000000010000000000000000
#define EXPONENT_PLUS_1 65536         // 0b00000000000000010000000000000000
#define EXPONENT_PLUS_2 196608        // 0b00000000000000110000000000000000
#define EXPONENT_MINUS_28 2149318656  // 0b10000000000111000000000000000000
#define EXPONENT_PLUS_28 1835008      // 0b00000000000111000000000000000000
#define MINUS 2147483648              // 0b10000000000000000000000000000000
#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

Suite* suite_is_equal();
Suite* suite_is_less();
Suite* suite_is_greater();
Suite* suite_is_not_equal();
Suite* suite_is_less_or_equal();
Suite* suite_is_greater_or_equal();

Suite* suite_from_int_to_decimal();
Suite* suite_from_float_to_decimal();
Suite* suite_from_decimal_to_float();
Suite* suite_from_decimal_to_int();

Suite* suite_add();
Suite* suite_sub();
Suite* suite_mul();
Suite* suite_div();

Suite* suite_truncate();
Suite* suite_round();
Suite* suite_negate();
Suite* suite_floor();

#endif