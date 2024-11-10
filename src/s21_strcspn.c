#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  int i = 0;
  int flag = 0;
  while (str1[i] != '\0') {
    int j = 0;
    while (str2[j] != '\0') {
      if (str1[i] == str2[j]) {
        flag = 1;
        break;
      }
      j++;
    }
    if (flag == 1) break;
    i++;
  }
  return i;
}
