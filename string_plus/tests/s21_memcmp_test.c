#include "../s21_string.h"
#include "s21_test.h"

START_TEST(n_5) {
  char *str1 = "Memcmp test string1";
  char *str2 = "Memcmp test string2";
  printf("case 1: 5\n");
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(n_256) {
  char *str1 = "Memcmp test string1";
  char *str2 = "Memcmp test string2";
  printf("case 2: 256\n");
  ck_assert_int_eq(s21_memcmp(str1, str2, 256), memcmp(str1, str2, 256));
}
END_TEST

START_TEST(n_0) {
  char *str1 = "Memcmp test string1";
  char *str2 = "Memcmp test string2";
  printf("case 3: 0\n");
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(n_1) {
  char *str1 = "Memcmp test string1";
  char *str2 = "Memcmp test string2";
  printf("case 4: 1\n");
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
}
END_TEST

START_TEST(str_size) {
  char *str1 = "Memcmp test string1";
  char *str2 = "Memcmp test string2";
  printf("case 5: str size(19)\n");
  ck_assert_int_eq(s21_memcmp(str1, str2, 19), memcmp(str1, str2, 19));
}
END_TEST

Suite *suite_memcmp() {
  printf("string 1: Memcmp test string1\nstring 2: Memcmp test string2\n");
  Suite *suite = suite_create("memcmp check");
  TCase *tcase_core = tcase_create("memcmp_tc");
  tcase_add_test(tcase_core, n_5);
  tcase_add_test(tcase_core, n_256);
  tcase_add_test(tcase_core, n_0);
  tcase_add_test(tcase_core, n_1);
  tcase_add_test(tcase_core, str_size);

  suite_add_tcase(suite, tcase_core);
  return suite;
}