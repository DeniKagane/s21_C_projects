#include "../s21_string.h"
#include "s21_test.h"

START_TEST(empty_res) {
  char str[] = "hihihi";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 4;

  printf("case 1:  + hihihi, n = 4\n");

  s21_strncpy(res, str, n);
  strncpy(res2, str, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(empty_res_0) {
  char str[] = "hihihi";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 0;

  printf("case 2:  + hihihi, n = 0\n");

  s21_strncpy(res, str, n);
  strncpy(res2, str, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(too_much) {
  char str[] = "hihihi";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 10;

  printf("case 3:  + hihihi, n = 8\n");

  s21_strncpy(res, str, n);
  strncpy(res2, str, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(nothing) {
  char str[] = "";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 0;

  printf("case 4:  + , n = 0\n");

  s21_strncpy(res, str, n);
  strncpy(res2, str, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(nothing_5) {
  char str[] = "";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 5;

  printf("case 5:  + , n = 5\n");

  s21_strncpy(res, str, n);
  strncpy(res2, str, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(not_empty) {
  char str[] = "hihihi";
  char res[10] = "oooh";
  char res2[10] = "oooh";
  s21_size_t n = 6;

  printf("case 6: oooh + hihihi, n = 6\n");

  s21_strncpy(res, str, n);
  strncpy(res2, str, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

START_TEST(empty_src) {
  char src[] = "";
  char res[] = "123";
  char res2[] = "123";
  s21_size_t n = 0;

  printf("case 7: 123 + , n = 0\n");

  s21_strncpy(res, src, n);
  strncpy(res2, src, n);

  ck_assert_str_eq(res, res2);
}
END_TEST

Suite *suite_strncpy() {
  Suite *suite = suite_create("strncpy check");
  TCase *tcase_core = tcase_create("strncpy_tc");
  tcase_add_test(tcase_core, empty_res);
  tcase_add_test(tcase_core, empty_res_0);
  tcase_add_test(tcase_core, too_much);
  tcase_add_test(tcase_core, nothing);
  tcase_add_test(tcase_core, nothing_5);
  tcase_add_test(tcase_core, not_empty);
  tcase_add_test(tcase_core, empty_src);

  suite_add_tcase(suite, tcase_core);
  return suite;
}