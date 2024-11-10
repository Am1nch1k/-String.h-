#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *dest_final = (unsigned char *)dest;
  unsigned char *src_final = (unsigned char *)src;

  for (size_t i = 0; i < n; i++) {
    dest_final[i] = src_final[i];
  }
  return dest_final;
}
