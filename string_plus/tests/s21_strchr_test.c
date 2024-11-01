#include "../s21_string.h"
#include "s21_test.h"

START_TEST(empty) {
  char str[] = "";
  char c = '3';
  printf("case 1: find 3 in (empty)\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(empty_empty) {
  char str[] = "";
  char c = '\0';
  printf("case 2: find (empty)  in (empty)\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(normal_dec) {
  char str[] = "12345";
  char c = '3';
  printf("case 3: find 3 in 12345\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(normal_dec_st) {
  char str[] = "12345";
  char c = '1';
  printf("case 4: find 1 in 12345\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(normal_dec_end) {
  char str[] = "12345";
  char c = '5';
  printf("case 5: find 5 in 12345\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(x) {
  char str[] = "12345";
  char c = 'x';
  printf("case 6: find x in 12345\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(c) {
  char str[] = "abCd";
  char c = 'c';
  printf("case 7: find c in abCd\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(f) {
  char str[] = "abCd efg";
  char c = 'f';
  printf("case 8: find f in abCd efg\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(normal) {
  char str[] = "abCd efg";
  char c = 'b';
  printf("case 9: find b in abCd efg\n");
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *suite_strchr() {
  Suite *suite = suite_create("strchr check");
  TCase *tcase_core = tcase_create("strchr_tc");
  tcase_add_test(tcase_core, empty);
  tcase_add_test(tcase_core, empty_empty);
  tcase_add_test(tcase_core, normal_dec);
  tcase_add_test(tcase_core, normal_dec_st);
  tcase_add_test(tcase_core, normal_dec_end);
  tcase_add_test(tcase_core, x);
  tcase_add_test(tcase_core, c);
  tcase_add_test(tcase_core, f);
  tcase_add_test(tcase_core, normal);

  suite_add_tcase(suite, tcase_core);
  return suite;
}