#include "s21_string.h"
void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (!src || !str) {
    return NULL;
  }
  size_t str_lenght = s21_strlen(src);
  size_t temp_lenght = s21_strlen(str);
  if (start_index >= str_lenght) {
    return NULL;
  }
  char *temp_str = malloc(sizeof(char) * (temp_lenght + str_lenght + 1));
  char flag = 0;
  for (size_t i = 0; i < str_lenght; i++) {
    if (i == start_index && !flag) {
      flag = 1;
      for (size_t j = 0; j < temp_lenght; j++) {
        temp_str[i + j] = str[j];
      }
      temp_str[i + temp_lenght] = src[i];
    } else {
      if (flag) {
        temp_str[i + temp_lenght] = src[i];
      } else {
        temp_str[i] = src[i];
      }
    }
  }
  temp_str[temp_lenght + str_lenght] = '\0';
  return (char *)temp_str;
}