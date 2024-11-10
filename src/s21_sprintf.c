//
// Created by Andrey on 01.06.2024.
//

#include <math.h>
#include <stdarg.h>

#include "s21_string.h"

struct S21SprintfFlags {
  int minus_flag, plus_flag, space_flag, sharp_flag, zero_flag;
};

int s21_is_sprintf_specifier(char c);
int s21_is_sprintf_flags(char c);
void s21_parse_sprintf_flag(struct S21SprintfFlags *flags, char c);
void s21_sput_digit_16(char **str, int digit, int upper);
void s21_ull2str(char **str, unsigned long long num, int base, int upper);
void s21_swrite_str(char **str, char *inp, struct S21SprintfFlags flags,
                    int width, int precision, char *prefix);
void s21_swrite_num(char **str, char sign, unsigned long long val,
                    struct S21SprintfFlags flags, int width, int precision,
                    int base);
int s21_write_double_int_part(char **str, long double num);

int s21_write_double_frac_part(char *str, long double num, int counter,
                               int precision, int i);
char s21_sput_floating_point_num(char **str, long double num,
                                 struct S21SprintfFlags flags, int precision);
void s21_swrite_floating_point_num(char **str, long double num,
                                   struct S21SprintfFlags flags, int width,
                                   int precision, int delete_nulls);
char s21_sput_scientific_num(char **str, long double num,
                             struct S21SprintfFlags flags, int precision,
                             int upper);
void s21_swrite_scientific_num(char **str, long double num,
                               struct S21SprintfFlags flags, int width,
                               int precision, int upper);

void swrite_g_float(char **str, long double num, struct S21SprintfFlags flags,
                    int width, int precision, int upper);
int s21_swrites(char **str, char format, va_list *args,
                struct S21SprintfFlags flags, int width, int precise,
                int l_counter, int L_counter, int h_counter, char *start);

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *start = str;
  int error = 0;
  while (*format != '\0' && error == 0) {
    if (*format == '%') {
      ++format;
      // flags finding
      struct S21SprintfFlags flags = {0, 0, 0, 0, 0};
      while (s21_is_sprintf_flags(*format)) {
        s21_parse_sprintf_flag(&flags, *format);
        ++format;
      }
      // width scanning
      int width = -1;
      int factor = 1;
      while (*format >= '0' && *format <= '9') {
        if (width == -1) width = 0;
        width = width * factor + (*format - '0');
        factor *= 10;
        ++format;
      }
      if (width == -1 && *format == '*') {
        width = va_arg(args, int);
        ++format;
      }
      // precise scanning
      int precise = -1;
      if (*format == '.') {
        precise = 0;
        ++format;
        factor = 1;
        while (*format >= '0' && *format <= '9') {
          precise = precise * factor + (*format - '0');
          factor *= 10;
          ++format;
        }
        if (precise == 0 && *format == '*') {
          precise = va_arg(args, int);
          ++format;
        }
      }
      // length scanning
      int h_counter = 0;
      int l_counter = 0;
      int L_counter = 0;
      while (*format == 'h' || *format == 'l' || *format == 'L') {
        if (*format == 'h') h_counter += 1;
        if (*format == 'l') l_counter += 1;
        if (*format == 'L') L_counter += 1;
        ++format;
      }
      if (s21_is_sprintf_specifier(*format)) {
        error = s21_swrites(&str, *format, &args, flags, width, precise,
                            l_counter, L_counter, h_counter, start);
        ++format;
      } else {
        error = -1;
        fprintf(stderr, "%s", "Specifier error!\n");
      }
    } else {
      *(str++) = *(format++);
    }
  }
  *str = '\0';
  va_end(args);
  if (error == 0)
    return str - start;
  else
    return error;
}

int s21_is_sprintf_specifier(char c) {
  const char values[] = "cdifsuoxXeEnpgG%";
  const char *value = values;
  for (; *value != c && *value != '\0'; ++value)
    ;
  if (*value == '\0')
    return 0;
  else
    return 1;
}

