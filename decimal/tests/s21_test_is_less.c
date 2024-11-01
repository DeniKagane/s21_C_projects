#include <stdio.h>

#include "../s21_decimal.h"
#include "s21_test.h"

START_TEST(t1) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t2) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t3) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t4) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t5) {
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t6) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t7) {
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t8) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t9) {
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t10) {
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t11) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t12) {
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t13) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t14) {
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t15) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t16) {
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t17) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t18) {
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t19) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t20) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t21) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t22) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t23) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t24) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t25) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t26) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t27) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t28) {
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t29) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t30) {
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t31) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t32) {
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t33) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t34) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t35) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t36) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t37) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t38) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t39) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t40) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t41) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

START_TEST(t42) {
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 1);
}

START_TEST(t43) {
  s21_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int res = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(res, 0);
}

Suite *suite_is_less() {
  Suite *suite = suite_create("decimal is less");
  TCase *tcase_core = tcase_create("is_less_tc");
  tcase_add_test(tcase_core, t1);
  tcase_add_test(tcase_core, t2);
  tcase_add_test(tcase_core, t3);
  tcase_add_test(tcase_core, t4);
  tcase_add_test(tcase_core, t5);
  tcase_add_test(tcase_core, t6);
  tcase_add_test(tcase_core, t7);
  tcase_add_test(tcase_core, t8);
  tcase_add_test(tcase_core, t9);
  tcase_add_test(tcase_core, t10);
  tcase_add_test(tcase_core, t11);
  tcase_add_test(tcase_core, t12);
  tcase_add_test(tcase_core, t13);
  tcase_add_test(tcase_core, t14);
  tcase_add_test(tcase_core, t15);
  tcase_add_test(tcase_core, t16);
  tcase_add_test(tcase_core, t17);
  tcase_add_test(tcase_core, t18);
  tcase_add_test(tcase_core, t19);
  tcase_add_test(tcase_core, t20);
  tcase_add_test(tcase_core, t21);
  tcase_add_test(tcase_core, t22);
  tcase_add_test(tcase_core, t23);
  tcase_add_test(tcase_core, t24);
  tcase_add_test(tcase_core, t25);
  tcase_add_test(tcase_core, t26);
  tcase_add_test(tcase_core, t27);
  tcase_add_test(tcase_core, t28);
  tcase_add_test(tcase_core, t29);
  tcase_add_test(tcase_core, t30);
  tcase_add_test(tcase_core, t31);
  tcase_add_test(tcase_core, t32);
  tcase_add_test(tcase_core, t33);
  tcase_add_test(tcase_core, t34);
  tcase_add_test(tcase_core, t35);
  tcase_add_test(tcase_core, t36);
  tcase_add_test(tcase_core, t37);
  tcase_add_test(tcase_core, t38);
  tcase_add_test(tcase_core, t39);
  tcase_add_test(tcase_core, t40);
  tcase_add_test(tcase_core, t41);
  tcase_add_test(tcase_core, t42);
  tcase_add_test(tcase_core, t43);

  suite_add_tcase(suite, tcase_core);
  return suite;
}