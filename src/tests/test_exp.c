#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 0.8;
  double x2 = 5.867;
  double x3 = 3;
  double x4 = 24;
  double x5 = 150;
  double x6 = 1;

  ck_assert_float_eq(s21_exp(x1), exp(x1));
  ck_assert_float_eq(s21_exp(x2), exp(x2));
  ck_assert_float_eq(s21_exp(x3), exp(x3));
  ck_assert_float_eq(s21_exp(x4), exp(x4));
  ck_assert_float_eq(s21_exp(x5), exp(x5));
  ck_assert_float_eq(s21_exp(x6), exp(x6));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -0.5;
  double x2 = -30;
  double x3 = -150;
  double x4 = -1;

  ck_assert_float_eq(s21_exp(x1), exp(x1));
  ck_assert_float_eq(s21_exp(x2), exp(x2));
  ck_assert_float_eq(s21_exp(x3), exp(x3));
  ck_assert_float_eq(s21_exp(x4), exp(x4));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;
  ck_assert_float_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(infinity_positive) {
  ck_assert_float_eq(s21_exp(INFINITY), exp(INFINITY));
}
END_TEST

START_TEST(infinity_negative) {
  ck_assert_float_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(nan_number) { ck_assert_int_eq(s21_exp(NAN), exp(NAN)); }
END_TEST

Suite *suite_exp(void) {
  Suite *s = suite_create("\033[1;31m--EXP--\033[m");
  TCase *tc = tcase_create("exp_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, infinity_positive);
  tcase_add_test(tc, infinity_negative);
  tcase_add_test(tc, nan_number);

  suite_add_tcase(s, tc);

  return s;
}
