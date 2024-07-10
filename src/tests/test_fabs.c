#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 8.0;
  double x2 = 32766.8765;
  double x3 = 4567854676543.9;
  double x4 = 0.0000000000001;

  ck_assert_float_eq(s21_fabs(x1), fabs(x1));
  ck_assert_float_eq(s21_fabs(x2), fabs(x2));
  ck_assert_float_eq(s21_fabs(x3), fabs(x3));
  ck_assert_float_eq(s21_fabs(x4), fabs(x4));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -8.0;
  double x2 = -32766.8765;
  double x3 = -4567854676543.9;
  double x4 = -0.0000000000001;

  ck_assert_float_eq(s21_fabs(x1), fabs(x1));
  ck_assert_float_eq(s21_fabs(x2), fabs(x2));
  ck_assert_float_eq(s21_fabs(x3), fabs(x3));
  ck_assert_float_eq(s21_fabs(x4), fabs(x4));
}
END_TEST

START_TEST(zero_test) {
  double x1 = 0.000;
  double x2 = -0.00;

  ck_assert_float_eq(s21_fabs(x1), fabs(x1));
  ck_assert_float_eq(s21_fabs(x2), fabs(x2));
}
END_TEST

START_TEST(inf_test) {
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(nan_test) { ck_assert_float_nan(s21_fabs(NAN)); }
END_TEST

Suite *suite_fabs(void) {
  Suite *s = suite_create("\033[1;31m--FABS--\033[m");
  TCase *tc = tcase_create("fabs_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, inf_test);
  tcase_add_test(tc, nan_test);
  suite_add_tcase(s, tc);

  return s;
}
