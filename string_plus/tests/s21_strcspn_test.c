#include "../s21_string.h"
#include "s21_test.h"

START_TEST(normal) {
  char src[] = "678";
  char res[] = "12345678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(not_after) {
  char src[] = "138";
  char res[] = "12345678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(last) {
  char src[] = "876";
  char res[] = "12345678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(not_in) {
  char src[] = "f";
  char res[] = "12345678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(space) {
  char src[] = " ";
  char res[] = "1234 5678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(end) {
  char src[] = "\0";
  char res[] = "1234 5678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(nothing) {
  char src[] = "";
  char res[] = "1234 5678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(all) {
  char src[] = "1234 5678";
  char res[] = "1234 5678";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(empty) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

Suite *suite_strcspn() {
  Suite *suite = suite_create("strcspn check");
  TCase *tcase_core = tcase_create("strcspn_tc");

  tcase_add_test(tcase_core, normal);
  tcase_add_test(tcase_core, not_after);
  tcase_add_test(tcase_core, last);
  tcase_add_test(tcase_core, not_in);
  tcase_add_test(tcase_core, space);
  tcase_add_test(tcase_core, end);
  tcase_add_test(tcase_core, nothing);
  tcase_add_test(tcase_core, all);
  tcase_add_test(tcase_core, empty);

  suite_add_tcase(suite, tcase_core);
  return suite;
}