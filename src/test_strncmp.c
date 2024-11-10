/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test_strncmp.check" instead.
 */

#include <check.h>
#include <string.h>

#include "s21_string.h"

const char a[] = "Lorem ipsum dolor sit amet";
const char b[] = "Lrem Hello ipsum dolor sit amet";
const char c[] = "Lorem ipsum dolor  amet";
const char d[] = "Lorem ipsum cat dolor sit amet";
const char e[] = "dolor sit amet";
const char f[] = "Lorem ipsum dolor sit amet";
const char g[] = "Lorem upsum dolor sit amet";

START_TEST(strncmp1) {
  char str1[20] = "Hello, world!";
  char str2[20] = "Hello, world!";
  int n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp2) {
  char str2[100] = "ERUND tra ta ta TRI ra ry da";
  ck_assert_int_eq(strncmp(a, str2, 6), s21_strncmp(a, str2, 6));
}
END_TEST

START_TEST(strncmp3) {
  ck_assert_int_eq(strncmp(a, b, 5), s21_strncmp(a, b, 5));
}
END_TEST

START_TEST(strncmp4) {
  ck_assert_int_eq(strncmp(a, f, 12), s21_strncmp(a, f, 12));
}
END_TEST

START_TEST(strncmp5) {
  ck_assert_int_eq(strncmp(a, c, 20), s21_strncmp(a, c, 20));
}
END_TEST

START_TEST(strncmp6) {
  ck_assert_int_eq(strncmp(a, d, 20), s21_strncmp(a, d, 20));
}
END_TEST

START_TEST(strncmp7) {
  ck_assert_int_eq(strncmp(a, e, 20), s21_strncmp(a, e, 20));
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strncmp1);
  tcase_add_test(tc1_1, strncmp2);
  tcase_add_test(tc1_1, strncmp3);
  tcase_add_test(tc1_1, strncmp4);
  tcase_add_test(tc1_1, strncmp5);
  tcase_add_test(tc1_1, strncmp6);
  tcase_add_test(tc1_1, strncmp7);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}