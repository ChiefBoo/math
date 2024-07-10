#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 25;
  double x2 = 5.8;
  double x3 = 0.012;
  double x4 = 2353;
  double x5 = 1;

  ck_assert_float_eq(s21_cos(x1), cos(x1));
  ck_assert_float_eq(s21_cos(x2), cos(x2));
  ck_assert_float_eq(s21_cos(x3), cos(x3));
  ck_assert_float_eq(s21_cos(x4), cos(x4));
  ck_assert_float_eq(s21_cos(x5), cos(x5));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -0.5;
  double x2 = -25;
  double x3 = -4578;
  double x4 = -1;

  ck_assert_float_eq(s21_cos(x1), cos(x1));
  ck_assert_float_eq(s21_cos(x2), cos(x2));
  ck_assert_float_eq(s21_cos(x3), cos(x3));
  ck_assert_float_eq(s21_cos(x4), cos(x4));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;
  ck_assert_float_eq(s21_cos(x), cos(x));
}
END_TEST

START_TEST(infinity_positive) {
  double x = INFINITY;

  ck_assert_int_eq(s21_cos(x), cos(x));
}
END_TEST

START_TEST(infinity_negative) {
  double x = -INFINITY;

  ck_assert_int_eq(s21_cos(x), cos(x));
}
END_TEST

START_TEST(nan_number) {
  double x = NAN;

  ck_assert_int_eq(s21_cos(x), cos(x));
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

  ck_assert_float_eq(s21_cos(x1), cos(x1));
  ck_assert_float_eq(s21_cos(x2), cos(x2));
  ck_assert_int_eq(s21_cos(x3), cos(x3));
  ck_assert_int_eq(s21_cos(x4), cos(x4));
  ck_assert_float_eq(s21_cos(x5), cos(x5));
  ck_assert_float_eq(s21_cos(x6), cos(x6));
  ck_assert_int_eq(s21_cos(x7), cos(x7));
  ck_assert_int_eq(s21_cos(x8), cos(x8));
  ck_assert_float_eq(s21_cos(x9), cos(x9));
  ck_assert_float_eq(s21_cos(x10), cos(x10));
}
END_TEST

Suite *suite_cos(void) {
  Suite *s = suite_create("\033[1;31m--COS--\033[m");
  TCase *tc = tcase_create("cos_tc");

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
