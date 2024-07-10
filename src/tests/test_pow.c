#include "../test_includes/s21_tests.h"

START_TEST(integer_number) {
  ck_assert_float_eq(s21_pow(6, 3), pow(6, 3));
  ck_assert_float_eq(s21_pow(-6, 3), pow(-6, 3));
  ck_assert_float_eq(s21_pow(6, -3), pow(6, -3));
  ck_assert_float_eq(s21_pow(-6, -3), pow(-6, -3));
  ck_assert_float_eq(s21_pow(-8, 4), pow(-8, 4));
  ck_assert_float_eq(s21_pow(-8, -4), pow(-8, -4));
}
END_TEST

START_TEST(double_number) {
  ck_assert_float_eq(s21_pow(8.366, 3.155), pow(8.366, 3.155));
  ck_assert_float_eq(s21_pow(2.5, -3.21), pow(2.5, -3.21));
  ck_assert_float_eq(s21_pow(-12.4, 2), pow(-12.4, 2));
  ck_assert_int_eq(s21_pow(-25, 0.5), pow(-25, 0.5));
  ck_assert_float_eq(s21_pow(9, 0.5), pow(9, 0.5));
  ck_assert_float_eq(s21_pow(-27, 1 / 3), pow(-27, 1 / 3));
  ck_assert_float_eq(s21_pow(25, 1), pow(25, 1));
  ck_assert_float_eq(s21_pow(-1, 33), pow(-1, 33));
  ck_assert_float_eq(s21_pow(-1, 32), pow(-1, 32));
  ck_assert_float_eq(s21_pow(1, 22), pow(1, 22));
}
END_TEST

START_TEST(zero_test) {
  ck_assert_float_eq(s21_pow(6.4646, 0), pow(6.4646, 0));
  ck_assert_float_eq(s21_pow(0.0, 0), pow(0.0, 0));
  ck_assert_float_eq(s21_pow(0.0, 235), pow(0.0, 235));
}
END_TEST

START_TEST(infinity) {
  ck_assert_float_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));
  ck_assert_float_eq(s21_pow(INFINITY, -INFINITY), pow(INFINITY, -INFINITY));
  ck_assert_float_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
  ck_assert_float_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));

  ck_assert_float_eq(s21_pow(5, INFINITY), pow(5, INFINITY));
  ck_assert_float_eq(s21_pow(0.3, INFINITY), pow(0.3, INFINITY));
  ck_assert_float_eq(s21_pow(5, -INFINITY), pow(5, -INFINITY));
  ck_assert_float_eq(s21_pow(0.3, -INFINITY), pow(0.3, -INFINITY));

  ck_assert_float_eq(s21_pow(INFINITY, 3), pow(INFINITY, 3));
  ck_assert_float_eq(s21_pow(INFINITY, -3), pow(INFINITY, -3));
  ck_assert_float_eq(s21_pow(-INFINITY, 3), pow(-INFINITY, 3));
  ck_assert_float_eq(s21_pow(-INFINITY, -3), pow(-INFINITY, -3));
}
END_TEST

START_TEST(nan_number) {
  ck_assert_int_eq(s21_pow(NAN, 3.346), pow(NAN, 3.346));
  ck_assert_int_eq(s21_pow(NAN, NAN), pow(NAN, NAN));
  ck_assert_int_eq(s21_pow(3.346, NAN), pow(3.346, NAN));
}
END_TEST

START_TEST(infinity_one) {
  ck_assert_float_eq(s21_pow(1, INFINITY), pow(1, INFINITY));
  ck_assert_float_eq(s21_pow(1, -INFINITY), pow(1, -INFINITY));
  ck_assert_float_eq(s21_pow(-1, INFINITY), pow(-1, INFINITY));
  ck_assert_float_eq(s21_pow(-1, -INFINITY), pow(-1, -INFINITY));
  ck_assert_float_eq(s21_pow(INFINITY, 1), pow(INFINITY, 1));
  ck_assert_float_eq(s21_pow(-INFINITY, 1), pow(-INFINITY, 1));
  ck_assert_float_eq(s21_pow(INFINITY, -1), pow(INFINITY, -1));
  ck_assert_float_eq(s21_pow(-INFINITY, -1), pow(-INFINITY, -1));
}
END_TEST

Suite *suite_pow(void) {
  Suite *s = suite_create("\033[1;31m--POW--\033[m");
  TCase *tc = tcase_create("pow_tc");

  tcase_add_test(tc, integer_number);
  tcase_add_test(tc, double_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, infinity);
  tcase_add_test(tc, nan_number);
  tcase_add_test(tc, infinity_one);

  suite_add_tcase(s, tc);

  return s;
}
