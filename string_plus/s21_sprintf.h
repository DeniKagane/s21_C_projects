#ifndef _SPRINTF_
#define _SPRINTF

#include "s21_string.h"

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool hash;
  bool zero;
} flags;

typedef struct {
  flags fl;
  int width;
  int precision;
  char length;
  char specifier;
  bool error;
  bool has_precision;
} args;

bool is_digit(const char ch);
bool is_flag(const char ch);
bool is_spec(const char ch);
int char_to_int(const char ch);
void num_to_str(int64_t num, char *str_num, int base);
void double_to_string(long double num, char *str_num, args arg);
void normalize_double(long double *num, int *exp, char *exp_sign);
void remove_point(char *str_num);
void remove_exp(char *str_num, int exp);
void remove_end(char *str_num);
void remove_zeros(char *str_num);
void norm_double_to_sc_not(char *str_num, int exp, char exp_sign, args arg);
int double_to_sc_notation(long double num, char *str_num, args arg);
void double_to_gG_format(args arg, long double num, char *str_num);
void *to_upper(char *str);
char *str_plus_str(char *str, char *str_num);

char *parse_int(args arg, char *str, va_list vars);
char *parse_char(args arg, char *str, va_list vars);
char *parse_float(args arg, char *str, va_list vars);
char *parse_string(args arg, char *str, va_list vars);
char *parse_unsigned(args arg, char *str, va_list vars);
char *parse_octal(args arg, char *str, va_list vars);
char *parse_hex(args arg, char *str, va_list vars);
char *parse_pointer(args arg, char *str, va_list vars);

char *format_char(args arg, char *str, char ch);
char *format_wchar(args arg, char *str, wchar_t w_ch);
void format_precision(char *str_num, args arg);
void format_flags(char *str_num, args arg);
void format_string(args arg, char *str, char *sstr);
void format_wstring(args arg, char *str, wchar_t *wstr);

void set_gG_size(char *str_num, int new_len);

int s21_sprintf(char *output, const char *input, ...);

#endif