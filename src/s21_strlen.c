#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t lenght = 0;
  if (str) {
    while (str[lenght] != '\0' && str[lenght]) {
      lenght++;
    }
  }
  return lenght;
}
