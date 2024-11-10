#include <check.h>
#include <string.h>

#include "s21_string.h"
const char a[] = "ERUNDA tra ta ta TRI ra ry da";
const char b[] = "Hello world\n\0";
const char c[] = "d\n\0";
const char d[] = " \n\0";
const char e[] = " \0";
const char f[] = "\n\0";
const char g[] = "\0";
const char h[] = "tra";
const char i[] = "world";

START_TEST(test_strstr) { ck_assert_str_eq(strstr(a, h), s21_strstr(a, h)); }
END_TEST
START_TEST(s21_strstr_test_b) { ck_assert(s21_strstr(b, d) == NULL); }
END_TEST
START_TEST(s21_strstr_test_c) {
  ck_assert_str_eq(strstr(b, i), s21_strstr(b, i));
}
END_TEST
START_TEST(s21_strstr_test_d) {
  ck_assert_str_eq(strstr("aa\naa\n\0", "\n"), s21_strstr("aa\naa\n\0", "\n"));
}
START_TEST(s21_strstr_test_e) {
  ck_assert_str_eq(strstr(b, e), s21_strstr(b, e));
}
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strstr);
  tcase_add_test(tc, s21_strstr_test_b);
  tcase_add_test(tc, s21_strstr_test_c);
  tcase_add_test(tc, s21_strstr_test_d);
  tcase_add_test(tc, s21_strstr_test_e);

  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
