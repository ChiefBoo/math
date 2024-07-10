#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 25;
  double x2 = 5.8;
  double x3 = 0.012;
  double x4 = 235357;
  double x5 = 1;

  ck_assert_float_eq(s21_sqrt(x1), sqrt(x1));
  ck_assert_float_eq(s21_sqrt(x2), sqrt(x2));
  ck_assert_float_eq(s21_sqrt(x3), sqrt(x3));
  ck_assert_float_eq(s21_sqrt(x4), sqrt(x4));
  ck_assert_float_eq(s21_sqrt(x5), sqrt(x5));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -0.5;
  double x2 = -25;
  double x3 = -457875;

  ck_assert_int_eq(s21_sqrt(x1), sqrt(x1));
  ck_assert_int_eq(s21_sqrt(x2), sqrt(x2));
  ck_assert_int_eq(s21_sqrt(x3), sqrt(x3));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;
  ck_assert_float_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(infinity_positive) {
  double x = INFINITY;
  ck_assert_float_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(infinity_negative) {
  double x = -INFINITY;
  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

START_TEST(nan_number) {
  double x = NAN;

  ck_assert_int_eq(s21_sqrt(x), sqrt(x));
}
END_TEST

Suite *suite_sqrt(void) {
  Suite *s = suite_create("\033[1;31m--SQRT--\033[m");
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
