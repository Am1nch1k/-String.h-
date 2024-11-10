#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *pointer = NULL;
  if (!str && pointer) {
    while (pointer && *pointer && s21_strchr(delim, *pointer) != NULL) {
      pointer = pointer + 1;
    }
    if (!pointer || !*pointer) {
      str = NULL;
    } else {
      str = pointer;
    }
  }
  if (str) {
    while (s21_strchr(delim, *str) != NULL) {
      str = str + 1;
    }
  }
  char *final_str = NULL;
  int flag = 0;
  if (str) {
    for (long unsigned j = 0; s21_strlen(str) > j && flag != 1; j++) {
      for (long unsigned i = 0; s21_strlen(delim) > i; i++) {
        if (str[j] == delim[i]) {
          flag = 1;
          final_str = str;
          final_str[j] = '\0';
          if (pointer != NULL) {
            pointer = pointer + j + 1;
          } else {
            pointer = str + j + 1;
          }
          break;
        }
      }
      if (j == s21_strlen(str) - 1 && !final_str) {
        final_str = pointer;
        pointer = NULL;
      }
    }
  }
  if (final_str) {
    if (final_str[0] == '\0') {
      return NULL;
    }
  }
  return final_str;
}
