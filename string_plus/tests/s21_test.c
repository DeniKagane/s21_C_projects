

#include "s21_test.h"

void run_testcase(Suite *testcase);
void run_tests(void);

int main(void) {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_strlen(),
                         suite_memcmp(),
                         suite_strncat(),
                         suite_strncpy(),
                         suite_strchr(),
                         suite_strncmp(),
                         suite_strrchr(),
                         suite_memcpy(),
                         suite_memset(),
                         suite_memchr(),
                         suite_strcspn(),
                         suite_strpbrk(),
                         suite_strtok(),
                         suite_sprintf(),
                         suite_strstr(),
                         suite_strerror(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
