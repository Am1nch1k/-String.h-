#include <check.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

START_TEST(s21_sprintf_test_percent) {
  char string1[400] = "";
  char string2[400] = "";
  int r1 = sprintf(string1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  int r2 = s21_sprintf(string2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
  char string1[100000] = "";
  char string2[100000] = "";
  short h = 34;
  int r1 = sprintf(
      string1,
      "%-25.10ld%030d%-10.12d%011d%d%d%+25d%+10.2ld %-11.5hd % d%d%d%+.5d",
      (long)-253, -335, 1234, 34, 10, 345, 666, 456789l, h, 2142, 0,
      (int)-2147483648, 12);
  int r2 = s21_sprintf(
      string2,
      "%-25.10ld%030d%-10.12d%011d%d%d%+25d%+10.2ld %-11.5hd % d%d%d%+.5d",
      (long)-253, -335, 1234, 34, 10, 345, 666, 456789l, h, 2142, 0,
      (int)-2147483648, 12);
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_d1) {
  char str1[100000] = "";
  char str2[100000] = "";
  int r1 =
      sprintf(str1, "%+-10.5f%+10.2f!%15.10f%+.10f%.16f%-10.f%25.f%25.f%.2f%.f",
              2546.4324, 3452.4325, 5678.43256, 456789.243242, 3456789123.43245,
              12345.6788, 34.4325432, 4325678.43242, 99.990, 34567.43244);
  int r2 = s21_sprintf(
      str2, "%+-10.5f%+10.2f!%15.10f%+.10f%.16f%-10.f%25.f%25.f%.2f%.f",
      2546.4324, 3452.4325, 5678.43256, 456789.243242, 3456789123.43245,
      12345.6788, 34.4325432, 4325678.43242, 99.990, 34567.43244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
  char string1[125000] = "";
  char string2[125000] = "";
  wint_t c1 = 'T', c2 = 'Z';
  int r1 =
      sprintf(string1, "[%10c][%-10c][%25c][%-30c][%25c][%c][%2c][%c]%lc%-50lc",
              'a', 'e', 'f', 'R', 'Q', 'P', 'L', 'x', c1, c2);
  int r2 = s21_sprintf(string2,
                       "[%10c][%-10c][%25c][%-30c][%25c][%c][%2c][%c]%lc%-50lc",
                       'a', 'e', 'f', 'R', 'Q', 'P', 'L', 'x', c1, c2);
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST
START_TEST(s21_sprintf_test_withoutarg) {
  char string1[125000] = "";
  char string2[125000] = "";

  int r1 = sprintf(string1, "fdkjhgslkfjhlsdjlskjfdhg; sdfgsldf");
  int r2 = s21_sprintf(string2, "fdkjhgslkfjhlsdjlskjfdhg; sdfgsldf");
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
  char string1[115000] = "";
  char string2[115000] = "";
  int r1 = sprintf(string1, "%+-10.5f!%+10.2f%15.7f %+.6f%.2f", -2546.4324,
                   -3452.245, 5678.43256, 25.0, 456789.243242);
  int r2 = s21_sprintf(string2, "%+-10.5f!%+10.2f%15.7f %+.6f%.2f", -2546.4324,
                       -3452.245, 5678.43256, 25.0, 456789.243242);
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
  char string1[117005] = "";
  char string2[117005] = "";
  unsigned short h = 115;

  int r1 = sprintf(string1, "%u%15u!%-20u%010u%20.2u %.4u!%.10u%19hu", 4321u,
                   34567u, 2342u, 12346u, 234542u, 2345u, 2432u, h);
  int r2 = s21_sprintf(string2, "%u%15u!%-20u%010u%20.2u %.4u!%.10u%19hu",
                       4321u, 34567u, 2342u, 12346u, 234542u, 2345u, 2432u, h);
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  char string1[125000] = "";
  char string2[125000] = "";
  char s[10] = {'h', 'e', 'l', 'l', 'o'};
  int r1 =
      sprintf(string1, "%-10.4s!%23s%-15s%10.4s%15.2s%16.2s%1.1s%s%15s%-10s",
              "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", "QWERTY",
              "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
  int r2 = s21_sprintf(string2,
                       "%-10.4s!%23s%-15s%10.4s%15.2s%16.2s%1.1s%s%15s%-10s",
                       "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA",
                       "QWERTY", "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
  ck_assert_str_eq(string1, string2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_sprintf_test_percent);
  tcase_add_test(tc1_1, s21_sprintf_test_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_d);
  tcase_add_test(tc1_1, s21_sprintf_test_withoutarg);

  tcase_add_test(tc1_1, s21_sprintf_test_c);

  tcase_add_test(tc1_1, s21_sprintf_test_f);

  tcase_add_test(tc1_1, s21_sprintf_test_u);
  tcase_add_test(tc1_1, s21_sprintf_test_s);

  srunner_run_all(sr, CK_VERBOSE);
  int errors = srunner_ntests_failed(sr);
  srunner_free(sr);
  return errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
