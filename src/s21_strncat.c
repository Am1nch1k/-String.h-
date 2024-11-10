#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  int i = s21_strlen(dest);
  int k = 0;
  int f = n;
  while (k < f) {
    dest[i] = src[k];
    k++;
    i++;
  }
  return dest;
}
