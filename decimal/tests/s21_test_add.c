#include <stdio.h>

#include "../s21_decimal.h"
#include "s21_test.h"

START_TEST(t1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(t2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(t3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(t4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(t5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(t6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(t7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(t11) {
  s21_decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t12) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = 1.234;
  float res_origin = -1232.766;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t13) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = -1.234;
  float res_origin = -1235.234;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t14) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 2.0234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t15) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0234;
  float res_origin = -1052.0234;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t16) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0e2;
  float res_origin = -12140;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(t17) {
  s21_decimal dec1, dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = 100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(t18) {
  s21_decimal dec1, dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = -100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(t19) {
  s21_decimal dec1, dec2;
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(t20) {
  s21_decimal dec1, dec2;
  int tmp1 = -2147483647;
  int tmp2 = 2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(t21) {
  int tmp1 = 4294967295;
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, 0}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(t22) {
  float float_a = -10758.218750;
  float float_b = 6268.843750;

  float float_res = float_a + float_b;

  s21_decimal expected = {0};
  s21_from_float_to_decimal(float_res, &expected);

  s21_decimal dec_a = {0};
  s21_from_float_to_decimal(float_a, &dec_a);
  s21_decimal dec_b = {0};
  s21_from_float_to_decimal(float_b, &dec_b);

  s21_decimal result = {0};
  int code = s21_add(dec_a, dec_b, &result);

  float got_float = 0;
  s21_from_decimal_to_float(result, &got_float);

  ck_assert_int_eq(code, 0);
  ck_assert_float_eq_tol(got_float, float_res, 1e-06);
}

START_TEST(t23) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(t24) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(t25) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(t26) {
  s21_decimal c = {{5, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{10, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t27) {
  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, S21_FALSE);
}
END_TEST

START_TEST(t28) {
  s21_decimal c = {{2147483647, 0, 0, 0}};
  s21_decimal d = {{2147483647, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t29) {
  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t30) {
  s21_decimal c = {{1000, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t31) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(*p_result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t32) {
  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t33) {
  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t34) {
  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t35) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t36) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t37) {
  s21_decimal c = {{UINT32_MAX, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 1, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t38) {
  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t39) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t40) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t41) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t42) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t43) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t44) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t45) {
  s21_decimal c = {0};
  c.bits[0] = 0b11111111111111111111111111111110;
  c.bits[1] = 0b00000000000000000000000000000000;
  c.bits[2] = 0b00000000000000000000000000000000;
  c.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {0};
  etalon.bits[0] = 0b11111111111111111111111111111111;
  etalon.bits[1] = 0b00000000000000000000000000000000;
  etalon.bits[2] = 0b00000000000000000000000000000000;
  etalon.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t46) {
  s21_decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t47) {
  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t48) {
  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t49) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t50) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;

  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal* p_res = &result;

  int add = s21_add(src1, src2, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);

  int equal = s21_is_equal(result, origin);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t51) {
  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t52) {
  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t53) {
  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t54) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t55) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t56) {
  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t57) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t58) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t59) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t60) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t61) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_1}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t62) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_2}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t63) {
  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t64) {
  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t65) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(t66) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(t67) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(t68) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(t69) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(t70) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b00000000000000000000001111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000001111111111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b00000000000000000010101111110101;
  original_res.bits[1] = 0b00000000000000000000000000000000;
  original_res.bits[2] = 0b00000000000000000000000000000000;
  original_res.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

Suite* suite_add(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("s21_add");
  tc = tcase_create("case_add");

  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);
  tcase_add_test(tc, t8);
  tcase_add_test(tc, t9);
  tcase_add_test(tc, t10);
  tcase_add_test(tc, t11);
  tcase_add_test(tc, t12);
  tcase_add_test(tc, t13);
  tcase_add_test(tc, t14);
  tcase_add_test(tc, t15);
  tcase_add_test(tc, t16);
  tcase_add_test(tc, t17);
  tcase_add_test(tc, t18);
  tcase_add_test(tc, t19);
  tcase_add_test(tc, t20);
  tcase_add_test(tc, t21);
  tcase_add_test(tc, t22);
  tcase_add_test(tc, t23);
  tcase_add_test(tc, t24);
  tcase_add_test(tc, t25);
  tcase_add_test(tc, t26);
  tcase_add_test(tc, t27);
  tcase_add_test(tc, t28);
  tcase_add_test(tc, t29);
  tcase_add_test(tc, t30);
  tcase_add_test(tc, t31);
  tcase_add_test(tc, t32);
  tcase_add_test(tc, t33);
  tcase_add_test(tc, t34);
  tcase_add_test(tc, t35);
  tcase_add_test(tc, t36);
  tcase_add_test(tc, t37);
  tcase_add_test(tc, t38);
  tcase_add_test(tc, t39);
  tcase_add_test(tc, t40);
  tcase_add_test(tc, t41);
  tcase_add_test(tc, t42);
  tcase_add_test(tc, t43);
  tcase_add_test(tc, t44);
  tcase_add_test(tc, t45);
  tcase_add_test(tc, t46);
  tcase_add_test(tc, t47);
  tcase_add_test(tc, t48);
  tcase_add_test(tc, t49);
  tcase_add_test(tc, t50);
  tcase_add_test(tc, t51);
  tcase_add_test(tc, t52);
  tcase_add_test(tc, t53);
  tcase_add_test(tc, t54);
  tcase_add_test(tc, t55);
  tcase_add_test(tc, t56);
  tcase_add_test(tc, t57);
  tcase_add_test(tc, t58);
  tcase_add_test(tc, t59);
  tcase_add_test(tc, t60);
  tcase_add_test(tc, t61);
  tcase_add_test(tc, t62);
  tcase_add_test(tc, t63);
  tcase_add_test(tc, t64);
  tcase_add_test(tc, t65);
  tcase_add_test(tc, t66);
  tcase_add_test(tc, t67);
  tcase_add_test(tc, t68);
  tcase_add_test(tc, t69);
  tcase_add_test(tc, t70);
  suite_add_tcase(s, tc);
  return s;
}