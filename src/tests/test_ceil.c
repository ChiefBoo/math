#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 8.0;
  double x2 = 32766.3765;
  double x3 = 4567854676543.9;
  double x4 = 0.0000000000001;
  double x5 = 8.5;
  double x6 = 8.4999999999999999;
  double x7 = 8.50000000000001;
  double x8 = 8.9999999999999;

  ck_assert_float_eq(s21_ceil(x1), ceil(x1));
  ck_assert_float_eq(s21_ceil(x2), ceil(x2));
  ck_assert_float_eq(s21_ceil(x3), ceil(x3));
  ck_assert_float_eq(s21_ceil(x4), ceil(x4));
  ck_assert_float_eq(s21_ceil(x5), ceil(x5));
  ck_assert_float_eq(s21_ceil(x6), ceil(x6));
  ck_assert_float_eq(s21_ceil(x7), ceil(x7));
  ck_assert_float_eq(s21_ceil(x8), ceil(x8));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -8.0;
  double x2 = -32766.3765;
  double x3 = -4567854676543.9;
  double x4 = -0.0000000000001;
  double x5 = -8.5;
  double x6 = -8.4999999999999999;
  double x7 = -8.50000000000001;
  double x8 = -8.9999999999999;

  ck_assert_float_eq(s21_ceil(x1), ceil(x1));
  ck_assert_float_eq(s21_ceil(x2), ceil(x2));
  ck_assert_float_eq(s21_ceil(x3), ceil(x3));
  ck_assert_float_eq(s21_ceil(x4), ceil(x4));
  ck_assert_float_eq(s21_ceil(x5), ceil(x5));
  ck_assert_float_eq(s21_ceil(x6), ceil(x6));
  ck_assert_float_eq(s21_ceil(x7), ceil(x7));
  ck_assert_float_eq(s21_ceil(x8), ceil(x8));
}
END_TEST

START_TEST(zero_test) {
  double x1 = 0.000;
  double x2 = -0.00;

  ck_assert_float_eq(s21_ceil(x1), ceil(x1));
  ck_assert_float_eq(s21_ceil(x2), ceil(x2));
}
END_TEST

START_TEST(inf_test) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(nan_test) { ck_assert_float_nan(s21_ceil(NAN)); }
END_TEST

Suite *suite_ceil(void) {
  Suite *s = suite_create("\033[1;31m--CEIL--\033[m");
  TCase *tc = tcase_create("ceil_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, inf_test);
  tcase_add_test(tc, nan_test);

  suite_add_tcase(s, tc);

  return s;
}
