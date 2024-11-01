#ifndef _STRING_TEST_
#define _STRING_TEST_

#include <check.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

Suite* suite_strlen();
Suite* suite_memcmp();
Suite* suite_strncat();
Suite* suite_strncpy();
Suite* suite_strchr();
Suite* suite_strncmp();
Suite* suite_strrchr();
Suite* suite_memcpy();
Suite* suite_sprintf();
Suite* suite_memset();
Suite* suite_memchr();
Suite* suite_strcspn();
Suite* suite_strpbrk();
Suite* suite_strtok();
Suite* suite_strstr();
Suite* suite_strerror();

#endif