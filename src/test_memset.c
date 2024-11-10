#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(memset_test1) {
  char str[20] = "School";
  ck_assert_pstr_eq(s21_memset(str, 'q', 3), memset(str, 'q', 3));
}
END_TEST
START_TEST(memset_test2) {
  char str[20] = "School";
  ck_assert_pstr_eq(s21_memset(str, 'c', 4), memset(str, 'c', 4));
}
END_TEST
START_TEST(memset_test3) {
  char str[20] = "";
  ck_assert_pstr_eq(s21_memset(str, 'c', 4), memset(str, 'c', 4));
}
END_TEST
START_TEST(memset_test4) {
  char str[20] = "\0";
  ck_assert_pstr_eq(s21_memset(str, 'c', 4), memset(str, 'c', 4));
}
END_TEST

int main() {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, memset_test1);
  tcase_add_test(tc, memset_test2);
  tcase_add_test(tc, memset_test3);
  tcase_add_test(tc, memset_test4);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}