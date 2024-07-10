#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 4.82536663;
  double x2 = 7;
  double x3 = 1.3;
  double x4 = 2;
  double x5 = 1;
  double x6 = s21_E;

  ck_assert_float_eq(s21_log(x1), log(x1));
  ck_assert_float_eq(s21_log(x2), log(x2));
  ck_assert_float_eq(s21_log(x3), log(x3));
  ck_assert_float_eq(s21_log(x4), log(x4));
  ck_assert_float_eq(s21_log(x5), log(x5));
  ck_assert_float_eq(s21_log(x6), log(x6));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -0.5;
  double x2 = -15;

  ck_assert_int_eq(s21_log(x1), log(x1));
  ck_assert_int_eq(s21_log(x2), log(x2));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;
  ck_assert_float_eq(s21_log(x), log(x));
}
END_TEST

START_TEST(infinity_positive) {
  ck_assert_float_eq(s21_log(INFINITY), log(INFINITY));
}
END_TEST

START_TEST(infinity_negative) {
  ck_assert_int_eq(s21_log(-INFINITY), log(-INFINITY));
}
END_TEST

START_TEST(nan_number) {
  double x = NAN;

  ck_assert_int_eq(s21_log(x), log(x));
}
END_TEST

Suite *suite_log(void) {
  Suite *s = suite_create("\033[1;31m--LOG--\033[m");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, infinity_positive);
  tcase_add_test(tc, infinity_negative);
  tcase_add_test(tc, nan_number);

  suite_add_tcase(s, tc);

  return s;
}
