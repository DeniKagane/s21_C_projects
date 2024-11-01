#include <stdio.h>

#include "../s21_decimal.h"
#include "s21_test.h"

START_TEST(t1) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_float_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(t2) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(t3) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(t4) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);
}
END_TEST

int check, result, code;

START_TEST(t5) {
  s21_decimal a = {{100, 0, 0, 0}};
  check = 100;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(t6) {
  s21_decimal a = {{INT_MAX, 0, 0, 0}};
  check = INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(t7) {
  s21_decimal a = {{INT_MAX, 0, 0, MINUS}};
  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(t8) {
  s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_MINUS_28}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(t9) {
  s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_28}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(t10) {
  s21_decimal a;
  a.bits[0] = 0b00000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = 1;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(t11) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(t12) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(t13) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(t14) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 4);
}
END_TEST

START_TEST(t15) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -4);
}
END_TEST

START_TEST(t16) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(t17) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000001111101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(t18) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000001111101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(t19) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000010011001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -12);
}
END_TEST

START_TEST(t20) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int result;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -3);
}
END_TEST

Suite *suite_from_decimal_to_int() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);
  tcase_add_test(tc, t8);
  tcase_add_test(tc, t9);
  tcase_add_test(tc, t10);
  tcase_add_test(tc, t11);
  tcase_add_test(tc, t12);
  tcase_add_test(tc, t13);
  tcase_add_test(tc, t14);
  tcase_add_test(tc, t15);
  tcase_add_test(tc, t16);
  tcase_add_test(tc, t17);
  tcase_add_test(tc, t18);
  tcase_add_test(tc, t19);
  tcase_add_test(tc, t20);

  suite_add_tcase(s, tc);
  return s;
}