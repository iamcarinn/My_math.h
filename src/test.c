#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  ck_assert_int_eq(abs(-73645), s21_abs(-73645));
  ck_assert_int_eq(abs(73645), s21_abs(73645));
  ck_assert_int_eq(abs(73645 / 6), s21_abs(73645 / 6));
  ck_assert_int_eq(abs(-73645 / 6), s21_abs(-73645 / 6));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(-0), s21_abs(-0));
  ck_assert_int_eq(abs(234743587), s21_abs(234743587));
  ck_assert_int_eq(abs(-234743587), s21_abs(-234743587));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq_tol(fabs(32.41), s21_fabs(32.41), 1e-6);
  ck_assert_double_eq_tol(fabs(-0.7), s21_fabs(-0.7), 1e-6);
  ck_assert_double_eq_tol(fabs(-1e-6), s21_fabs(-1e-6), 1e-6);
  ck_assert_double_eq(fabs(-s21_INF), s21_fabs(-s21_INF));
  ck_assert_double_eq(fabs(s21_INF), s21_fabs(s21_INF));
  ck_assert_double_nan(s21_fabs(-s21_NAN));
  ck_assert_double_eq_tol(fabs(0.0), s21_fabs(0.0), 1e-6);
  ck_assert_double_eq_tol(fabs(-0.0), s21_fabs(-0.0), 1e-6);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_double_eq_tol(fmod(3.5, 1.1), s21_fmod(3.5, 1.1), 1e-6);
  ck_assert_double_eq_tol(fmod(-3.5, 1.1), s21_fmod(-3.5, 1.1), 1e-6);
  ck_assert_double_eq_tol(fmod(576848.84848, 1.1), s21_fmod(576848.84848, 1.1),
                          1e-6);
  ck_assert_double_eq_tol(fmod(-0.000001, 0.2), s21_fmod(-0.000001, 0.2), 1e-6);
  ck_assert_double_eq_tol(fmod(0.908364, 6.4332), s21_fmod(0.908364, 6.4332),
                          1e-6);
  ck_assert_double_eq_tol(fmod(-163682, -76.1), s21_fmod(-163682, -76.1), 1e-6);
  ck_assert_double_eq(fmod(4, s21_INF), s21_fmod(4, s21_INF));
  ck_assert_double_eq(fmod(4, -s21_INF), s21_fmod(4, -s21_INF));
  ck_assert_double_nan(s21_fmod(4.6, 0));
  ck_assert_double_nan(s21_fmod(2, s21_NAN));
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq_tol(floor(10.78354689), s21_floor(10.78354689), 1e-6);
  ck_assert_double_eq_tol(floor(-11193.89436), s21_floor(-11193.89436), 1e-6);
  ck_assert_double_eq_tol(floor(9.34), s21_floor(9.34), 1e-6);
  ck_assert_double_eq_tol(floor(7), s21_floor(7), 1e-6);
  ck_assert_double_eq_tol(floor(-8.511), s21_floor(-8.511), 1e-6);
  ck_assert_double_eq_tol(floor(-0.511), s21_floor(-0.511), 1e-6);
  ck_assert_double_eq_tol(floor(0.555553223), s21_floor(0.555553223), 1e-6);
  ck_assert_double_eq(floor(s21_INF), s21_floor(s21_INF));
  ck_assert_double_eq(floor(-s21_INF), s21_floor(-s21_INF));
  ck_assert_double_nan(s21_floor(s21_NAN));
  ck_assert_double_nan(s21_floor(-s21_NAN));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq_tol(ceil(20.7777777), s21_ceil(20.7777777), 1e-6);
  ck_assert_double_eq_tol(ceil(-20435.99436), s21_ceil(-20435.99436), 1e-6);
  ck_assert_double_eq_tol(ceil(9.35), s21_ceil(9.35), 1e-6);
  ck_assert_double_eq_tol(ceil(-6.559), s21_ceil(-6.559), 1e-6);
  ck_assert_double_eq_tol(ceil(-0.559), s21_ceil(-0.559), 1e-6);
  ck_assert_double_eq_tol(ceil(0.555554423), s21_ceil(0.555554423), 1e-6);
  ck_assert_double_eq(ceil(s21_INF), s21_ceil(s21_INF));
  ck_assert_double_eq(ceil(-s21_INF), s21_ceil(-s21_INF));
  ck_assert_double_nan(s21_ceil(s21_NAN));
  ck_assert_double_nan(s21_ceil(-s21_NAN));
}
END_TEST

