#include <check.h>
#include <string.h>

#include "s21_string.h"
const char a[] = "ERUNDA tra ta ta TRI ra ry";
const char b[] = "Hello world\n\0";
const char c[] = "q\n\0";
const char d[] = " \n\0";
const char e[] = " \0";
const char f[] = "\n\0";
const char g[] = "\0";

START_TEST(test_strlen) { ck_assert_uint_eq(strlen(a), s21_strlen(a)); }
END_TEST
START_TEST(s21_sstrlen_test_b) { ck_assert_uint_eq(strlen(b), s21_strlen(b)); }
END_TEST
START_TEST(s21_sstrlen_test_c) { ck_assert_uint_eq(strlen(c), s21_strlen(c)); }
END_TEST
START_TEST(s21_strlen_test_d) { ck_assert_uint_eq(strlen(d), s21_strlen(d)); }
END_TEST
START_TEST(s21_strlen_test_e) { ck_assert_uint_eq(strlen(e), s21_strlen(e)); }
END_TEST
START_TEST(s21_strlen_test_f) { ck_assert_uint_eq(strlen(f), s21_strlen(f)); }
END_TEST
START_TEST(s21_strlen_test_g) { ck_assert_uint_eq(strlen(g), s21_strlen(g)); }
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strlen);
  tcase_add_test(tc, s21_sstrlen_test_b);
  tcase_add_test(tc, s21_sstrlen_test_c);
  tcase_add_test(tc, s21_strlen_test_d);
  tcase_add_test(tc, s21_strlen_test_f);
  tcase_add_test(tc, s21_strlen_test_g);
  tcase_add_test(tc, s21_strlen_test_e);
  //  tcase_add_test(tc, test_cos_NAN);
  // tcase_add_test(tc, test_cos_PLUS_INF);
  // tcase_add_test(tc, test_cos_MINUS_INF);

  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
