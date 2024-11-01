#include <stdio.h>

#include "../s21_decimal.h"
#include "s21_test.h"

START_TEST(t1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(t2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(t3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(t4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t7) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = 189940600;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t8) {
  float num1 = 3228162514264337593543950335.0;
  float num2 = 3.0;
  float res_origin = num1 * num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t9) {
  float num1 = 4228162514264337593543950335.0;
  float num2 = 2.0;
  float res_origin = num1 * num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t10) {
  float num1 = 2228162514264337593543950335.0;
  float num2 = 1.5;
  float res_origin = num1 * num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t11) {
  s21_decimal num1 = {{2, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(t12) {
  s21_decimal num1 = {{24, 0, 0, 0}};
  s21_decimal num2 = {{6, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 144);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(t13) {
  s21_decimal num1 = {{500, 0, 0, (unsigned int)-2147483648}};
  s21_decimal num2 = {{3, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1500);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(t14) {
  s21_decimal num1 = {{2, 0, 0, 0}};
  s21_decimal num2 = {{5, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 10);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(t15) {
  s21_decimal num1 = {{3, 0, 0, 0}};
  s21_decimal num2 = {{256, 0, 0, 262144}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 768);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 262144);
}
END_TEST

START_TEST(t16) {
  s21_decimal num1 = {{9213658, 0, 0, 393216}};
  s21_decimal num2 = {{169312846, 0, 0, (unsigned int)-2147090432}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-1593398676);
  ck_assert_int_eq(res.bits[1], 363213);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2146697216);
}
END_TEST

START_TEST(t17) {
  s21_decimal num1 = {{321, 0, 0, 131072}};
  s21_decimal num2 = {{30336, 0, 0, 196608}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 9737856);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 327680);
}
END_TEST

START_TEST(t18) {
  s21_decimal num1 = {{32, 0, 0, (unsigned int)-2147418112}};
  s21_decimal num2 = {{3, 0, 0, (unsigned int)-2147418112}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 96);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 131072);
}
END_TEST

START_TEST(t19) {
  s21_decimal num1 = {{32, 0, 0, (unsigned int)-2147418112}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(t20) {
  s21_decimal num1 = {{0, 0, 1, 0}};
  s21_decimal num2 = {{256, 0, 0, 917504}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 256);
  ck_assert_int_eq(res.bits[3], 917504);
}
END_TEST

START_TEST(t21) {
  s21_decimal num1 = {{0, 0, 5, 0}};
  s21_decimal num2 = {{(unsigned int)-1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(t22) {
  s21_decimal num1 = {{0, 0, 1, (unsigned int)-2147483648}};
  s21_decimal num2 = {{0, -1, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(t23) {
  s21_decimal num1 = {{200, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 1703936}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 400);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0b00011010 << 16);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_mul");
  tc = tcase_create("case_mul");

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
  tcase_add_test(tc, t21);
  tcase_add_test(tc, t22);
  tcase_add_test(tc, t23);

  suite_add_tcase(s, tc);

  return s;
}
