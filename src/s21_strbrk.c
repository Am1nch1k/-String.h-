#include "s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  char* s1 = (char*)str1;
  char* s2 = (char*)str2;
  int size = s21_strlen(str2);
  int flag = 1;
  char* res = S21_NULL;
  while (*s1 != '\0' && flag == 1) {
    for (int i = 0; size > i && flag == 1; i++) {
      if (*s1 == s2[i]) {
        flag = 0;
        res = s1;
      }
    }
    s1++;
  }
  return res;
}
