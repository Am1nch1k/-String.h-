#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char symb = c;
  char *buff;
  for (;; str++) {
    if (*str == symb) {
      buff = (char *)str;
      break;
    }
    if (*str == '\0') {
      buff = S21_NULL;
      break;
    }
  }
  return buff;
}
