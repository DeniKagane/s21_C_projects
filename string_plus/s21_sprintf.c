#include "s21_sprintf.h"

const char *flags_from_str(const char *input, args *arg);
const char *width_from_str(const char *input, args *arg, va_list vars);
const char *prec_from_str(const char *input, args *arg, va_list vars);
const char *len_from_str(const char *input, args *arg);
const char *spec_from_str(const char *input, args *arg);
char *parse_value(args arg, char *str, va_list vars);

int s21_sprintf(char *str, const char *format, ...) {
  char *tmp_str = str;
  va_list vars;
  va_start(vars, format);
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      args arg = {0};
      format = flags_from_str(format, &arg);
      format = width_from_str(format, &arg, vars);
      format = prec_from_str(format, &arg, vars);
      format = len_from_str(format, &arg);
      format = spec_from_str(format, &arg);
      str = parse_value(arg, str, vars);
      if (arg.specifier == 'n') {
        int *num = va_arg(vars, int *);
        (*num) = str - tmp_str;
      }
    }
    format++;
  }
  *str = '\0';
  va_end(vars);
  return str - tmp_str;
}

const char *flags_from_str(const char *input, args *arg) {
  while (is_flag(*input) && !arg->error) {
    switch (*input) {
      case '-':
        if (!arg->fl.zero) {
          arg->fl.minus = 1;
        } else {
          arg->error = 1;
        }
        break;
      case '0':
        if (!arg->fl.minus) {
          arg->fl.zero = 1;
        } else {
          arg->error = 1;
        }
        break;
      case '+':
        if (!arg->fl.space) {
          arg->fl.plus = 1;
        } else {
          arg->error = 1;
        }
        break;
      case ' ':
        if (!arg->fl.plus) {
          arg->fl.space = 1;
        } else {
          arg->error = 1;
        }
        break;
      case '#':
        arg->fl.hash = 1;
        break;
    }
    input++;
  }
  return input;
}

const char *width_from_str(const char *input, args *arg, va_list vars) {
  if (*input == '*') {
    arg->width = va_arg(vars, int);
    input++;
  } else if (is_digit(*input)) {
    int width = 0;
    while (is_digit(*input)) {
      width *= 10;
      width += char_to_int(*input);
      input++;
    }
    arg->width = width;
  }
  return input;
}

const char *prec_from_str(const char *input, args *arg, va_list vars) {
  if (*input == '.') {
    input++;
    if (*input == '*') {
      input++;
      arg->precision = va_arg(vars, int);
      arg->has_precision = 1;
    } else if (is_digit(*input)) {
      int precision = 0;
      while (is_digit(*input)) {
        precision *= 10;
        precision += char_to_int(*input);
        input++;
      }
      arg->precision = precision;
      arg->has_precision = 1;
    } else {
      arg->error = 1;
    }
  }
  return input;
}

const char *len_from_str(const char *input, args *arg) {
  switch (*input) {
    case 'h':
      arg->length = 'h';
      input++;
      break;
    case 'l':
      arg->length = 'l';
      input++;
      break;
    case 'L':
      arg->length = 'L';
      input++;
      break;
  }
  return input;
}

const char *spec_from_str(const char *input, args *arg) {
  if (is_spec(*input)) {
    arg->specifier = *input;
  } else {
    arg->error = 1;
  }
  return input;
}

char *parse_value(args arg, char *str, va_list vars) {
  char spec = arg.specifier;
  if (spec == 'c') {
    str = parse_char(arg, str, vars);
  } else if (spec == 'd' || spec == 'i') {
    str = parse_int(arg, str, vars);
  } else if (spec == 'f' || spec == 'e' || spec == 'E' || spec == 'g' ||
             spec == 'G')
    str = parse_float(arg, str, vars);
  else if (spec == 's')
    str = parse_string(arg, str, vars);
  else if (spec == 'u')
    str = parse_unsigned(arg, str, vars);
  else if (spec == 'o')
    str = parse_octal(arg, str, vars);
  else if (spec == 'x' || spec == 'X')
    str = parse_hex(arg, str, vars);
  else if (spec == 'p')
    str = parse_pointer(arg, str, vars);
  else if (spec == '%')
    *str++ = '%';
  return str;
}

void set_gG_size(char *str_num, int new_len) {
  size_t len = s21_strlen(str_num);
  int i = len;
  while ((int)len > new_len) {
    str_num[i--] = '\0';
    len--;
  }
}
