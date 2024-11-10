#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_elements) {
  size_t str_lenght = s21_strlen(src);
  size_t temp_lenght = s21_strlen(trim_elements);
  if (!src) {
    return NULL;
  }
  char *temp_str;
  char trim_array[str_lenght];
  for (size_t i = 0; i < str_lenght; i++) {
    trim_array[i] = 0;
  }
  for (size_t i = 0; i < str_lenght; i++) {
    for (size_t j = 0; j < temp_lenght; j++) {
      if (trim_elements[j] == src[i]) {
        trim_array[i] = 1;
        break;
      }
    }
  }
  char check = 0;
  for (size_t i = 0; i < str_lenght; i++) {
    if (trim_array[i] == 1) {
      check = 1;
    }
  }
  if (check == 0 && trim_elements[0] == '\0') {
    size_t flag = 0;
    for (size_t i = 0; i < str_lenght; i++) {
      if (src[i] == ' ' || src[i] == '\n' || src[i] == '\t') {
        trim_array[i] = 1;
      } else if (flag == 0) {
        flag = i;
      } else {
        for (size_t z = flag; z < i; z++) {
          trim_array[z] = 0;
        }
      }
    }
  }
  size_t res = 0;
  for (size_t i = 0; i < str_lenght; i++) {
    if (trim_array[i] == 0) {
      res++;
    }
  }
  temp_str = malloc(sizeof(char) * (res + 1));
  size_t count_passed_trims = 0;
  for (size_t i = 0; i < str_lenght; i++) {
    if (trim_array[i] == 0) {
      temp_str[i - count_passed_trims] = src[i];
    } else {
      count_passed_trims++;
    }
  }
  temp_str[res] = '\0';
  return temp_str;
}