START_TEST(test_pow) {
  ck_assert_double_eq_tol(pow(11, 3), s21_pow(11, 3), 1e-6);
  ck_assert_double_eq_tol(pow(11, 0), s21_pow(11, 0), 1e-6);
  ck_assert_double_eq_tol(pow(0, 11), s21_pow(0, 11), 1e-6);
  ck_assert_double_eq_tol(pow(0, 0), s21_pow(0, 0), 1e-6);
  ck_assert_double_eq_tol(pow(42, 0.6), s21_pow(42, 0.6), 1e-6);
  ck_assert_double_nan(s21_pow(-32, 0.6));
  ck_assert_double_eq_tol(pow(8.5, 3), s21_pow(8.5, 3), 1e-6);
  ck_assert_double_eq_tol(pow(8.5, -3), s21_pow(8.5, -3), 1e-6);
  ck_assert_double_eq_tol(pow(-8.5, -3), s21_pow(-8.5, -3), 1e-6);
  ck_assert_double_eq_tol(pow(8.3, 6.4), s21_pow(8.3, 6.4), 1e-6);
  ck_assert_double_eq(pow(s21_INF, 4.4), s21_pow(s21_INF, 4.4));
  ck_assert_double_eq(pow(1, s21_INF), s21_pow(1, s21_INF));
  ck_assert_double_eq(pow(0, s21_INF), s21_pow(0, s21_INF));
  ck_assert_double_eq(pow(s21_INF, 0), s21_pow(s21_INF, 0));
  ck_assert_double_eq(pow(5, -s21_INF), s21_pow(5, -s21_INF));
  ck_assert_double_eq(pow(s21_INF, s21_INF), s21_pow(s21_INF, s21_INF));
  ck_assert_double_eq(pow(-s21_INF, 2), s21_pow(-s21_INF, 2));
  ck_assert_double_eq(pow(-s21_INF, 3), s21_pow(-s21_INF, 3));
  ck_assert_double_nan(s21_pow(s21_NAN, 6));
  ck_assert_double_nan(s21_pow(7.637, s21_NAN));
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_double_eq_tol(sqrt(265434.345323), s21_sqrt(265434.345323), 1e-6);
  ck_assert_double_eq_tol(sqrt(20.543678), s21_sqrt(20.543678), 1e-6);
  ck_assert_double_nan(s21_sqrt(-0.98323));
  ck_assert_double_nan(s21_sqrt(-1e-6));
  ck_assert_double_eq_tol(sqrt(1e-6), s21_sqrt(1e-6), 1e-6);
  ck_assert_double_nan(s21_sqrt(-s21_INF));
  ck_assert_double_eq(sqrt(s21_INF), s21_sqrt(s21_INF));
  ck_assert_double_nan(s21_sqrt(-s21_NAN));
  ck_assert_double_eq_tol(sqrt(0.0), s21_sqrt(0.0), 1e-6);

  ck_assert_double_eq_tol(sqrt(256), s21_sqrt(256), 1e-6);
  for (double i = 0; i <= 1000; i += 4) {
    ck_assert_ldouble_eq_tol(sqrt(i), s21_sqrt(i), 1e-6);
  }
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_eq_tol(log(265434.345323), s21_log(265434.345323), 1e-6);
  ck_assert_double_eq_tol(log(20.543678), s21_log(20.543678), 1e-6);
  ck_assert_double_nan(s21_log(-0.92323));
  ck_assert_double_nan(s21_log(-1e-6));
  ck_assert_double_eq_tol(log(1e-6), s21_log(1e-6), 1e-6);
  ck_assert_double_nan(s21_log(-s21_INF));
  ck_assert_double_eq(log(s21_INF), s21_log(s21_INF));
  ck_assert_double_nan(s21_log(-s21_NAN));
  ck_assert_double_eq(log(0.0), s21_log(0.0));
  ck_assert_double_eq(log(-0.0), s21_log(-0.0));
  ck_assert_double_eq_tol(log(256), s21_log(256), 1e-6);
  for (double i = 1; i <= 1000; i += 4) {
    ck_assert_ldouble_eq_tol(log(i), s21_log(i), 1e-6);
  }
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_eq_tol(exp(0), s21_exp(0), 1e-6);
  ck_assert_double_eq_tol(exp(1.0), s21_exp(1.0), 1e-6);
  ck_assert_double_eq_tol(exp(-1.0), s21_exp(-1.0), 1e-6);
  ck_assert_double_eq_tol(exp(0.4567893), s21_exp(0.4567893), 1e-6);
  ck_assert_double_eq_tol(exp(20), s21_exp(20), 1e-6);
  ck_assert_double_eq_tol(exp(-20), s21_exp(-20), 1e-6);
  ck_assert_double_eq(exp(s21_INF), s21_exp(s21_INF));
  ck_assert_double_eq(exp(-s21_INF), s21_exp(-s21_INF));
  ck_assert_double_nan(s21_exp(-s21_NAN));
  ck_assert_double_nan(s21_exp(s21_NAN));
  ck_assert_double_eq_tol(exp(-37.3568893), s21_exp(-37.3568893), 1e-6);
  ck_assert_double_eq_tol(exp(-241), s21_exp(-241), 1e-6);
  ck_assert_double_eq_tol(exp(27.3568893), s21_exp(27.3568893), 1e-6);  //
  ck_assert_double_eq_tol(exp(51), s21_exp(51), 1e-6);
  for (double i = -20; i < 20; i += 0.1)
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), 1e-6);
}
END_TEST

