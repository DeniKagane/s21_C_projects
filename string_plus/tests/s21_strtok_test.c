#include "../s21_string.h"
#include "s21_test.h"

START_TEST(normal) {
  char str1[] = "test1+test2+test3";
  char str2[] = "test1+test2+test3";
  char delim[3] = "+";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(normal_2) {
  char str1[] = "test1 test2 test3.test4";
  char str2[] = "test1 test2 test3.test4";
  char delim[3] = ". ";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(sep_both) {
  char str1[] = "+test1+test2+test3+";
  char str2[] = "+test1+test2+test3+";
  char delim[3] = "+";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(sep_end) {
  char str1[] = "test1+test2+test3+";
  char str2[] = "test1+test2+test3+";
  char delim[3] = "+";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(sep_start) {
  char str1[] = "+test1+test2+test3";
  char str2[] = "+test1+test2+test3";
  char delim[3] = "+";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(many_seps) {
  char str1[] = ". . test1 . test2";
  char str2[] = ". . test1 . test2";
  char delim[3] = ". ";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

START_TEST(no_sep) {
  char str1[] = ". . test1 . test2";
  char str2[] = ". . test1 . test2";
  char delim[3] = "/";
  char *nstr1, *nstr2;
  nstr1 = strtok(str1, delim);
  nstr2 = s21_strtok(str2, delim);
  while (nstr1 != S21_NULL) {
    ck_assert_pstr_eq(nstr1, nstr2);
    nstr1 = strtok(S21_NULL, delim);
    nstr2 = s21_strtok(S21_NULL, delim);
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *suite = suite_create("strtok check");
  TCase *tcase_core = tcase_create("strtok_tc");
  tcase_add_test(tcase_core, normal);
  tcase_add_test(tcase_core, normal_2);
  tcase_add_test(tcase_core, sep_both);
  tcase_add_test(tcase_core, sep_end);
  tcase_add_test(tcase_core, sep_start);
  tcase_add_test(tcase_core, many_seps);
  tcase_add_test(tcase_core, no_sep);

  suite_add_tcase(suite, tcase_core);
  return suite;
}