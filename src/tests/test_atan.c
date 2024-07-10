#include "../test_includes/s21_tests.h"

START_TEST(zero_test) {
  double x = 0.0;

  ck_assert_float_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(close_to_zero_test) {
  double x1 = 0.000000000000000001;
  double x2 = -0.00000000000000001;

  ck_assert_float_eq(s21_atan(x1), atan(x1));
  ck_assert_float_eq(s21_atan(x2), atan(x2));
}
END_TEST

START_TEST(positive_less_than_1) {
  double x1 = 0.12345654355675678756;
  double x2 = 0.50000000000000000001;
  double x3 = 0.87654546788904335678;
  double x4 = 0.99999999999999999999;

  ck_assert_float_eq(s21_atan(x1), atan(x1));
  ck_assert_float_eq(s21_atan(x2), atan(x2));
  ck_assert_float_eq(s21_atan(x3), atan(x3));
  ck_assert_int_eq(s21_atan(x4), atan(x4));
}
END_TEST

START_TEST(negative_less_than_1) {
  double x1 = -0.12345654355675678756;
  double x2 = -0.50000000006000000008;
  double x3 = -0.78654345676543456777;
  double x4 = -0.99999999999999999999;

  ck_assert_float_eq(s21_atan(x1), atan(x1));
  ck_assert_float_eq(s21_atan(x2), atan(x2));
  ck_assert_float_eq(s21_atan(x3), atan(x3));
  ck_assert_int_eq(s21_atan(x4), atan(x4));
}
END_TEST

START_TEST(boundary_condition) {
  double x1 = 1.000000;
  double x2 = -1.000000;

  ck_assert_int_eq(s21_atan(x1), atan(x1));
  ck_assert_int_eq(s21_atan(x2), atan(x2));
}
END_TEST

START_TEST(positive_more_than_1) {
  double x1 = 1.00000000000000000001;
  double x2 = 1.5;
  double x3 = 5.87654308976567899878;
  double x4 = 10000010.1000001010001;
  double x5 = 1000001010000010100011.0;

  ck_assert_double_eq_tol(s21_atan(x1), atan(x1), 0.000001);
  ck_assert_float_eq(s21_atan(x2), atan(x2));
  ck_assert_float_eq(s21_atan(x3), atan(x3));
  ck_assert_float_eq(s21_atan(x4), atan(x4));
  ck_assert_float_eq(s21_atan(x5), atan(x5));
}
END_TEST

START_TEST(negative_more_than_1) {
  double x1 = -1.00000000000000000001;
  double x2 = -1.5;
  double x3 = -5.87654308976567899878;
  double x4 = -10000010.1000001010001;
  double x5 = -1000001010000010100011.0;

  ck_assert_double_eq_tol(s21_atan(x1), atan(x1), 0.000001);
  ck_assert_float_eq(s21_atan(x2), atan(x2));
  ck_assert_float_eq(s21_atan(x3), atan(x3));
  ck_assert_float_eq(s21_atan(x4), atan(x4));
  ck_assert_float_eq(s21_atan(x5), atan(x5));
}
END_TEST

START_TEST(inf_test) {
  ck_assert_int_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_int_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

START_TEST(nan_test) { ck_assert_int_eq(s21_atan(NAN), atan(NAN)); }
END_TEST

Suite *suite_atan(void) {
  Suite *s = suite_create("\033[1;31m--ATAN--\033[m");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, close_to_zero_test);
  tcase_add_test(tc, positive_less_than_1);
  tcase_add_test(tc, negative_less_than_1);
  tcase_add_test(tc, boundary_condition);
  tcase_add_test(tc, positive_more_than_1);
  tcase_add_test(tc, negative_more_than_1);
  tcase_add_test(tc, inf_test);
  tcase_add_test(tc, nan_test);

  suite_add_tcase(s, tc);

  return s;
}
