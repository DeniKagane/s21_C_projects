#include <stdio.h>

#include "../s21_decimal.h"
#include "s21_test.h"

START_TEST(t1) {
  int a = 15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(t2) {
  float a = 10.12345;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(t3) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(t4) {
  float a = -10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(10.1234e5, res_a);
}
END_TEST

START_TEST(t5) {
  int a = -15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(t6) {
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};
  int negate = s21_negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(t7) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t8) {
  s21_decimal a = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{1, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t9) {
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t10) {
  s21_decimal a = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{100, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t11) {
  s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, 0, 0, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t12) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(t13) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t14) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(t15) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(t16) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(t17) {
  s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(t18) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

Suite* suite_negate(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("s21_negate");
  tc = tcase_create("case_negate");
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
  suite_add_tcase(s, tc);
  return s;
}