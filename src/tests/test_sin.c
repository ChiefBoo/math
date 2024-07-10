#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 25;
  double x2 = 5.8;
  double x3 = 0.012;
  double x4 = 2353;
  double x5 = 1;

  ck_assert_float_eq(s21_sin(x1), sin(x1));
  ck_assert_float_eq(s21_sin(x2), sin(x2));
  ck_assert_float_eq(s21_sin(x3), sin(x3));
  ck_assert_float_eq(s21_sin(x4), sin(x4));
  ck_assert_float_eq(s21_sin(x5), sin(x5));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -0.5;
  double x2 = -25;
  double x3 = -4578;
  double x4 = -1;

  ck_assert_float_eq(s21_sin(x1), sin(x1));
  ck_assert_float_eq(s21_sin(x2), sin(x2));
  ck_assert_float_eq(s21_sin(x3), sin(x3));
  ck_assert_float_eq(s21_sin(x4), sin(x4));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;
  ck_assert_float_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(infinity_positive) {
  double x = INFINITY;

  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(infinity_negative) {
  double x = -INFINITY;

  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(nan_number) {
  double x = NAN;

  ck_assert_int_eq(s21_sin(x), sin(x));
}
END_TEST

START_TEST(pi_test) {
  double x1 = s21_PI;
  double x2 = -s21_PI;
  double x3 = s21_PI / 2;
  double x4 = -s21_PI / 2;
  double x5 = 2 * s21_PI;
  double x6 = -2 * s21_PI;
  double x7 = 3 * s21_PI / 2;
  double x8 = 3 * s21_PI / 2;
  double x9 = s21_PI / 3;
  double x10 = 5 * s21_PI / 6;

  ck_assert_int_eq(s21_sin(x1), sin(x1));
  ck_assert_int_eq(s21_sin(x2), sin(x2));
  ck_assert_float_eq(s21_sin(x3), sin(x3));
  ck_assert_float_eq(s21_sin(x4), sin(x4));
  ck_assert_int_eq(s21_sin(x5), sin(x5));
  ck_assert_int_eq(s21_sin(x6), sin(x6));
  ck_assert_float_eq(s21_sin(x7), sin(x7));
  ck_assert_float_eq(s21_sin(x8), sin(x8));
  ck_assert_float_eq(s21_sin(x9), sin(x9));
  ck_assert_float_eq(s21_sin(x10), sin(x10));
}
END_TEST

Suite *suite_sin(void) {
  Suite *s = suite_create("\033[1;31m--SIN--\033[m");
  TCase *tc = tcase_create("sin_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, infinity_positive);
  tcase_add_test(tc, infinity_negative);
  tcase_add_test(tc, nan_number);
  tcase_add_test(tc, pi_test);
  suite_add_tcase(s, tc);

  return s;
}