int s21_is_sprintf_flags(char c) {
  const char values[] = "-+ #0";
  const char *value = values;
  for (; *value != c && *value != '\0'; ++value)
    ;
  if (*value == '\0')
    return 0;
  else
    return 1;
}

void s21_parse_sprintf_flag(struct S21SprintfFlags *flags, char c) {
  switch (c) {
    case '-':
      flags->minus_flag = 1;
      break;
    case '+':
      flags->plus_flag = 1;
      break;
    case ' ':
      flags->space_flag = 1;
      break;
    case '#':
      flags->sharp_flag = 1;
      break;
    case '0':
      flags->zero_flag = 1;
      break;
  }
}

void s21_sput_digit_16(char **str, int digit, int upper) {
  if (digit < 10) {
    **str = '0' + (char)(digit);
  } else {
    if (upper)
      **str = 'A' + (char)(digit - 10);
    else
      **str = 'a' + (char)(digit - 10);
  }
}

void s21_ull2str(char **str, unsigned long long num, int base, int upper) {
  if (num / base != 0) s21_ull2str(str, num / base, base, upper);
  s21_sput_digit_16(str, num % base, upper);
  *(++(*str)) = '\0';
}

void s21_swrite_str(char **str, char *inp, struct S21SprintfFlags flags,
                    int width, int precision, char *prefix) {
  int len = 0;
  char null[] = "(null)";
  if (inp == NULL) inp = &(null[0]);
  while (*(inp + len) != '\0' && (precision < 0 || len < precision)) ++len;
  char fill = ' ';
  if (flags.zero_flag && !flags.minus_flag) fill = '0';
  if (prefix[0] != 'c') {
    for (char *ptr = prefix; *ptr != '\0'; ++len, ++ptr)
      ;
    if (fill == '0')
      for (; (**str = *prefix) != '\0'; ++(*str), ++prefix)
        ;
    if (!flags.minus_flag) {
      for (; len < width; ++len) *((*str)++) = fill;
    }
    if (fill == ' ')
      for (; (**str = *prefix) != '\0'; ++(*str), ++prefix)
        ;

    for (int counter = 0;
         (**str = *inp) != '\0' && (precision < 0 || counter < precision);
         ++(*str), ++inp, ++counter)
      ;
    if (flags.minus_flag) {
      for (; len < width; ++len) *((*str)++) = fill;
    }
  } else {
    len = 1;
    if (!flags.minus_flag) {
      for (; len < width; ++len) *((*str)++) = fill;
    }
    *((*str)++) = inp[0];
    if (flags.minus_flag) {
      for (; len < width; ++len) *((*str)++) = fill;
    }
  }
  **str = '\0';
}

void s21_swrite_num(char **str, char sign, unsigned long long val,
                    struct S21SprintfFlags flags, int width, int precision,
                    int base) {
  char temp[22] = "";
  char *temp_ptr = &(temp[0]);
  char prefix[3] = "\0\0\0";
  if (precision != 0 || val != 0) {
    if (base > 0)
      s21_ull2str(&temp_ptr, (unsigned long long)val, base, 0);
    else
      s21_ull2str(&temp_ptr, (unsigned long long)val, -base, 1);
    if (sign == '-')
      prefix[0] = '-';
    else {
      if (flags.plus_flag)
        prefix[0] = '+';
      else if (flags.space_flag)
        prefix[0] = ' ';
    }
    if (val != 0 && flags.sharp_flag &&
        (base == 8 || base == 16 || base == -16)) {
      prefix[0] = '0';
      if (base == 16) prefix[1] = 'x';
      if (base == -16) prefix[1] = 'X';
    }
  }
  int len = 0;
  while (temp[len]) ++len;
  int size = precision + 1 > len ? precision + 1 : len;
  char *buf = malloc(sizeof(char) * size);
  for (int i = 0; i < size; ++i) buf[i] = '0';
  // for (int i = 0; i <= len; ++i) buf[size - 1 - len + i] = temp[i];
  for (int i = 0; i <= len; ++i)
    buf[(precision + 1 > len ? precision : len) - len + i] = temp[i];
  s21_swrite_str(str, buf, flags, width, -1, &(prefix[0]));
  free(buf);
}

