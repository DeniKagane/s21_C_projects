#include "../s21_sprintf.h"

#include "s21_test.h"

START_TEST(normal_c_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%c", 'a');
  int len = sprintf(str, "%c", 'a');
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%c", 56);
  int len = sprintf(str, "%c", 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-c", 56);
  int len = sprintf(str, "%-c", 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-10c", 56);
  int len = sprintf(str, "%-10c", 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-*c", 34, 56);
  int len = sprintf(str, "%-*c", 34, 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*c", 34, 56);
  int len = sprintf(str, "%*c", 34, 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%11c", 56);
  int len = sprintf(str, "%11c", 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_c_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "Hhahah %11c !!", 56);
  int len = sprintf(str, "Hhahah %11c !!", 56);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%d", 112);
  int len = sprintf(str, "%d", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25d", 112);
  int len = sprintf(str, "%25d", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// START_TEST(normal_d_3) {
//   char s21_str[SIZE] = {'\0'};
//   char str[SIZE] = {'\0'};
//   int s21_len = s21_sprintf(s21_str, "%*hd", 5, 112);
//   int len = sprintf(str, "%*hd", 5, 112);
//   s21_size_t size = s21_strlen(str);
//   ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
//   ck_assert_int_eq(s21_len, len);
// }
// END_TEST

START_TEST(normal_d_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*d", 5, 112);
  int len = sprintf(str, "%.*d", 5, 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9d", 112);
  int len = sprintf(str, "%.9d", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9d", 112);
  int len = sprintf(str, "%-.9d", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9d", 112);
  int len = sprintf(str, "% -.9d", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9ld", -112l);
  int len = sprintf(str, "%+-.9ld", -112l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9d", 112);
  int len = sprintf(str, "%+.9d", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_d_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9d;\n", 14632);
  int len = sprintf(str, "it is number - %+.9d;\n", 14632);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %i
START_TEST(normal_i_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%i", 112);
  int len = sprintf(str, "%i", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25i", 112);
  int len = sprintf(str, "%25i", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*i", 5, 112);
  int len = sprintf(str, "%*i", 5, 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*i", 5, 112);
  int len = sprintf(str, "%.*i", 5, 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// START_TEST(normal_i_5) {
//   char s21_str[SIZE] = {'\0'};
//   char str[SIZE] = {'\0'};
//   int s21_len = s21_sprintf(s21_str, "%.9hi", 112);
//   int len = sprintf(str, "%.9hi", 112);
//   s21_size_t size = s21_strlen(str);
//   ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
//   ck_assert_int_eq(s21_len, len);
// }
// END_TEST

START_TEST(normal_i_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9i", 112);
  int len = sprintf(str, "%-.9i", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9i", 112);
  int len = sprintf(str, "% -.9i", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9i", 112);
  int len = sprintf(str, "%+-.9i", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9i", 112);
  int len = sprintf(str, "%+.9i", 112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9li;\n", -14632l);
  int len = sprintf(str, "it is number - %+.9li;\n", -14632l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9i;\n", 012);
  int len = sprintf(str, "it is number - %+.9i;\n", 012);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9i;\n", -012);
  int len = sprintf(str, "it is number - %+.9i;\n", -012);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9i;\n", 0x12);
  int len = sprintf(str, "it is number - %+.9i;\n", 0x12);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_i_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9i;\n", -0x12);
  int len = sprintf(str, "it is number - %+.9i;\n", -0x12);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %e
START_TEST(normal_e_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%e", 11.235);
  int len = sprintf(str, "%e", 11.235);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25e", 112.);
  int len = sprintf(str, "%25e", 112.);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*e", 5, .112);
  int len = sprintf(str, "%*e", 5, .112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*e", 5, -112e2);
  int len = sprintf(str, "%.*e", 5, -112e2);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9e", 0.00000001);
  int len = sprintf(str, "%.9e", 0.00000001);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9e", 876e-9);
  int len = sprintf(str, "%-.9e", 876e-9);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9e", 1e20);
  int len = sprintf(str, "% -.9e", 1e20);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9e", -5.6789);
  int len = sprintf(str, "%+-.9e", -5.6789);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9e", 0.05454);
  int len = sprintf(str, "%+.9e", 0.05454);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9e;\n", -146.32);
  int len = sprintf(str, "it is number - %+.9e;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+#.9e;\n", -146.32);
  int len = sprintf(str, "it is number - %+#.9e;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9e;\n", -146.32);
  int len = sprintf(str, "it is number - %0+#.9e;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9Le;\n", -146.32l);
  int len = sprintf(str, "it is number - %0+#.9Le;\n", -146.32l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_e_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9Le;\n", 0.l);
  int len = sprintf(str, "it is number - %0+#.9Le;\n", 0.l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %E
START_TEST(normal_E_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%E", 11.235);
  int len = sprintf(str, "%E", 11.235);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25E", 112.);
  int len = sprintf(str, "%25E", 112.);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*E", 5, .112);
  int len = sprintf(str, "%*E", 5, .112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*E", 5, -112e2);
  int len = sprintf(str, "%.*E", 5, -112e2);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9E", 0.00000001);
  int len = sprintf(str, "%.9E", 0.00000001);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9E", 876e-9);
  int len = sprintf(str, "%-.9E", 876e-9);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9E", 1e20);
  int len = sprintf(str, "% -.9E", 1e20);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9E", -5.6789);
  int len = sprintf(str, "%+-.9E", -5.6789);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9E", 0.05454);
  int len = sprintf(str, "%+.9E", 0.05454);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9E;\n", -146.32);
  int len = sprintf(str, "it is number - %+.9E;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+#.9E;\n", -146.32);
  int len = sprintf(str, "it is number - %+#.9E;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9E;\n", -146.32);
  int len = sprintf(str, "it is number - %0+#.9E;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9LE;\n", -146.32l);
  int len = sprintf(str, "it is number - %0+#.9LE;\n", -146.32l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_E_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9LE;\n", 0.l);
  int len = sprintf(str, "it is number - %0+#.9LE;\n", 0.l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %f
START_TEST(normal_f_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%f", 11.235);
  int len = sprintf(str, "%f", 11.235);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25f", 112.);
  int len = sprintf(str, "%25f", 112.);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*f", 5, .112);
  int len = sprintf(str, "%*f", 5, .112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*f", 5, -112e2);
  int len = sprintf(str, "%.*f", 5, -112e2);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9f", 0.00000001);
  int len = sprintf(str, "%.9f", 0.00000001);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9f", 876e-9);
  int len = sprintf(str, "%-.9f", 876e-9);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9f", 1e18);
  int len = sprintf(str, "% -.9f", 1e18);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9f", -5.6789);
  int len = sprintf(str, "%+-.9f", -5.6789);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9f", 0.05454);
  int len = sprintf(str, "%+.9f", 0.05454);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9f;\n", -146.32);
  int len = sprintf(str, "it is number - %+.9f;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+#.9f;\n", -146.32);
  int len = sprintf(str, "it is number - %+#.9f;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9f;\n", -146.32);
  int len = sprintf(str, "it is number - %0+#.9f;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9Lf;\n", -146.32l);
  int len = sprintf(str, "it is number - %0+#.9Lf;\n", -146.32l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_f_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9Lf;\n", 0.l);
  int len = sprintf(str, "it is number - %0+#.9Lf;\n", 0.l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %g
START_TEST(normal_g_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%g", 11.235);
  int len = sprintf(str, "%g", 11.235);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25g", 112.);
  int len = sprintf(str, "%25g", 112.);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*g", 5, .112);
  int len = sprintf(str, "%*g", 5, .112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*g", 5, -112e2);
  int len = sprintf(str, "%.*g", 5, -112e2);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9g", 0.00000001);
  int len = sprintf(str, "%.9g", 0.00000001);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9g", 876e-9);
  int len = sprintf(str, "%-.9g", 876e-9);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9g", 1e18);
  int len = sprintf(str, "% -.9g", 1e18);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9g", -5.6789);
  int len = sprintf(str, "%+-.9g", -5.6789);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9g", 0.05454);
  int len = sprintf(str, "%+.9g", 0.05454);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9g;\n", -146.32);
  int len = sprintf(str, "it is number - %+.9g;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+#.9g;\n", -146.32);
  int len = sprintf(str, "it is number - %+#.9g;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9g;\n", -146.32);
  int len = sprintf(str, "it is number - %0+#.9g;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9Lg;\n", -146.32l);
  int len = sprintf(str, "it is number - %0+#.9Lg;\n", -146.32l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_g_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9Lg;\n", 0.l);
  int len = sprintf(str, "it is number - %0+#.9Lg;\n", 0.l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %G
START_TEST(normal_G_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%G", 11.235);
  int len = sprintf(str, "%G", 11.235);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25G", 112.);
  int len = sprintf(str, "%25G", 112.);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*G", 5, .112);
  int len = sprintf(str, "%*G", 5, .112);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*G", 5, -112e2);
  int len = sprintf(str, "%.*G", 5, -112e2);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9G", 0.00000001);
  int len = sprintf(str, "%.9G", 0.00000001);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9G", 876e-9);
  int len = sprintf(str, "%-.9G", 876e-9);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "% -.9G", 1e18);
  int len = sprintf(str, "% -.9G", 1e18);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+-.9G", -5.6789);
  int len = sprintf(str, "%+-.9G", -5.6789);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%+.9G", 0.05454);
  int len = sprintf(str, "%+.9G", 0.05454);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+.9G;\n", -146.32);
  int len = sprintf(str, "it is number - %+.9G;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %+#.9G;\n", -146.32);
  int len = sprintf(str, "it is number - %+#.9G;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9G;\n", -146.32);
  int len = sprintf(str, "it is number - %0+#.9G;\n", -146.32);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9LG;\n", -146.32l);
  int len = sprintf(str, "it is number - %0+#.9LG;\n", -146.32l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_G_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %0+#.9LG;\n", 0.l);
  int len = sprintf(str, "it is number - %0+#.9LG;\n", 0.l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %o
START_TEST(normal_o_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%o", 03245);
  int len = sprintf(str, "%o", 03245);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25o", 01);
  int len = sprintf(str, "%25o", 01);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*o", 5, 04214);
  int len = sprintf(str, "%*o", 5, 04214);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*o", 5, 0);
  int len = sprintf(str, "%.*o", 5, 0);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9o", 123);
  int len = sprintf(str, "%.9o", 123);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9o", 0067);
  int len = sprintf(str, "%-.9o", 0067);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9o", 9879);
  int len = sprintf(str, "%-.9o", 9879);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9o", 01234567);
  int len = sprintf(str, "%-.9o", 01234567);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9o", 07654321);
  int len = sprintf(str, "%.9o", 07654321);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9o;\n", 0344);
  int len = sprintf(str, "it is number - %.9o;\n", 0344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#.9o;\n", 0344);
  int len = sprintf(str, "it is number - %#.9o;\n", 0344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#9o;\n", 0344);
  int len = sprintf(str, "it is number - %#9o;\n", 0344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_o_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#9.9o;\n", 0344);
  int len = sprintf(str, "it is number - %#9.9o;\n", 0344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// START_TEST(normal_o_14) {
//   char s21_str[SIZE] = {'\0'};
//   char str[SIZE] = {'\0'};
//   int s21_len = s21_sprintf(s21_str, "it is number - %#12.9ho;\n", 0344);
//   int len = sprintf(str, "it is number - %#12.9ho;\n", 0344);
//   s21_size_t size = s21_strlen(str);
//   ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
//   ck_assert_int_eq(s21_len, len);
// }
// END_TEST

START_TEST(normal_o_15) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#6.9lo;\n", 0344l);
  int len = sprintf(str, "it is number - %#6.9lo;\n", 0344l);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %s
START_TEST(normal_s_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%s", "1fg*%#&h");
  int len = sprintf(str, "%s", "1fg*%#&h");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25s", "01");
  int len = sprintf(str, "%25s", "01");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*s", 5, "04214");
  int len = sprintf(str, "%*s", 5, "04214");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*s", 5, "Heu!!!!!!!!!!!");
  int len = sprintf(str, "%.*s", 5, "Heu!!!!!!!!!!!");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9s", "Hmmmmmmmmmm.....");
  int len = sprintf(str, "%.9s", "Hmmmmmmmmmm.....");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9s", "Blalallalbvll");
  int len = sprintf(str, "%-.9s", "Blalallalbvll");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9s", "lolol kekekekeke cheburek!");
  int len = sprintf(str, "%-.9s", "lolol kekekekeke cheburek!");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9s", "Aaaaaaaa pomagiteeee");
  int len = sprintf(str, "%-.9s", "Aaaaaaaa pomagiteeee");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9s", "Baumanka - eto kruto!");
  int len = sprintf(str, "%.9s", "Baumanka - eto kruto!");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len =
      s21_sprintf(s21_str, "it is number - %.9s;\n", "Na samom dele net");
  int len = sprintf(str, "it is number - %.9s;\n", "Na samom dele net");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9s;\n", "");
  int len = sprintf(str, "it is number - %.9s;\n", "");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_s_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9ls;\n",
                            L"Ochen shirokie simvoli\taga");
  int len =
      sprintf(str, "it is number - %.9ls;\n", L"Ochen shirokie simvoli\taga");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 3245;
  int s21_len = s21_sprintf(s21_str, "%u", x);
  int len = sprintf(str, "%u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 1;
  int s21_len = s21_sprintf(s21_str, "%25u", x);
  int len = sprintf(str, "%25u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 4241;
  int s21_len = s21_sprintf(s21_str, "%*u", 5, x);
  int len = sprintf(str, "%*u", 5, x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 0;
  int s21_len = s21_sprintf(s21_str, "%.*u", 5, x);
  int len = sprintf(str, "%.*u", 5, x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 0x123;
  int s21_len = s21_sprintf(s21_str, "%.9u", x);
  int len = sprintf(str, "%.9u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 067;
  int s21_len = s21_sprintf(s21_str, "%-.9u", x);
  int len = sprintf(str, "%-.9u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 9879;
  int s21_len = s21_sprintf(s21_str, "%-.9u", x);
  int len = sprintf(str, "%-.9u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 01234567;
  int s21_len = s21_sprintf(s21_str, "%-.9u", x);
  int len = sprintf(str, "%-.9u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 7654321;
  int s21_len = s21_sprintf(s21_str, "%.9u", x);
  int len = sprintf(str, "%.9u", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 344;
  int s21_len = s21_sprintf(s21_str, "it is number - %.9u;\n", x);
  int len = sprintf(str, "it is number - %.9u;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 0374;
  int s21_len = s21_sprintf(s21_str, "it is number - %.9u;\n", x);
  int len = sprintf(str, "it is number - %.9u;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 9344;
  int s21_len = s21_sprintf(s21_str, "it is number - %9u;\n", x);
  int len = sprintf(str, "it is number - %9u;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned int x = 3440;
  int s21_len = s21_sprintf(s21_str, "it is number - %9.9u;\n", x);
  int len = sprintf(str, "it is number - %9.9u;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned short x = 32144;
  int s21_len = s21_sprintf(s21_str, "it is number - %12.9hu;\n", x);
  int len = sprintf(str, "it is number - %12.9hu;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_u_15) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned long x = 344701;
  int s21_len = s21_sprintf(s21_str, "it is number - %6.9lu;\n", x);
  int len = sprintf(str, "it is number - %6.9lu;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %x
START_TEST(normal_x_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%x", 0x3249A5);
  int len = sprintf(str, "%x", 0x3249A5);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25x", 0x1);
  int len = sprintf(str, "%25x", 0x1);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*x", 5, 0x42c14);
  int len = sprintf(str, "%*x", 5, 0x42c14);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*x", 5, 0);
  int len = sprintf(str, "%.*x", 5, 0);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9x", 123);
  int len = sprintf(str, "%.9x", 123);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9x", 0x06b7);
  int len = sprintf(str, "%-.9x", 0x06b7);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9x", 0x98d79);
  int len = sprintf(str, "%-.9x", 0x98d79);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9x", 0x1234567);
  int len = sprintf(str, "%-.9x", 0x1234567);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9x", 07654321);
  int len = sprintf(str, "%.9x", 07654321);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9x;\n", 0x344);
  int len = sprintf(str, "it is number - %.9x;\n", 0x344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#.9x;\n", 0x34a4);
  int len = sprintf(str, "it is number - %#.9x;\n", 0x34a4);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#9x;\n", 0xC344);
  int len = sprintf(str, "it is number - %#9x;\n", 0xC344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#9.9x;\n", 0x34B4);
  int len = sprintf(str, "it is number - %#9.9x;\n", 0x34B4);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned short x = 344;
  int s21_len = s21_sprintf(s21_str, "it is number - %#12.9hx;\n", x);
  int len = sprintf(str, "it is number - %#12.9hx;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_x_15) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#6.9lx;\n", 0x344Dl);
  int len = sprintf(str, "it is number - %#6.9lx;\n", 0x344Dl);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %X
START_TEST(normal_X_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%X", 0x3249A5);
  int len = sprintf(str, "%X", 0x3249A5);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25X", 0x1);
  int len = sprintf(str, "%25X", 0x1);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*X", 5, 0x42c14);
  int len = sprintf(str, "%*X", 5, 0x42c14);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*X", 5, 0);
  int len = sprintf(str, "%.*X", 5, 0);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9X", 123);
  int len = sprintf(str, "%.9X", 123);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9X", 0x06b7);
  int len = sprintf(str, "%-.9X", 0x06b7);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9X", 0x98d79);
  int len = sprintf(str, "%-.9X", 0x98d79);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9X", 0x1234567);
  int len = sprintf(str, "%-.9X", 0x1234567);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9X", 07654321);
  int len = sprintf(str, "%.9X", 07654321);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9X;\n", 0x344);
  int len = sprintf(str, "it is number - %.9X;\n", 0x344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#.9X;\n", 0x34a4);
  int len = sprintf(str, "it is number - %#.9X;\n", 0x34a4);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#9X;\n", 0xC344);
  int len = sprintf(str, "it is number - %#9X;\n", 0xC344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#9.9X;\n", 0x34B4);
  int len = sprintf(str, "it is number - %#9.9X;\n", 0x34B4);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  unsigned short x = 344;
  int s21_len = s21_sprintf(s21_str, "it is number - %#12.9hX;\n", x);
  int len = sprintf(str, "it is number - %#12.9hX;\n", x);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_X_15) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %#6.9lX;\n", 0x344Dl);
  int len = sprintf(str, "it is number - %#6.9lX;\n", 0x344Dl);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %p
START_TEST(normal_p_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%p", (void *)0x3249A5);
  int len = sprintf(str, "%p", (void *)0x3249A5);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25p", (void *)0x1);
  int len = sprintf(str, "%25p", (void *)0x1);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*p", 5, (void *)0x42c14);
  int len = sprintf(str, "%*p", 5, (void *)0x42c14);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int a = 3;
  int s21_len = s21_sprintf(s21_str, "%p", &a);
  int len = sprintf(str, "%p", &a);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int b = 56;
  int s21_len = s21_sprintf(s21_str, "%p", &b);
  int len = sprintf(str, "%p", &b);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-p", (void *)0x06b7);
  int len = sprintf(str, "%-p", (void *)0x06b7);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-p", (void *)0x98d79);
  int len = sprintf(str, "%-p", (void *)0x98d79);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-p", (void *)0x1234567);
  int len = sprintf(str, "%-p", (void *)0x1234567);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%p", (void *)07654321);
  int len = sprintf(str, "%p", (void *)07654321);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %p;\n", (void *)0x344);
  int len = sprintf(str, "it is number - %p;\n", (void *)0x344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %p;\n", (void *)0x34a4);
  int len = sprintf(str, "it is number - %p;\n", (void *)0x34a4);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %9p;\n", (void *)0xC344);
  int len = sprintf(str, "it is number - %9p;\n", (void *)0xC344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_13) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %9p;\n", (void *)0x34B4);
  int len = sprintf(str, "it is number - %9p;\n", (void *)0x34B4);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_14) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %12p;\n", (void *)344);
  int len = sprintf(str, "it is number - %12p;\n", (void *)344);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_p_15) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %6p;\n", (void *)0x344Dl);
  int len = sprintf(str, "it is number - %6p;\n", (void *)0x344Dl);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

// =======================================================================
// %n
START_TEST(normal_n_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%s%n", "1fg*%#&h", &s21_n);
  int len = sprintf(str, "%s%n", "1fg*%#&h", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%25s %d%n", "1fg*%#&h", 5, &s21_n);
  int len = sprintf(str, "%25s %d%n", "1fg*%#&h", 5, &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%*s%n", 5, "04214", &s21_n);
  int len = sprintf(str, "%*s%n", 5, "04214", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%.*s%n", 5, "Heu!!!!!!!!!!!", &s21_n);
  int len = sprintf(str, "%.*s%n", 5, "Heu!!!!!!!!!!!", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%.9s%n", "Hmmmmmmmmmm.....", &s21_n);
  int len = sprintf(str, "%.9s%n", "Hmmmmmmmmmm.....", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%-.9s%n", "Blalallalbvll", &s21_n);
  int len = sprintf(str, "%-.9s%n", "Blalallalbvll", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len =
      s21_sprintf(s21_str, "%-.9s%n", "lolol kekekekeke cheburek!", &s21_n);
  int len = sprintf(str, "%-.9s%n", "lolol kekekekeke cheburek!", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%-.9s%n", "Aaaaaaaa pomagiteeee", &s21_n);
  int len = sprintf(str, "%-.9s%n", "Aaaaaaaa pomagiteeee", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "%.9s%n", "Baumanka - eto kruto!", &s21_n);
  int len = sprintf(str, "%.9s%n", "Baumanka - eto kruto!", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "it is number - %.9s;\n%n",
                            "Na samom dele net", &s21_n);
  int len = sprintf(str, "it is number - %.9s;\n%n", "Na samom dele net", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "it is number - %.9s;\n%n", "", &s21_n);
  int len = sprintf(str, "it is number - %.9s;\n%n", "", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_n_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "it is number - %.9ls;\n%n",
                            L"Ochen shirokie simvoli\taga", &s21_n);
  int len = sprintf(str, "it is number - %.9ls;\n%n",
                    L"Ochen shirokie simvoli\taga", &n);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// =======================================================================
// %ls
START_TEST(normal_ls_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%ls", L"1fg*%#&h");
  int len = sprintf(str, "%ls", L"1fg*%#&h");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_2) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%25ls", L"01");
  int len = sprintf(str, "%25ls", L"01");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%*ls", 5, L"04214");
  int len = sprintf(str, "%*ls", 5, L"04214");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_4) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.*ls", 5, L"Heu!!!!!!!!!!!");
  int len = sprintf(str, "%.*ls", 5, L"Heu!!!!!!!!!!!");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_5) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9ls", L"Hmmmmmmmmmm.....");
  int len = sprintf(str, "%.9ls", L"Hmmmmmmmmmm.....");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_6) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9ls", L"Blalallalbvll");
  int len = sprintf(str, "%-.9ls", L"Blalallalbvll");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_7) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9ls", L"lolol kekekekeke cheburek!");
  int len = sprintf(str, "%-.9ls", L"lolol kekekekeke cheburek!");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_8) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-.9ls", L"Aaaaaaaa pomagiteeee");
  int len = sprintf(str, "%-.9ls", L"Aaaaaaaa pomagiteeee");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_9) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%.9ls", L"Baumanka - eto kruto!");
  int len = sprintf(str, "%.9ls", L"Baumanka - eto kruto!");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_10) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len =
      s21_sprintf(s21_str, "it is number - %.9ls;\n", L"Na samom dele net");
  int len = sprintf(str, "it is number - %.9ls;\n", L"Na samom dele net");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_11) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9ls;\n", L"");
  int len = sprintf(str, "it is number - %.9ls;\n", L"");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_ls_12) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "it is number - %.9ls;\n",
                            L"Ochen shirokie simvoli\taga");
  int len =
      sprintf(str, "it is number - %.9ls;\n", L"Ochen shirokie simvoli\taga");
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_mixed_1) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_n = 0;
  int n = 0;
  int s21_len = s21_sprintf(s21_str, "it is number - %.9ls;\n%n%d\t %.3e",
                            L"Ochen shirokie simvoli\taga", &s21_n, 5, 6.);
  int len = sprintf(str, "it is number - %.9ls;\n%n%d\t %.3e",
                    L"Ochen shirokie simvoli\taga", &n, 5, 6.);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(normal_mixed_3) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-50s:%d", "Summ", 1000);
  int len = sprintf(str, "%-50s:%d", "Summ", 1000);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

START_TEST(normal_perc) {
  char s21_str[SIZE] = {'\0'};
  char str[SIZE] = {'\0'};
  int s21_len = s21_sprintf(s21_str, "%-50s:%d%%", "Summ", 1000);
  int len = sprintf(str, "%-50s:%d%%", "Summ", 1000);
  s21_size_t size = s21_strlen(str);
  ck_assert_int_eq(s21_memcmp(s21_str, str, size), 0);
  ck_assert_int_eq(s21_len, len);
}
END_TEST

Suite *suite_sprintf() {
  Suite *suite = suite_create("sprintf check");

  TCase *tcase_core = tcase_create("sprintf_tc");

  tcase_add_test(tcase_core, normal_c_1);
  tcase_add_test(tcase_core, normal_c_2);
  tcase_add_test(tcase_core, normal_c_3);
  tcase_add_test(tcase_core, normal_c_4);
  tcase_add_test(tcase_core, normal_c_5);
  tcase_add_test(tcase_core, normal_c_6);
  tcase_add_test(tcase_core, normal_c_7);
  tcase_add_test(tcase_core, normal_c_8);

  tcase_add_test(tcase_core, normal_d_1);
  tcase_add_test(tcase_core, normal_d_2);
  tcase_add_test(tcase_core, normal_d_4);
  tcase_add_test(tcase_core, normal_d_5);
  tcase_add_test(tcase_core, normal_d_6);
  tcase_add_test(tcase_core, normal_d_7);
  tcase_add_test(tcase_core, normal_d_8);
  tcase_add_test(tcase_core, normal_d_9);
  tcase_add_test(tcase_core, normal_d_10);

  tcase_add_test(tcase_core, normal_i_1);
  tcase_add_test(tcase_core, normal_i_2);
  tcase_add_test(tcase_core, normal_i_3);
  tcase_add_test(tcase_core, normal_i_4);
  tcase_add_test(tcase_core, normal_i_6);
  tcase_add_test(tcase_core, normal_i_7);
  tcase_add_test(tcase_core, normal_i_8);
  tcase_add_test(tcase_core, normal_i_9);
  tcase_add_test(tcase_core, normal_i_10);
  tcase_add_test(tcase_core, normal_i_11);
  tcase_add_test(tcase_core, normal_i_12);
  tcase_add_test(tcase_core, normal_i_13);
  tcase_add_test(tcase_core, normal_i_14);

  tcase_add_test(tcase_core, normal_e_1);
  tcase_add_test(tcase_core, normal_e_2);
  tcase_add_test(tcase_core, normal_e_3);
  tcase_add_test(tcase_core, normal_e_4);
  tcase_add_test(tcase_core, normal_e_5);
  tcase_add_test(tcase_core, normal_e_6);
  tcase_add_test(tcase_core, normal_e_7);
  tcase_add_test(tcase_core, normal_e_8);
  tcase_add_test(tcase_core, normal_e_9);
  tcase_add_test(tcase_core, normal_e_10);
  tcase_add_test(tcase_core, normal_e_11);
  tcase_add_test(tcase_core, normal_e_12);
  tcase_add_test(tcase_core, normal_e_13);
  tcase_add_test(tcase_core, normal_e_14);

  tcase_add_test(tcase_core, normal_E_1);
  tcase_add_test(tcase_core, normal_E_2);
  tcase_add_test(tcase_core, normal_E_3);
  tcase_add_test(tcase_core, normal_E_4);
  tcase_add_test(tcase_core, normal_E_5);
  tcase_add_test(tcase_core, normal_E_6);
  tcase_add_test(tcase_core, normal_E_7);
  tcase_add_test(tcase_core, normal_E_8);
  tcase_add_test(tcase_core, normal_E_9);
  tcase_add_test(tcase_core, normal_E_10);
  tcase_add_test(tcase_core, normal_E_11);
  tcase_add_test(tcase_core, normal_E_12);
  tcase_add_test(tcase_core, normal_E_13);
  tcase_add_test(tcase_core, normal_E_14);

  tcase_add_test(tcase_core, normal_f_1);
  tcase_add_test(tcase_core, normal_f_2);
  tcase_add_test(tcase_core, normal_f_3);
  tcase_add_test(tcase_core, normal_f_4);
  tcase_add_test(tcase_core, normal_f_5);
  tcase_add_test(tcase_core, normal_f_6);
  tcase_add_test(tcase_core, normal_f_7);
  tcase_add_test(tcase_core, normal_f_8);
  tcase_add_test(tcase_core, normal_f_9);
  tcase_add_test(tcase_core, normal_f_10);
  tcase_add_test(tcase_core, normal_f_11);
  tcase_add_test(tcase_core, normal_f_12);
  tcase_add_test(tcase_core, normal_f_13);
  tcase_add_test(tcase_core, normal_f_14);

  tcase_add_test(tcase_core, normal_g_1);
  tcase_add_test(tcase_core, normal_g_2);
  tcase_add_test(tcase_core, normal_g_3);
  tcase_add_test(tcase_core, normal_g_4);
  tcase_add_test(tcase_core, normal_g_5);
  tcase_add_test(tcase_core, normal_g_6);
  tcase_add_test(tcase_core, normal_g_7);
  tcase_add_test(tcase_core, normal_g_8);
  tcase_add_test(tcase_core, normal_g_9);
  tcase_add_test(tcase_core, normal_g_10);
  tcase_add_test(tcase_core, normal_g_11);
  tcase_add_test(tcase_core, normal_g_12);
  tcase_add_test(tcase_core, normal_g_13);
  tcase_add_test(tcase_core, normal_g_14);

  tcase_add_test(tcase_core, normal_G_1);
  tcase_add_test(tcase_core, normal_G_2);
  tcase_add_test(tcase_core, normal_G_3);
  tcase_add_test(tcase_core, normal_G_4);
  tcase_add_test(tcase_core, normal_G_5);
  tcase_add_test(tcase_core, normal_G_6);
  tcase_add_test(tcase_core, normal_G_7);
  tcase_add_test(tcase_core, normal_G_8);
  tcase_add_test(tcase_core, normal_G_9);
  tcase_add_test(tcase_core, normal_G_10);
  tcase_add_test(tcase_core, normal_G_11);
  tcase_add_test(tcase_core, normal_G_12);
  tcase_add_test(tcase_core, normal_G_13);
  tcase_add_test(tcase_core, normal_G_14);

  tcase_add_test(tcase_core, normal_o_1);
  tcase_add_test(tcase_core, normal_o_2);
  tcase_add_test(tcase_core, normal_o_3);
  tcase_add_test(tcase_core, normal_o_4);
  tcase_add_test(tcase_core, normal_o_5);
  tcase_add_test(tcase_core, normal_o_6);
  tcase_add_test(tcase_core, normal_o_7);
  tcase_add_test(tcase_core, normal_o_8);
  tcase_add_test(tcase_core, normal_o_9);
  tcase_add_test(tcase_core, normal_o_10);
  tcase_add_test(tcase_core, normal_o_11);
  tcase_add_test(tcase_core, normal_o_12);
  tcase_add_test(tcase_core, normal_o_13);
  tcase_add_test(tcase_core, normal_o_15);

  tcase_add_test(tcase_core, normal_s_1);
  tcase_add_test(tcase_core, normal_s_2);
  tcase_add_test(tcase_core, normal_s_3);
  tcase_add_test(tcase_core, normal_s_4);
  tcase_add_test(tcase_core, normal_s_5);
  tcase_add_test(tcase_core, normal_s_6);
  tcase_add_test(tcase_core, normal_s_7);
  tcase_add_test(tcase_core, normal_s_8);
  tcase_add_test(tcase_core, normal_s_9);
  tcase_add_test(tcase_core, normal_s_10);
  tcase_add_test(tcase_core, normal_s_11);
  tcase_add_test(tcase_core, normal_s_12);

  tcase_add_test(tcase_core, normal_u_1);
  tcase_add_test(tcase_core, normal_u_2);
  tcase_add_test(tcase_core, normal_u_3);
  tcase_add_test(tcase_core, normal_u_4);
  tcase_add_test(tcase_core, normal_u_5);
  tcase_add_test(tcase_core, normal_u_6);
  tcase_add_test(tcase_core, normal_u_7);
  tcase_add_test(tcase_core, normal_u_8);
  tcase_add_test(tcase_core, normal_u_9);
  tcase_add_test(tcase_core, normal_u_10);
  tcase_add_test(tcase_core, normal_u_11);
  tcase_add_test(tcase_core, normal_u_12);
  tcase_add_test(tcase_core, normal_u_13);
  tcase_add_test(tcase_core, normal_u_14);
  tcase_add_test(tcase_core, normal_u_15);

  tcase_add_test(tcase_core, normal_x_1);
  tcase_add_test(tcase_core, normal_x_2);
  tcase_add_test(tcase_core, normal_x_3);
  tcase_add_test(tcase_core, normal_x_4);
  tcase_add_test(tcase_core, normal_x_5);
  tcase_add_test(tcase_core, normal_x_6);
  tcase_add_test(tcase_core, normal_x_7);
  tcase_add_test(tcase_core, normal_x_8);
  tcase_add_test(tcase_core, normal_x_9);
  tcase_add_test(tcase_core, normal_x_10);
  tcase_add_test(tcase_core, normal_x_11);
  tcase_add_test(tcase_core, normal_x_12);
  tcase_add_test(tcase_core, normal_x_13);
  tcase_add_test(tcase_core, normal_x_14);
  tcase_add_test(tcase_core, normal_x_15);

  tcase_add_test(tcase_core, normal_X_1);
  tcase_add_test(tcase_core, normal_X_2);
  tcase_add_test(tcase_core, normal_X_3);
  tcase_add_test(tcase_core, normal_X_4);
  tcase_add_test(tcase_core, normal_X_5);
  tcase_add_test(tcase_core, normal_X_6);
  tcase_add_test(tcase_core, normal_X_7);
  tcase_add_test(tcase_core, normal_X_8);
  tcase_add_test(tcase_core, normal_X_9);
  tcase_add_test(tcase_core, normal_X_10);
  tcase_add_test(tcase_core, normal_X_11);
  tcase_add_test(tcase_core, normal_X_12);
  tcase_add_test(tcase_core, normal_X_13);
  tcase_add_test(tcase_core, normal_X_14);
  tcase_add_test(tcase_core, normal_X_15);

  tcase_add_test(tcase_core, normal_p_1);
  tcase_add_test(tcase_core, normal_p_2);
  tcase_add_test(tcase_core, normal_p_3);
  tcase_add_test(tcase_core, normal_p_4);
  tcase_add_test(tcase_core, normal_p_5);
  tcase_add_test(tcase_core, normal_p_6);
  tcase_add_test(tcase_core, normal_p_7);
  tcase_add_test(tcase_core, normal_p_8);
  tcase_add_test(tcase_core, normal_p_9);
  tcase_add_test(tcase_core, normal_p_10);
  tcase_add_test(tcase_core, normal_p_11);
  tcase_add_test(tcase_core, normal_p_12);
  tcase_add_test(tcase_core, normal_p_13);
  tcase_add_test(tcase_core, normal_p_14);
  tcase_add_test(tcase_core, normal_p_15);

  tcase_add_test(tcase_core, normal_n_1);
  tcase_add_test(tcase_core, normal_n_2);
  tcase_add_test(tcase_core, normal_n_3);
  tcase_add_test(tcase_core, normal_n_4);
  tcase_add_test(tcase_core, normal_n_5);
  tcase_add_test(tcase_core, normal_n_6);
  tcase_add_test(tcase_core, normal_n_7);
  tcase_add_test(tcase_core, normal_n_8);
  tcase_add_test(tcase_core, normal_n_9);
  tcase_add_test(tcase_core, normal_n_10);
  tcase_add_test(tcase_core, normal_n_11);
  tcase_add_test(tcase_core, normal_n_12);

  tcase_add_test(tcase_core, normal_ls_1);
  tcase_add_test(tcase_core, normal_ls_2);
  tcase_add_test(tcase_core, normal_ls_3);
  tcase_add_test(tcase_core, normal_ls_4);
  tcase_add_test(tcase_core, normal_ls_5);
  tcase_add_test(tcase_core, normal_ls_6);
  tcase_add_test(tcase_core, normal_ls_7);
  tcase_add_test(tcase_core, normal_ls_8);
  tcase_add_test(tcase_core, normal_ls_9);
  tcase_add_test(tcase_core, normal_ls_10);
  tcase_add_test(tcase_core, normal_ls_11);
  tcase_add_test(tcase_core, normal_ls_12);

  tcase_add_test(tcase_core, normal_mixed_1);
  tcase_add_test(tcase_core, normal_mixed_3);

  tcase_add_test(tcase_core, normal_perc);

  suite_add_tcase(suite, tcase_core);

  return suite;
}