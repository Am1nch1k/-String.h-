#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (!str) {
    return S21_NULL;
  }
  size_t len_str = s21_strlen(str);
  char *temp_string = malloc(sizeof(char) * (len_str + 1));
  for (size_t i = 0; i < len_str; i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      temp_string[i] = str[i] - 32;
    } else {
      temp_string[i] = str[i];
    }
  }
  temp_string[len_str] = '\0';
  return (char *)temp_string;
}