START_TEST(test_atan) {
  ck_assert_double_eq_tol(atan(0), s21_atan(0), 1e-6);
  ck_assert_double_eq_tol(atan(1), s21_atan(1), 1e-6);
  ck_assert_double_eq_tol(atan(-1), s21_atan(-1), 1e-6);
  ck_assert_double_eq_tol(atan(s21_PI / 2), s21_atan(s21_PI / 2), 1e-6);
  ck_assert_double_eq_tol(atan(-s21_PI / 2), s21_atan(-s21_PI / 2), 1e-6);
  ck_assert_double_eq_tol(atan(475), s21_atan(475), 1e-6);
  ck_assert_double_eq_tol(atan(-475), s21_atan(-475), 1e-6);
  ck_assert_double_eq_tol(atan(475.758), s21_atan(475.758), 1e-6);
  ck_assert_double_eq_tol(atan(-475.758), s21_atan(-475.758), 1e-6);
  ck_assert_double_eq_tol(atan(0.475), s21_atan(0.475), 1e-6);
  ck_assert_double_eq_tol(atan(-0.475), s21_atan(-0.475), 1e-6);
  ck_assert_double_eq_tol(atan(1e-6), s21_atan(1e-6), 1e-6);
  ck_assert_double_eq_tol(atan(-1e-6), s21_atan(-1e-6), 1e-6);
  ck_assert_double_eq_tol(atan(s21_INF), s21_atan(s21_INF), 1e-6);
  ck_assert_double_eq_tol(atan(-s21_INF), s21_atan(-s21_INF), 1e-6);
  ck_assert_double_nan(s21_atan(s21_NAN));
}
END_TEST

START_TEST(test_asin) {
  ck_assert_double_eq_tol(asin(0), s21_asin(0), 1e-6);
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-6);
  ck_assert_double_eq_tol(asin(0.475), s21_asin(0.475), 1e-6);
  ck_assert_double_eq_tol(asin(-0.475), s21_asin(-0.475), 1e-6);
  ck_assert_double_eq_tol(asin(-0.9999999), s21_asin(-0.9999999), 1e-6);
  ck_assert_double_eq_tol(asin(0.9999999), s21_asin(0.9999999), 1e-6);
  ck_assert_double_eq_tol(asin(1e-6), s21_asin(1e-6), 1e-6);
  ck_assert_double_eq_tol(asin(-1e-6), s21_asin(-1e-6), 1e-6);
  ck_assert_double_nan(s21_asin(7));
  ck_assert_double_nan(s21_asin(-7));
  ck_assert_double_nan(s21_asin(s21_INF));
  ck_assert_double_nan(s21_asin(-s21_INF));
  ck_assert_double_nan(s21_asin(s21_NAN));
  ck_assert_double_eq_tol(asin(0.7071067811865475244),
                          s21_asin(0.7071067811865475244), 1e-6);
  ck_assert_double_eq_tol(asin(-0.7071067811865475244),
                          s21_asin(-0.7071067811865475244), 1e-6);
  for (double i = -1; i <= 1; i += 0.1) {
    ck_assert_ldouble_eq_tol(asin(i), s21_asin(i), 1e-6);
  }
}
END_TEST

