#include "s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  char *str_ptr = (char *)str;
  for (size_t i = 0; i < n; i++) {
    str_ptr[i] = (char)c;
  }
  return str;
}
