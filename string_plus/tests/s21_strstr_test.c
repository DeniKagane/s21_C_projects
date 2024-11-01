#include "../s21_string.h"
#include "s21_test.h"

START_TEST(s21_strstr_test_1) {
  char str1_1[20] = "hello world";
  char *str2_1 = "w";
  ck_assert_ptr_eq(strstr(str1_1, str2_1), s21_strstr(str1_1, str2_1));

  char str1_2[20] = "hello world";
  char *str2_2 = "p";
  ck_assert_ptr_eq(strstr(str1_2, str2_2), s21_strstr(str1_2, str2_2));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char str1_1[20] = "hello world";
  char *str2_1 = "ll";
  ck_assert_ptr_eq(strstr(str1_1, str2_1), s21_strstr(str1_1, str2_1));

  char str1_2[20] = "hello world";
  char *str2_2 = "pow";
  ck_assert_ptr_eq(strstr(str1_2, str2_2), s21_strstr(str1_2, str2_2));
}
END_TEST

START_TEST(s21_strstr_test_3) {
  char str1_1[20] = "hello\0world";
  char *str2_1 = "\0";
  ck_assert_ptr_eq(strstr(str1_1, str2_1), s21_strstr(str1_1, str2_1));

  char str1_2[20] = "hello\nworld";
  char *str2_2 = "\n";
  ck_assert_ptr_eq(strstr(str1_2, str2_2), s21_strstr(str1_2, str2_2));
}
END_TEST

Suite *suite_strstr() {
  Suite *s;
  TCase *tc_strstr_test_1, *tc_strstr_test_2, *tc_strstr_test_3;

  s = suite_create("strstr_check");

  tc_strstr_test_1 = tcase_create("s21_strstr_test_1");
  tcase_add_test(tc_strstr_test_1, s21_strstr_test_1);
  suite_add_tcase(s, tc_strstr_test_1);

  tc_strstr_test_2 = tcase_create("s21_strstr_test_2");
  tcase_add_test(tc_strstr_test_2, s21_strstr_test_2);
  suite_add_tcase(s, tc_strstr_test_2);

  tc_strstr_test_3 = tcase_create("s21_strstr_test_3");
  tcase_add_test(tc_strstr_test_3, s21_strstr_test_3);
  suite_add_tcase(s, tc_strstr_test_3);

  return s;
}