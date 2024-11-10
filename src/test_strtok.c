#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_strtok) {
  char str[25] = "test1lltest2ltest3ltest4";
  char str_2[25] = "test1lltest2ltest3ltest4";
  char sep[10] = "l";
  char *istr;
  char *fstr;
  istr = s21_strtok(str, sep);
  fstr = strtok(str_2, sep);
  while (istr != NULL || fstr != NULL) {
    ck_assert_str_eq(istr, fstr);
    istr = s21_strtok(NULL, sep);
    fstr = strtok(NULL, sep);
  }
  char str_3[28] = "cstrclubstepclubgocgofunccc";
  char str_4[28] = "cstrclubstepclubgocgofunccc";
  char sep_2[5] = "club";
  char *gstr = s21_strtok(str_3, sep_2);
  char *hstr = strtok(str_4, sep_2);
  while (gstr != NULL || hstr != NULL) {
    ck_assert_str_eq(gstr, hstr);
    gstr = s21_strtok(NULL, sep_2);
    hstr = strtok(NULL, sep_2);
  }
  char str_5[9] = "ineedprp";
  char str_6[9] = "ineedprp";
  char sep_3[9] = "ineedprp";
  char *xstr = s21_strtok(str_5, sep_3);
  char *ystr = strtok(str_6, sep_3);
  ck_assert_pstr_eq(xstr, ystr);
}
END_TEST

int main(void) {
  Suite *s = suite_create("strtok");
  TCase *tc = tcase_create("strtok");
  SRunner *srun = srunner_create(s);
  int sf = 0;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strtok);
  srunner_run_all(srun, CK_ENV);
  sf = srunner_ntests_failed(srun);
  srunner_free(srun);
  return sf == 0 ? 0 : 1;
}
