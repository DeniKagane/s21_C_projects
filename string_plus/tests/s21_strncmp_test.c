#include "../s21_string.h"
#include "s21_test.h"

START_TEST(different_strings_same_length) {
  char str1[5] = "abcde";
  char str2[5] = "abfgh";
  size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
  ck_assert_int_eq(strncmp(str2, str1, n), s21_strncmp(str2, str1, n));
}
END_TEST

START_TEST(equal_strings_same_length) {
  char str1[5] = "equal";
  char str2[5] = "equal";
  size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(different_length) {
  char str1[10] = "string";
  char str2[20] = "string_longer";
  size_t n5 = 5, n10 = 10;
  ck_assert_int_eq(strncmp(str1, str2, n5), s21_strncmp(str1, str2, n5));
  ck_assert_int_eq(strncmp(str1, str2, n10), s21_strncmp(str1, str2, n10));
  ck_assert_int_eq(strncmp(str2, str1, n10), s21_strncmp(str2, str1, n10));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("strncmp chceck");
  TCase *tc = tcase_create("strncmp tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, different_strings_same_length);
  tcase_add_test(tc, equal_strings_same_length);
  tcase_add_test(tc, different_length);
  return s;
}