int s21_write_double_int_part(char **str, long double num) {
  int counter = 0;
  if (num / 10 > 1) {
    counter = s21_write_double_int_part(str, truncl(num / 10));
  }
  if (counter < 25)
    (*((*str)++)) = '0' + (char)((truncl(num - 10 * truncl(num / 10))));
  else
    (*((*str)++)) = '0';
  return counter + 1;
}

int s21_write_double_frac_part(char *str, long double num, int counter,
                               int precision, int i) {
  int digit;
  if (i + 1 < precision) {
    digit = (int)truncl(num * 10);
    long double new_num = num * 10 - digit;
    digit +=
        s21_write_double_frac_part(str, new_num, counter, precision, i + 1);
  } else {
    digit = (int)roundl(num * 10);
  }
  if (counter + i < 26)
    *(str + i) = '0' + digit % 10;
  else
    *(str + i) = '0';
  return digit / 10;
}

char s21_sput_floating_point_num(char **str, long double num,
                                 struct S21SprintfFlags flags, int precision) {
  if (precision == -1) precision = 6;
  char sign = '\0';
  if (num < 0) {
    sign = '-';
    num *= -1;
  } else {
    if (flags.plus_flag)
      sign = '+';
    else if (flags.space_flag)
      sign = ' ';
  }
  int counter;
  if (precision > 0)
    counter = s21_write_double_int_part(str, num);
  else
    counter = s21_write_double_int_part(str, roundl(num));
  if (precision > 0 || flags.sharp_flag) (*((*str)++)) = '.';
  **str = '\0';
  if (precision > 0) {
    s21_write_double_frac_part(*str, num - trunc(num), counter, precision, 0);
    *str += precision;
    **str = '\0';
  }

  return sign;
}

void s21_swrite_floating_point_num(char **str, long double num,
                                   struct S21SprintfFlags flags, int width,
                                   int precision, int delete_nulls) {
  if (num != num)
    s21_swrite_str(str, "nan", flags, width, -1, "");
  else {
    char temp[1000] = "";
    char *temp_ptr = &(temp[0]);
    char prefix[2] = "";
    prefix[0] = s21_sput_floating_point_num(&temp_ptr, num, flags, precision);
    if (delete_nulls) {
      while (*(temp_ptr - 1) == '0') *(--temp_ptr) = '\0';
      if (*temp_ptr == '.') *temp_ptr = '\0';
    }
    s21_swrite_str(str, temp, flags, width, -1, &(prefix[0]));
  }
}

char s21_sput_scientific_num(char **str, long double num,
                             struct S21SprintfFlags flags, int precision,
                             int upper) {
  long double mantise = num;
  int power = 0;
  char power_sign = '+';
  if (fabsl(num) > 1) {
    while (fabsl(mantise) >= 10) {
      mantise /= 10;
      power += 1;
    }
  } else {
    while (fabsl(mantise) < 1 && mantise != 0) {
      power_sign = '-';
      mantise *= 10;
      power += 1;
    }
  }

  char sign = s21_sput_floating_point_num(str, mantise, flags, precision);
  **str = '\0';
  if (upper)
    (*((*str)++)) = 'E';
  else
    (*((*str)++)) = 'e';
  **str = '\0';
  flags.zero_flag = 1;
  flags.plus_flag = 1;
  s21_swrite_num(str, power_sign, power, flags, -1, 2, 10);
  **str = '\0';
  return sign;
}

void s21_swrite_scientific_num(char **str, long double num,
                               struct S21SprintfFlags flags, int width,
                               int precision, int upper) {
  if (num != num) {
    if (upper)
      s21_swrite_str(str, "NAN", flags, width, -1, "");
    else
      s21_swrite_str(str, "nan", flags, width, -1, "");
  } else {
    char temp[1000] = "";
    char *temp_ptr = &(temp[0]);
    char prefix[2] = "";
    prefix[0] =
        s21_sput_scientific_num(&temp_ptr, num, flags, precision, upper);
    s21_swrite_str(str, temp, flags, width, -1, &(prefix[0]));
  }
}

