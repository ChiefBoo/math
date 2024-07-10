#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 25;
  double x2 = 5.8;
  double x3 = 0.012;
  double x4 = 2353;
  double x5 = 1;

  ck_assert_float_eq(s21_tan(x1), tan(x1));
  ck_assert_float_eq(s21_tan(x2), tan(x2));
  ck_assert_float_eq(s21_tan(x3), tan(x3));
  ck_assert_float_eq(s21_tan(x4), tan(x4));
  ck_assert_float_eq(s21_tan(x5), tan(x5));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -0.5;
  double x2 = -25;
  double x3 = -4578;
  double x4 = -1;

  ck_assert_float_eq(s21_tan(x1), tan(x1));
  ck_assert_float_eq(s21_tan(x2), tan(x2));
  ck_assert_float_eq(s21_tan(x3), tan(x3));
  ck_assert_float_eq(s21_tan(x4), tan(x4));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;
  ck_assert_float_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(infinity_positive) {
  double x = INFINITY;

  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(infinity_negative) {
  double x = -INFINITY;

  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(nan_number) {
  double x = NAN;

  ck_assert_int_eq(s21_tan(x), tan(x));
}
END_TEST

START_TEST(pi_test) {
  double x1 = s21_PI;
  double x2 = -s21_PI;
  double x3 = 2 * s21_PI;
  double x4 = -2 * s21_PI;
  double x5 = s21_PI / 3;
  double x6 = 5 * s21_PI / 6;

  ck_assert_int_eq(s21_tan(x1), tan(x1));
  ck_assert_int_eq(s21_tan(x2), tan(x2));
  ck_assert_int_eq(s21_tan(x3), tan(x3));
  ck_assert_int_eq(s21_tan(x4), tan(x4));
  ck_assert_float_eq(s21_tan(x5), tan(x5));
  ck_assert_float_eq(s21_tan(x6), tan(x6));
}
END_TEST

Suite *suite_tan(void) {
  Suite *s = suite_create("\033[1;31m--TAN--\033[m");
  TCase *tc = tcase_create("tan_tc");

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
