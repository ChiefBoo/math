#include "../test_includes/s21_tests.h"

START_TEST(positive_number) {
  int x1 = 8;
  int x2 = 32766;

  ck_assert_int_eq(s21_abs(x1), abs(x1));
  ck_assert_int_eq(s21_abs(x2), abs(x2));
}
END_TEST

START_TEST(negative_number) {
  int x1 = -1999;
  int x2 = -32766;

  ck_assert_int_eq(s21_abs(x1), abs(x1));
  ck_assert_int_eq(s21_abs(x2), abs(x2));
}
END_TEST

START_TEST(zero_test) {
  int x1 = 0;
  int x2 = -0;

  ck_assert_int_eq(s21_abs(x1), abs(x1));
  ck_assert_int_eq(s21_abs(x2), abs(x2));
}
END_TEST

Suite *suite_abs(void) {
  Suite *s = suite_create("\033[1;31m--ABS--\033[m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, positive_number);
  tcase_add_test(tc, negative_number);
  tcase_add_test(tc, zero_test);

  suite_add_tcase(s, tc);

  return s;
}
