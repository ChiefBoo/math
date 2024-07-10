#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  double x1 = 3;
  double x2 = 4.82536663;
  double x3 = 4.235357;

  ck_assert_float_eq(s21_floor(x1), floor(x1));
  ck_assert_float_eq(s21_floor(x2), floor(x2));
  ck_assert_float_eq(s21_floor(x3), floor(x3));
}
END_TEST

START_TEST(negative_number) {
  double x1 = -3;
  double x2 = -15.7855;
  double x3 = -15.346;

  ck_assert_float_eq(s21_floor(x1), floor(x1));
  ck_assert_float_eq(s21_floor(x2), floor(x2));
  ck_assert_float_eq(s21_floor(x3), floor(x3));
}
END_TEST

START_TEST(zero_test) {
  double x = 0;

  ck_assert_float_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(infinity_positive) {
  double x = INFINITY;

  ck_assert_float_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(infinity_negative) {
  double x = -INFINITY;

  ck_assert_float_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(nan_number) {
  double x = NAN;

  ck_assert_int_eq(s21_floor(x), floor(x));
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("\033[1;31m--FLOOR--\033[m");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, infinity_positive);
  tcase_add_test(tc, infinity_negative);
  tcase_add_test(tc, nan_number);

  suite_add_tcase(s, tc);

  return s;
}
