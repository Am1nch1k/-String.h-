#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(strcat_test1) {
  char str1[20] = "School";
  char str2[20] = " 21";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 5), strncat(str1, str2, 5));
}
END_TEST
START_TEST(strcat_test2) {
  char str1[30] = "asrertv";
  char str2[30] = "asrertv";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 7), strncat(str1, str2, 7));
}
END_TEST
START_TEST(strcat_test3) {
  char str1[30] = "xszrav";
  char str2[30] = "ssegrht";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 3), strncat(str1, str2, 3));
}
END_TEST
START_TEST(strcat_test4) {
  char str1[30] = "xasrgcs";
  char str2[30] = "earhst";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 4), strncat(str1, str2, 4));
}
END_TEST

int main() {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, strcat_test1);
  tcase_add_test(tc, strcat_test2);
  tcase_add_test(tc, strcat_test3);
  tcase_add_test(tc, strcat_test4);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}