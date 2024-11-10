#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(trim_1) {
  char src[5] = "Hell";
  char str[7] = "elgjkl";
  char *res = s21_trim(src, str);
  ck_assert_str_eq((char *)res, "H");
  char src2[100] = "\tHello, world\n";
  char str2[100] = "";
  char *res2 = s21_trim(src2, str2);
  ck_assert_str_eq((char *)res2, "Hello, world");
  free(res);
  free(res2);
  const char *str_2 = NULL;
  ck_assert_ptr_null(s21_trim(str_2, str_2));
}
END_TEST

int main(void) {
  Suite *s = suite_create("trim");
  TCase *tc = tcase_create("trim");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, trim_1);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
