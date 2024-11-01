#include "../s21_string.h"
#include "s21_test.h"

START_TEST(normal) {
  char in[] = "1234567";
  char find[] = "45";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(normal_beg) {
  char in[] = "1234567";
  char find[] = "123";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(normal_end) {
  char in[] = "1234567";
  char find[] = "7";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(more_end) {
  char in[] = "1234567";
  char find[] = "78";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(more_beg) {
  char in[] = "1234567";
  char find[] = "01";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(nothing) {
  char in[] = "1234567";
  char find[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(all) {
  char in[] = "1234567";
  char find[] = "1234567";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(none) {
  char in[] = "1234567";
  char find[] = "";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(space) {
  char in[] = "1234 567";
  char find[] = " ";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(not_in) {
  char in[] = "1234567";
  char find[] = "9";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

START_TEST(empty) {
  char in[] = "";
  char find[] = "";

  ck_assert_pstr_eq(s21_strpbrk(in, find), strpbrk(in, find));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *suite = suite_create("strpbrk check");
  TCase *tcase_core = tcase_create("strpbrk_tc");

  tcase_add_test(tcase_core, normal);
  tcase_add_test(tcase_core, normal_beg);
  tcase_add_test(tcase_core, normal_end);
  tcase_add_test(tcase_core, more_end);
  tcase_add_test(tcase_core, more_beg);
  tcase_add_test(tcase_core, nothing);
  tcase_add_test(tcase_core, all);
  tcase_add_test(tcase_core, none);
  tcase_add_test(tcase_core, space);
  tcase_add_test(tcase_core, not_in);
  tcase_add_test(tcase_core, empty);

  suite_add_tcase(suite, tcase_core);
  return suite;
}