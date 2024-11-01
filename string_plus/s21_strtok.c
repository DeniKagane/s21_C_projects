#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* nextToken = S21_NULL;
  if (str) nextToken = str;

  if (!nextToken) return S21_NULL;

  char* tokenStart = nextToken;
  while (*tokenStart) {
    bool isDelim = false;
    for (const char* d = delim; *d; d++) {
      if (*tokenStart == *d) {
        tokenStart++;
        isDelim = true;
        break;
      }
    }
    if (!isDelim) {
      break;
    }
  }

  if (!*tokenStart) {
    nextToken = S21_NULL;
    return S21_NULL;
  }

  char* tokenEnd = tokenStart;

  while (*tokenEnd) {
    for (const char* d = delim; *d; d++) {
      if (*tokenEnd == *d) {
        *tokenEnd = '\0';
        nextToken = tokenEnd + 1;
        return tokenStart;
      }
    }
    tokenEnd++;
  }
  nextToken = S21_NULL;
  return tokenStart;
}