#include "../s21_string.h"
#include "s21_test.h"

START_TEST(normal) {
  char res[10] = "1234567";
  char exp[10] = "1234567";
  char new = '8';
  s21_size_t n = 7;

  s21_memset(res, new, n);
  memset(exp, new, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(normal_5) {
  char res[10] = "1234567";
  char exp[10] = "1234567";
  char new = '8';
  s21_size_t n = 5;

  s21_memset(res, new, n);
  memset(exp, new, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(normal_1) {
  char res[10] = "1234567";
  char exp[10] = "1234567";
  char new = '8';
  s21_size_t n = 1;

  s21_memset(res, new, n);
  memset(exp, new, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(zero) {
  char res[10] = "1234567";
  char exp[10] = "1234567";
  char new = '8';
  s21_size_t n = 0;

  s21_memset(res, new, n);
  memset(exp, new, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(more) {
  char res[10] = "1234567";
  char exp[10] = "1234567";
  char new = '8';
  s21_size_t n = 9;

  s21_memset(res, new, n);
  memset(exp, new, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(is_in) {
  char res[10] = "1234567";
  char exp[10] = "1234567";
  char new = '2';
  s21_size_t n = 3;

  s21_memset(res, new, n);
  memset(exp, new, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

Suite *suite_memset() {
  Suite *suite = suite_create("memset check");
  TCase *tcase_core = tcase_create("memset_tc");

  tcase_add_test(tcase_core, normal);
  tcase_add_test(tcase_core, normal_5);
  tcase_add_test(tcase_core, normal_1);
  tcase_add_test(tcase_core, zero);
  tcase_add_test(tcase_core, more);
  tcase_add_test(tcase_core, is_in);

  suite_add_tcase(suite, tcase_core);
  return suite;
}