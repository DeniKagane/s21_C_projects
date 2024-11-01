#include "s21_sprintf.h"
#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char res[BUFSIZ] = {'\0'};
  if (errnum <= MIN_ERR || errnum >= MAX_ERR_ARR) {
    s21_sprintf(res, "%s%d", ERROR, errnum);
  } else {
    s21_strcpy(res, s21_errlist[errnum]);
  }
  return res;
}
