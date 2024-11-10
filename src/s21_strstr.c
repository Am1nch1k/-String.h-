#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  size_t haystack_len = s21_strlen(haystack);
  size_t needle_len = s21_strlen(needle);

  if (needle_len == 0) return (char *)haystack;

  for (size_t i = 0; i <= haystack_len - needle_len; i++) {
    size_t j;
    for (j = 0; j < needle_len; j++)
      if (haystack[i + j] != needle[j]) break;

    if (j == needle_len) return (char *)&haystack[i];
  }

  return NULL;
}
