#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = NULL;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == (unsigned char)c) {
      result = (char *)str + i;
    }
    i++;
  }
  if (c == '\0') {
    result = (char *)str + i;
  }

  return result;
}
