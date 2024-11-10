#include "s21_string.h"

char* s21_strcat(char* dest, const char* src) {
  s21_strcpy(dest + s21_strlen(dest), src);
  return dest;
}
