#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(strchr_test1) {
  char str[20] = "qwerty";
  ck_assert_str_eq(s21_strchr(str, 'q'), strchr(str, 'q'));
}
END_TEST
START_TEST(strchr_test2) {
  char str[20] = "qwerty";
  ck_assert_pstr_eq(s21_strchr(str, '0'), strchr(str, '0'));
}
END_TEST
START_TEST(strchr_test3) {
  char str[20] = "qwerty";
  ck_assert_str_eq(s21_strchr(str, 'e'), strchr(str, 'e'));
}
END_TEST
START_TEST(strchr_test4) {
  char str[20] = "school21";
  ck_assert_pstr_eq(s21_strchr(str, 's'), strchr(str, 's'));
}
END_TEST

int main() {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_test1);
  tcase_add_test(tc, strchr_test2);
  tcase_add_test(tc, strchr_test3);
  tcase_add_test(tc, strchr_test4);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}