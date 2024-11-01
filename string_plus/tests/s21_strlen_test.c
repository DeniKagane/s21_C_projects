#include "../s21_string.h"
#include "s21_test.h"

START_TEST(spaces) {
  char str[] = " оооо  spaces    !";
  printf("case 1:  оооо  spaces    !\n");
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(empty_str) {
  char str[] = "";
  printf("case 2:\n");
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(one_symbol_test) {
  char str[] = "1\0";
  printf("case 3: 1\\0\n");
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *suite_strlen() {
  Suite *suite = suite_create("strlen check");
  TCase *tcase_core = tcase_create("strlen_tc");
  tcase_add_test(tcase_core, spaces);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}