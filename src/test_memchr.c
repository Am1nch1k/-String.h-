#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_memchr1) {
  const char *buff = "qwedescv66WER";
  ck_assert_str_eq(memchr(buff, 'd', 5), s21_memchr(buff, 'd', 5));
}
END_TEST
START_TEST(test_memchr2) {
  const char *buff = "School21";
  ck_assert_pstr_eq(memchr(buff, 'v', 2), s21_memchr(buff, 'v', 2));
}
END_TEST
START_TEST(test_memchr3) {
  const char *buff = "School21";
  ck_assert_pstr_eq(memchr(buff, 'c', 5), s21_memchr(buff, 'c', 5));
}
END_TEST
START_TEST(test_memchr4) {
  const char *buff = "qwerty";
  ck_assert_str_eq(memchr(buff, 'q', 5), s21_memchr(buff, 'q', 5));
}
START_TEST(test_memchr5) {
  const char *buff = "qwerty";
  ck_assert_pstr_eq(memchr(buff, 'v', 6), s21_memchr(buff, 'v', 6));
}
END_TEST

int main() {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memchr1);
  tcase_add_test(tc, test_memchr2);
  tcase_add_test(tc, test_memchr3);
  tcase_add_test(tc, test_memchr4);
  tcase_add_test(tc, test_memchr5);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
