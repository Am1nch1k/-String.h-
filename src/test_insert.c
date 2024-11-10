#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(insert_1) {
  char src[5] = "gggg";
  char str[6] = "bb bb";
  char *res = s21_insert(src, str, 2);
  ck_assert_str_eq((char *)res, "ggbb bbgg");
  free(res);
  const char *str_2 = NULL;
  ck_assert_ptr_null(s21_insert(str_2, str_2, 228));
  ck_assert_ptr_null(s21_insert(src, str, 228));
}
END_TEST

int main(void) {
  Suite *s = suite_create("insert");
  TCase *tc = tcase_create("insert");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, insert_1);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}