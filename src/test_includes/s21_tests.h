#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../s21_math.h"

Suite *suite_abs(void);
Suite *suite_acos(void);
Suite *suite_asin(void);
Suite *suite_atan(void);
Suite *suite_ceil(void);
Suite *suite_cos(void);
Suite *suite_exp(void);
Suite *suite_fabs(void);

Suite *suite_floor(void);
Suite *suite_fmod(void);
Suite *suite_pow(void);
Suite *suite_log(void);
Suite *suite_sqrt(void);
Suite *suite_sin(void);
Suite *suite_tan(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_
