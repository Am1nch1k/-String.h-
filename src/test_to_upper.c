#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(upper_1) {
  char *res_str;
  res_str = s21_to_upper("abcdefghij7");
  ck_assert_str_eq(res_str, "ABCDEFGHIJ7");
  free(res_str);
  char *res2_str = s21_to_upper(NULL);
  ck_assert_ptr_null(res2_str);
  free(res2_str);
}
END_TEST

int main(void) {
  Suite *s = suite_create("to_upper");
  TCase *tc = tcase_create("to_upper");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, upper_1);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}