void swrite_g_float(char **str, long double num, struct S21SprintfFlags flags,
                    int width, int precision, int upper) {
  if (num != num) {
    s21_swrite_floating_point_num(str, num, flags, width, precision, 0);
  } else {
    if (precision == -1) precision = 6;
    if (precision == 0) precision = 1;
    int power = 0;
    long double mantise = num;
    if (fabsl(mantise) > 1) {
      while (fabsl(mantise) >= 10) {
        mantise /= 10;
        power += 1;
      }
    } else {
      while (fabsl(mantise) < 1 && mantise != 0) {
        mantise *= 10;
        power -= 1;
      }
    }
    if (precision > power && power >= -4)
      s21_swrite_floating_point_num(str, num, flags, width,
                                    precision - (power + 1), !flags.sharp_flag);
    else
      s21_swrite_scientific_num(str, num, flags, width, precision - 1, upper);
  }
}

int s21_swrites(char **str, char format, va_list *args,
                struct S21SprintfFlags flags, int width, int precise,
                int l_counter, int L_counter, int h_counter, char *start) {
  unsigned long long num;
  long double fnum;
  long long int temp;
  unsigned short ush_int;
  int *num_ptr;
  void *ptr;
  char sign = '+';
  char char_temp[] = "\0\0";
  int error = 0;
  switch (format) {
    case 'i':
    case 'd':
      if (l_counter) {
        if (l_counter > 1) {
          temp = va_arg(*args, long long int);
        } else {
          temp = va_arg(*args, long int);
        }
      } else {
        temp = va_arg(*args, int);
      }
      num = temp;
      if (temp < 0) {
        sign = '-';
        num = temp * (-1);
      }
      s21_swrite_num(str, sign, num, flags, width, precise, 10);
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      if (L_counter)
        fnum = (long double)va_arg(*args, long double);
      else
        fnum = (long double)va_arg(*args, double);

      if (format == 'f')
        s21_swrite_floating_point_num(str, fnum, flags, width, precise, 0);
      if (format == 'e' || format == 'E')
        s21_swrite_scientific_num(str, fnum, flags, width, precise,
                                  format == 'E');
      if (format == 'g' || format == 'G') {
        swrite_g_float(str, fnum, flags, width, precise, format == 'G');
      }
      break;
    case 'u':
    case 'o':
    case 'x':
    case 'X':
      if (l_counter) {
        if (l_counter > 1) {
          num = va_arg(*args, unsigned long long int);
        } else {
          num = va_arg(*args, unsigned long int);
        }
      } else {
        if (h_counter) {
          ush_int = va_arg(*args, int);
          num = ush_int;
        } else
          num = va_arg(*args, unsigned int);
      }
      flags.plus_flag = 0;
      flags.space_flag = 0;
      if (format == 'u')
        s21_swrite_num(str, sign, num, flags, width, precise, 10);
      if (format == 'o')
        s21_swrite_num(str, sign, num, flags, width, precise, 8);
      if (format == 'x')
        s21_swrite_num(str, sign, num, flags, width, precise, 16);
      if (format == 'X')
        s21_swrite_num(str, sign, num, flags, width, precise, -16);
      break;
    case 'p':
      flags.sharp_flag = 1;
      flags.plus_flag = 0;
      flags.space_flag = 0;
      ptr = va_arg(*args, void *);
      num = (unsigned long long)ptr;
      s21_swrite_num(str, sign, num, flags, width, precise, 16);
      break;
    case 'c':
      char_temp[0] = (char)va_arg(*args, int);
      s21_swrite_str(str, char_temp, flags, width, -1, "c");
      **(str) = '\0';
      break;
    case '%':
      width = -1;
      char_temp[0] = '%';
      s21_swrite_str(str, char_temp, flags, width, -1, "c");
      **(str) = '\0';
      break;
    case 's':
      s21_swrite_str(str, va_arg(*args, char *), flags, width, precise, "");
      break;
    case 'n':
      num_ptr = va_arg(*args, int *);
      *num_ptr = *str - start;
      break;
    default:
      error = -1;
      fprintf(stderr, "%s", "No case for specifier!\n");
  }
  return error;
}