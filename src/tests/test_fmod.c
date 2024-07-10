#include "../test_includes/s21_tests.h"

START_TEST(integer_number1) {
  ck_assert_float_eq(s21_fmod(6, 3), fmod(6, 3));
  ck_assert_float_eq(s21_fmod(-6, 3), fmod(-6, 3));
  ck_assert_float_eq(s21_fmod(6, -3), fmod(6, -3));
  ck_assert_float_eq(s21_fmod(-6, -3), fmod(-6, -3));
}
END_TEST

START_TEST(integer_number2) {
  ck_assert_float_eq(s21_fmod(8, -3), fmod(8, -3));
  ck_assert_float_eq(s21_fmod(8, 3), fmod(8, 3));
  ck_assert_float_eq(s21_fmod(-8, 3), fmod(-8, 3));
  ck_assert_float_eq(s21_fmod(-8, -3), fmod(-8, -3));
}
END_TEST

START_TEST(integer_number3) {
  ck_assert_float_eq(s21_fmod(3, 8), fmod(3, 8));
  ck_assert_float_eq(s21_fmod(-3, 8), fmod(-3, 8));
  ck_assert_float_eq(s21_fmod(-3, -8), fmod(-3, -8));
  ck_assert_float_eq(s21_fmod(3, -8), fmod(3, -8));
}
END_TEST

START_TEST(double_number1) {
  ck_assert_float_eq(s21_fmod(8.4645, -3.234), fmod(8.4645, -3.234));
  ck_assert_float_eq(s21_fmod(8.63, 3.35), fmod(8.63, 3.35));
  ck_assert_float_eq(s21_fmod(-8.242, 3.92482897), fmod(-8.242, 3.92482897));
  ck_assert_float_eq(s21_fmod(-8.2356, -3.3675), fmod(-8.2356, -3.3675));
}
END_TEST

START_TEST(double_number2) {
  ck_assert_float_eq(s21_fmod(3.214, 8.36756), fmod(3.214, 8.36756));
  ck_assert_float_eq(s21_fmod(-3.2578, 8.25), fmod(-3.2578, 8.25));
  ck_assert_float_eq(s21_fmod(-3.547, -8), fmod(-3.547, -8));
  ck_assert_float_eq(s21_fmod(3, -8.258), fmod(3, -8.258));
}
END_TEST

START_TEST(zero_test) {
  ck_assert_int_eq(s21_fmod(6.4646, 0), fmod(6.4646, 0));
  ck_assert_float_eq(s21_fmod(0.0, 235), fmod(0.0, 235));
  ck_assert_int_eq(s21_fmod(0.0, 0.0), fmod(0.0, 0.0));
}
END_TEST

START_TEST(equal_test) { ck_assert_float_eq(s21_fmod(43, 43), fmod(43, 43)); }
END_TEST

START_TEST(infinity_positive) {
  ck_assert_int_eq(s21_fmod(658.3894, INFINITY), fmod(658.3894, INFINITY));
  ck_assert_int_eq(s21_fmod(INFINITY, 658.3894), fmod(INFINITY, 658.3894));
  ck_assert_int_eq(s21_fmod(INFINITY, INFINITY), fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(infinity_negative) {
  ck_assert_int_eq(s21_fmod(658.3894, -INFINITY), fmod(658.3894, -INFINITY));
  ck_assert_int_eq(s21_fmod(-INFINITY, 658.3894), fmod(-INFINITY, 658.3894));
  ck_assert_int_eq(s21_fmod(-INFINITY, -INFINITY), fmod(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(infinity) {
  ck_assert_int_eq(s21_fmod(INFINITY, -INFINITY), fmod(INFINITY, -INFINITY));
  ck_assert_int_eq(s21_fmod(-INFINITY, INFINITY), fmod(-INFINITY, INFINITY));
}
END_TEST

START_TEST(nan_number) {
  ck_assert_int_eq(s21_fmod(NAN, 3.346), fmod(NAN, 3.346));
  ck_assert_int_eq(s21_fmod(3.346, NAN), fmod(3.346, NAN));
  ck_assert_int_eq(s21_fmod(NAN, NAN), fmod(NAN, NAN));
}
END_TEST

Suite *suite_fmod(void) {
  Suite *s = suite_create("\033[1;31m--FMOD--\033[m");
  TCase *tc = tcase_create("fmod_tc");

  tcase_add_test(tc, integer_number1);
  tcase_add_test(tc, integer_number2);
  tcase_add_test(tc, integer_number3);
  tcase_add_test(tc, double_number1);
  tcase_add_test(tc, double_number2);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, equal_test);
  tcase_add_test(tc, infinity_positive);
  tcase_add_test(tc, infinity_negative);
  tcase_add_test(tc, infinity);
  tcase_add_test(tc, nan_number);

  suite_add_tcase(s, tc);

  return s;
}
