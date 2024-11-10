#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  const unsigned char *str_final = (const unsigned char *)str;

  for (size_t i = 0; i < n; i++) {
    if (str_final[i] == (unsigned char)c) {
      return (void *)(str_final + i);
    }
  }

  return NULL;
}