START_TEST(test_acos) {
  ck_assert_double_eq_tol(acos(0), s21_acos(0), 1e-6);
  ck_assert_double_eq_tol(acos(1), s21_acos(1), 1e-6);
  ck_assert_double_eq_tol(acos(0.475), s21_acos(0.475), 1e-6);
  ck_assert_double_eq_tol(acos(-0.475), s21_acos(-0.475), 1e-6);
  ck_assert_double_eq_tol(acos(-0.9999999), s21_acos(-0.9999999), 1e-6);
  ck_assert_double_eq_tol(acos(0.9999999), s21_acos(0.9999999), 1e-6);
  ck_assert_double_eq_tol(acos(1e-6), s21_acos(1e-6), 1e-6);
  ck_assert_double_eq_tol(acos(-1e-6), s21_acos(-1e-6), 1e-6);
  ck_assert_double_nan(s21_acos(7));
  ck_assert_double_nan(s21_acos(-7));
  ck_assert_double_nan(s21_acos(s21_INF));
  ck_assert_double_nan(s21_acos(-s21_INF));
  ck_assert_double_nan(s21_acos(s21_NAN));
  ck_assert_double_eq_tol(acos(0.7071067811865475244),
                          s21_acos(0.7071067811865475244), 1e-6);
  ck_assert_double_eq_tol(acos(-0.7071067811865475244),
                          s21_acos(-0.7071067811865475244), 1e-6);
  for (double i = -1; i <= 1; i += 0.1) {
    ck_assert_ldouble_eq_tol(acos(i), s21_acos(i), 1e-6);
  }
}
END_TEST

