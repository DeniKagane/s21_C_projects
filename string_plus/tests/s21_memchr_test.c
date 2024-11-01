#include "../s21_string.h"
#include "s21_test.h"

START_TEST(normal) {
  s21_size_t n = 6;
  char str[10] = "123456";
  int find = '5';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(not_find) {
  s21_size_t n = 6;
  char str[10] = "123456";
  int find = '7';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(first) {
  s21_size_t n = 6;
  char str[10] = "123456";
  int find = '1';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(last) {
  s21_size_t n = 6;
  char str[10] = "123456";
  int find = '6';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(n_1) {
  s21_size_t n = 1;
  char str[10] = "123456";
  int find = '1';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(not_enough) {
  s21_size_t n = 5;
  char str[10] = "123456";
  int find = '6';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(nothing) {
  s21_size_t n = 5;
  char str[10] = "";
  int find = '6';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

START_TEST(empty) {
  s21_size_t n = 0;
  char str[10] = "";
  int find = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find, n), memchr(str, find, n));
}
END_TEST

Suite *suite_memchr() {
  Suite *suite = suite_create("memchr check");
  TCase *tcase_core = tcase_create("memchr_tc");
  tcase_add_test(tcase_core, normal);
  tcase_add_test(tcase_core, not_find);
  tcase_add_test(tcase_core, first);
  tcase_add_test(tcase_core, last);
  tcase_add_test(tcase_core, n_1);
  tcase_add_test(tcase_core, not_enough);
  tcase_add_test(tcase_core, nothing);
  tcase_add_test(tcase_core, empty);

  suite_add_tcase(suite, tcase_core);
  return suite;
}