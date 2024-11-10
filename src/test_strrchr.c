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

START_TEST(test_strrchr) {
  ck_assert_str_eq(strrchr(a, 'a'), s21_strrchr(a, 'a'));
}
END_TEST
START_TEST(s21_strrchr_test_b) {
  ck_assert_str_eq(strrchr(b, 'l'), s21_strrchr(b, 'l'));
}
END_TEST
START_TEST(s21_strrchr_test_c) {
  ck_assert_str_eq(strrchr(a, ' '), s21_strrchr(a, ' '));
}
END_TEST
START_TEST(s21_strrchr_test_d) {
  ck_assert_str_eq(strrchr(a, '\0'), s21_strrchr(a, '\0'));
}
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strrchr);
  tcase_add_test(tc, s21_strrchr_test_b);
  tcase_add_test(tc, s21_strrchr_test_c);
  tcase_add_test(tc, s21_strrchr_test_d);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