START_TEST(test_sin) {
  ck_assert_double_eq_tol(sin(0), s21_sin(0), 1e-6);
  ck_assert_double_eq_tol(sin(1), s21_sin(1), 1e-6);
  ck_assert_double_eq_tol(sin(3 * s21_PI / 18), s21_sin(3 * s21_PI / 18), 1e-6);
  ck_assert_double_eq_tol(sin(6 * s21_PI / 36), s21_sin(6 * s21_PI / 36), 1e-6);
  ck_assert_double_eq_tol(sin(-s21_PI / 360), s21_sin(-s21_PI / 360), 1e-6);
  ck_assert_double_eq_tol(sin(s21_PI / 6), s21_sin(s21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(sin(s21_TWO_PI), s21_sin(s21_TWO_PI), 1e-6);
  ck_assert_double_eq_tol(sin(1e-6), s21_sin(1e-6), 1e-6);
  ck_assert_double_eq_tol(sin(-1e-6), s21_sin(-1e-6), 1e-6);
  ck_assert_double_nan(s21_sin(s21_INF));
  ck_assert_double_nan(s21_sin(-s21_INF));
  ck_assert_double_nan(s21_sin(s21_NAN));
  for (double i = -100; i <= 100; i += 0.001) {
    ck_assert_ldouble_eq_tol(sin(i), s21_sin(i), 1e-6);
  }
  ck_assert_double_eq_tol(sin(-2435.6578), s21_sin(-2435.6578), 1e-6);
  ck_assert_double_eq_tol(sin(38456.9174678), s21_sin(38456.9174678), 1e-6);
}
END_TEST

START_TEST(test_cos) {
  ck_assert_double_eq_tol(cos(0), s21_cos(0), 1e-6);
  ck_assert_double_eq_tol(cos(1), s21_cos(1), 1e-6);
  ck_assert_double_eq_tol(cos(3 * s21_PI / 18), s21_cos(3 * s21_PI / 18), 1e-6);
  ck_assert_double_eq_tol(cos(6 * s21_PI / 360), s21_cos(6 * s21_PI / 360),
                          1e-6);
  ck_assert_double_eq_tol(cos(-s21_PI / 360), s21_cos(-s21_PI / 360), 1e-6);
  ck_assert_double_eq_tol(cos(s21_PI / 6), s21_cos(s21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(cos(s21_TWO_PI), s21_cos(s21_TWO_PI), 1e-6);
  ck_assert_double_eq_tol(cos(1e-6), s21_cos(1e-6), 1e-6);
  ck_assert_double_eq_tol(cos(-1e-6), s21_cos(-1e-6), 1e-6);
  ck_assert_double_nan(s21_cos(s21_INF));
  ck_assert_double_nan(s21_cos(-s21_INF));
  ck_assert_double_nan(s21_cos(s21_NAN));
  for (double i = -100; i <= 100; i += 0.001) {
    ck_assert_ldouble_eq_tol(cos(i), s21_cos(i), 1e-6);
  }
  ck_assert_double_eq_tol(cos(-2435.6578), s21_cos(-2435.6578), 1e-6);
  ck_assert_double_eq_tol(cos(38456.9174678), s21_cos(38456.9174678), 1e-6);
}
END_TEST

START_TEST(test_tan) {
  ck_assert_double_eq_tol(tan(0), s21_tan(0), 1e-6);
  ck_assert_double_eq_tol(tan(1), s21_tan(1), 1e-6);
  ck_assert_double_eq_tol(tan(s21_PI / 3), s21_tan(s21_PI / 3), 1e-6);
  ck_assert_double_eq_tol(tan(s21_PI / 4), s21_tan(s21_PI / 4), 1e-6);
  ck_assert_double_eq_tol(tan(s21_PI / 5), s21_tan(s21_PI / 5), 1e-6);
  ck_assert_double_eq_tol(tan(s21_PI / 6), s21_tan(s21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(tan(-s21_PI / 3), s21_tan(-s21_PI / 3), 1e-6);
  ck_assert_double_eq_tol(tan(-s21_PI / 4), s21_tan(-s21_PI / 4), 1e-6);
  ck_assert_double_eq_tol(tan(-s21_PI / 5), s21_tan(-s21_PI / 5), 1e-6);
  ck_assert_double_eq_tol(tan(-s21_PI / 6), s21_tan(-s21_PI / 6), 1e-6);
  ck_assert_double_eq_tol(tan(-s21_PI / 360), s21_tan(-s21_PI / 360), 1e-6);
  ck_assert_double_eq_tol(tan(s21_TWO_PI), s21_tan(s21_TWO_PI), 1e-6);
  ck_assert_double_eq_tol(tan(1e-6), s21_tan(1e-6), 1e-6);
  ck_assert_double_eq_tol(tan(-1e-6), s21_tan(-1e-6), 1e-6);
  ck_assert_double_nan(s21_tan(s21_INF));
  ck_assert_double_nan(s21_tan(-s21_INF));
  ck_assert_double_nan(s21_tan(s21_NAN));
  for (double i = -100; i <= 100; i += 0.01) {
    ck_assert_ldouble_eq_tol(tan(i), s21_tan(i), 1e-6);
  }
  ck_assert_double_eq_tol(tan(-2435.6578), s21_tan(-2435.6578), 1e-6);
  ck_assert_double_eq_tol(tan(38456.9174678), s21_tan(38456.9174678), 1e-6);
}
END_TEST

Suite *math_suite(void) {
  Suite *s = suite_create("Math_testcase");
  TCase *tc_math = tcase_create("Core");
  tcase_add_test(tc_math, test_abs);
  tcase_add_test(tc_math, test_fmod);
  tcase_add_test(tc_math, test_sqrt);
  tcase_add_test(tc_math, test_fabs);
  tcase_add_test(tc_math, test_floor);
  tcase_add_test(tc_math, test_ceil);
  tcase_add_test(tc_math, test_exp);
  tcase_add_test(tc_math, test_sin);
  tcase_add_test(tc_math, test_cos);
  tcase_add_test(tc_math, test_tan);
  tcase_add_test(tc_math, test_pow);
  tcase_add_test(tc_math, test_log);
  tcase_add_test(tc_math, test_atan);
  tcase_add_test(tc_math, test_acos);
  tcase_add_test(tc_math, test_asin);
  suite_add_tcase(s, tc_math);
  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = math_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
