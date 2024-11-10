#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_memcpy1) {
  char str[20] = "test";
  char dest1[20] = "";
  char dest2[20] = "";
  ck_assert_pstr_eq(s21_memcpy(dest1, str, 4), memcpy(dest2, str, 4));
}
END_TEST
START_TEST(test_memcpy2) {
  char str[20] = "school21";
  char dest1[20] = "write";
  char dest2[20] = "write";
  ck_assert_pstr_eq(s21_memcpy(dest1, str, 4), memcpy(dest2, str, 4));
}
END_TEST
START_TEST(test_memcpy3) {
  char str[20] = "12345";
  char dest1[20] = "\0";
  char dest2[20] = "\0";
  ck_assert_pstr_eq(s21_memcpy(dest1, str, 4), memcpy(dest2, str, 4));
}
END_TEST
START_TEST(test_memcpy4) {
  char str[20] = "qwerty";
  char dest1[20] = "qw";
  char dest2[20] = "qw";
  ck_assert_pstr_eq(s21_memcpy(dest1, str, 4), memcpy(dest2, str, 4));
}
END_TEST

int main() {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memcpy1);
  tcase_add_test(tc, test_memcpy2);
  tcase_add_test(tc, test_memcpy3);
  tcase_add_test(tc, test_memcpy4);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}