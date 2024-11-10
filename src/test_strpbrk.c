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

START_TEST(test_strpbrk) { ck_assert_str_eq(strpbrk(a, b), s21_strpbrk(a, b)); }
END_TEST
START_TEST(s21_strpbrk_test_b) {
  ck_assert_str_eq(strpbrk(b, d), s21_strpbrk(b, d));
}
END_TEST
START_TEST(s21_strpbrk_test_c) {
  ck_assert_str_eq(strpbrk(c, a), s21_strpbrk(c, a));
}
END_TEST
START_TEST(s21_strpbrk_test_d) {
  ck_assert_str_eq(strpbrk(a, "aeiou"), s21_strpbrk(a, "aeiou"));
}
END_TEST
START_TEST(s21_strpbrk_test_e) { ck_assert(s21_strpbrk(e, "aeiou") == NULL); }
END_TEST
START_TEST(s21_strpbrk_test_f) { ck_assert(s21_strpbrk(f, "aeiou") == NULL); }
END_TEST
START_TEST(s21_strpbrk_test_g) { ck_assert(s21_strpbrk(g, "aeiou") == NULL); }
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strpbrk);
  tcase_add_test(tc, s21_strpbrk_test_b);
  tcase_add_test(tc, s21_strpbrk_test_c);
  tcase_add_test(tc, s21_strpbrk_test_d);
  tcase_add_test(tc, s21_strpbrk_test_f);
  tcase_add_test(tc, s21_strpbrk_test_g);
  tcase_add_test(tc, s21_strpbrk_test_e);
  //  tcase_add_test(tc, test_cos_NAN);
  // tcase_add_test(tc, test_cos_PLUS_INF);
  // tcase_add_test(tc, test_cos_MINUS_INF);

  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
