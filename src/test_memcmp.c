#include <check.h>
#include <math.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_memcmp1) {
  char str1[10] = "Hello";
  char str2[10] = "Hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
}
END_TEST
START_TEST(test_memcmp2) {
  char str3[10] = "Hello";
  char str4[10] = "olleH";
  ck_assert_int_eq(s21_memcmp(str3, str4, 3) / abs(s21_memcmp(str3, str4, 3)),
                   memcmp(str3, str4, 3) / abs(memcmp(str3, str4, 3)));
}
END_TEST
START_TEST(test_memcmp3) {
  char str1[10] = "Hel";
  char str2[10] = "Hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4) / abs(s21_memcmp(str1, str2, 4)),
                   memcmp(str1, str2, 4) / abs(memcmp(str1, str2, 4)));
}
END_TEST
START_TEST(test_memcmp4) {
  char str1[10] = "school";
  char str2[10] = "school";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memcmp1);
  tcase_add_test(tc, test_memcmp2);
  tcase_add_test(tc, test_memcmp3);
  tcase_add_test(tc, test_memcmp4);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}