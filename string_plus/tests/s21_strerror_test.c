
#include "../s21_string.h"
#include "s21_test.h"

START_TEST(s21_strerror_test_1) {
  char *var1_str1 = strerror(4);
  char *var1_str2 = s21_strerror(4);
  ck_assert_str_eq(var1_str1, var1_str2);
}
END_TEST

START_TEST(s21_strerror_test_2) {
  char *var1_str1 = strerror(-20);
  char *var1_str2 = s21_strerror(-20);
  ck_assert_pstr_eq(var1_str1, var1_str2);

  char *var2_str1 = strerror(41);
  char *var2_str2 = s21_strerror(41);
  ck_assert_pstr_eq(var2_str1, var2_str2);

  char *var3_str1 = strerror(58);
  char *var3_str2 = s21_strerror(58);
  ck_assert_pstr_eq(var3_str1, var3_str2);
}
END_TEST

START_TEST(s21_strerror_test_3) {
  char *var1_str1 = strerror(150);
  char *var1_str2 = s21_strerror(150);
  ck_assert_pstr_eq(var1_str1, var1_str2);

  char *var2_str1 = strerror(-0);
  char *var2_str2 = s21_strerror(-0);
  ck_assert_pstr_eq(var2_str1, var2_str2);
}
END_TEST

START_TEST(s21_strerror_test_4) {
  char *original_error = S21_NULL;
  char *s21_error = S21_NULL;
  for (int i = -10000; i < 10001; ++i) {
    original_error = strerror(i);
    s21_error = s21_strerror(i);

    ck_assert_pstr_eq(original_error, s21_error);
  }
}
END_TEST

Suite *suite_strerror() {
  Suite *s;
  TCase *tc_strerror_test_1, *tc_strerror_test_2, *tc_strerror_test_3,
      *tc_strerror_test_4;

  s = suite_create("strerror check");

  tc_strerror_test_1 = tcase_create("s21_strerror_test_1");
  tcase_add_test(tc_strerror_test_1, s21_strerror_test_1);
  suite_add_tcase(s, tc_strerror_test_1);

  tc_strerror_test_2 = tcase_create("s21_strerror_test_2");
  tcase_add_test(tc_strerror_test_2, s21_strerror_test_2);
  suite_add_tcase(s, tc_strerror_test_2);

  tc_strerror_test_3 = tcase_create("s21_strerror_test_3");
  tcase_add_test(tc_strerror_test_3, s21_strerror_test_3);
  suite_add_tcase(s, tc_strerror_test_3);

  tc_strerror_test_4 = tcase_create("s21_strerror_test_4");
  tcase_add_test(tc_strerror_test_4, s21_strerror_test_4);
  suite_add_tcase(s, tc_strerror_test_4);

  return s;
}