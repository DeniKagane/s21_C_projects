#include <stdio.h>

#include "../s21_decimal.h"
#include "s21_test.h"

START_TEST(t1) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 5);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(t2) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 393216}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 10000000);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(t3) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{658067456, 1164, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 786432);
}
END_TEST

START_TEST(t4) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {
      {1879048192, (unsigned int)-1291644761, (unsigned int)-500259693, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(t5) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{3, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1431655765);
  ck_assert_int_eq(res.bits[1], 1431655765);
  ck_assert_int_eq(res.bits[2], 1431655765);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(t6) {
  s21_decimal num1 = {{1, 1, 1, 1835008}};
  s21_decimal num2 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 3);
}
END_TEST

START_TEST(t7) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{1, 0, 0, 393216}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(t8) {
  s21_decimal num1 = {{1, 0, 0, 1835008}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(t9) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result_our = {{0, 0, 0, 0}};

  src1.bits[0] = 0b11111111111111111111111111111110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int val = s21_div(src1, src2, &result_our);
  ck_assert_int_eq(val, 1);
}
END_TEST

Suite* suite_div(void) {
  Suite* s;
  TCase* tcase;
  s = suite_create("s21_div");
  tcase = tcase_create("case_div");

  tcase_add_test(tcase, t1);
  tcase_add_test(tcase, t2);
  tcase_add_test(tcase, t3);
  tcase_add_test(tcase, t4);
  tcase_add_test(tcase, t5);
  tcase_add_test(tcase, t6);
  tcase_add_test(tcase, t7);
  tcase_add_test(tcase, t8);
  tcase_add_test(tcase, t9);
  suite_add_tcase(s, tcase);

  return s;
}