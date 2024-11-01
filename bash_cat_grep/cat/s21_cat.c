
#include "s21_cat.h"

int main(int argc, char *argv[]) {
  // забираем флаги
  Flag flags = parseFlags(argc, argv);

  if (!flags.error) {
    // тело (применение флагов к файлам)
    handleFiles(argc, argv, flags);
  } else {
    printf("usage: cat [-belnstuv] [file ...]");
  }
}

Flag parseFlags(int argc, char *argv[]) {
  Flag flags = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int opt;

  //Перевод длинных флагов в короткие
  struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                  {"number", no_argument, NULL, 'n'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {0, 0, 0, 0}};

  // Парсер
  while ((opt = getopt_long(argc, argv, "+benstEvT", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        flags.numberNonblank = 1;
        break;
      case 'e':
        flags.showEnds = 1;
        flags.suppressV = 1;
        break;
      case 'n':
        flags.numberAll = 1;
        break;
      case 's':
        flags.squeezeBlank = 1;
        break;
      case 't':
        flags.showTabs = 1;
        flags.suppressV = 1;
        break;
      case 'E':
        flags.showEndsOnly = 1;
        break;
      case 'v':
        flags.suppressV = 1;
        break;
      case 'T':
        flags.showTabsOnly = 1;
        break;
      case '?':
        flags.error = 1;
        break;
    }
  }

  return flags;
}

void handleFiles(int argc, char *argv[], Flag flags) {
  if (optind < argc) {
    // Итераци по всем флагам
    for (int i = optind; i < argc; i++) {
      int lineIndex = 0;
      int consecutiveNewlines = 0;
      int previousChar = '\n';
      FILE *file;

      // Работа с файлом
      file = fopen(argv[i], "r");

      if (!file) {
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
      } else {
        int currentChar = 0;

        // Считывание с файла
        while ((currentChar = fgetc(file)) != EOF) {
          applyFlagLogic(flags, currentChar, &previousChar, &lineIndex,
                         &consecutiveNewlines);
        }
      }

      fclose(file);
    }
  }
}

void applyFlagLogic(Flag flags, int currentChar, int *previousChar,
                    int *lineIndex, int *consecutiveNewlines) {
  // cat -s
  if (!(flags.squeezeBlank && *previousChar == '\n' && currentChar == '\n' &&
        *consecutiveNewlines)) {
    if (*previousChar == '\n' && currentChar == '\n')
      *consecutiveNewlines = 1;
    else
      *consecutiveNewlines = 0;
    // cat -n
    if (((flags.numberAll && !flags.numberNonblank) ||
         (flags.numberNonblank && currentChar != '\n')) &&
        *previousChar == '\n') {
      *lineIndex += 1;
      printf("%6d\t", *lineIndex);
    }
    // cat -e
    if ((flags.showEnds || flags.showEndsOnly) && currentChar == '\n') {
      if (flags.numberNonblank && *consecutiveNewlines) {
        printf("      \t$");
      } else {
        printf("$");
      }
    }
    // cat -t
    if ((flags.showTabs || flags.showTabsOnly) && currentChar == '\t') {
      printf("^");
      currentChar = '\t' + 64;
    }
    // cat -v
    if (flags.suppressV && currentChar != '\n' && currentChar != '\t') {
      if (currentChar < 32) {
        printf("^");
        currentChar += 64;
      } else if (currentChar >= 127) {
        printf("^");
        currentChar -= 64;
      }
    }

    printf("%c", currentChar);
    *previousChar = currentChar;
  }
}