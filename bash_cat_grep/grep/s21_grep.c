#include "s21_grep.h"

int main(int argc, char *argv[]) {
  char *patterns = (char *)malloc(256 * sizeof(char));
  if (patterns == NULL) {
    printf("Memory for the array cannot be allocated");
  } else {
    strcpy(patterns, "");
  }

  int numFiles = 10;
  char **files = malloc(numFiles * sizeof(char *));
  if (files == NULL) {
    printf("Memory for the array cannot be allocated");
  }
  Flags flags = parseGrepFlags(argc, argv, patterns, files);
  if (flags.error == false) {
    grep(flags, patterns, files);
  }
  free(patterns);
  for (int i = 0; i < flags.fileIndex; i++) {
    free(files[i]);
  }
  free(files);
  return 0;
}

void grep(Flags flags, char *patterns, char **files) {
  regex_t preg;
  int reti = regcomp(&preg, patterns, flags.regexFlag);
  if (reti) {
    fprintf(stderr, "Can't compile regular expression\n");
  }
  for (int i = 0; i < flags.fileIndex; i++) {
    FILE *file = fopen(files[i], "r");
    if (file == NULL) {
      if (flags.s == false) {
        fprintf(stderr, "grep: %s: No such file or directory\n", files[i]);
      }
      continue;
    } else {
      grepFile(file, flags, &preg, files[i]);
    }
    fclose(file);
  }
  regfree(&preg);
}

void grepFile(FILE *file, Flags flags, regex_t *preg, char *files) {
  int matchCounter = 0;
  int lineNumber = 1;
  int lkey = 0;
  char line[MAX_LINE_LENGTH];
  regmatch_t match;
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    line[strcspn(line, "\n")] = 0;
    if (regexec(preg, line, 1, &match, 0) == 0 && flags.v == false) {
      matchCounter++;
      if (flags.c == false && flags.l == false) {
        printFileName(flags, files);
        printLineNumber(flags, lineNumber);
        if (flags.o == false) {
          printf("%s\n", line);
        } else {
          printFlagO(preg, line);
        }
      }
      lkey = 1;
      //проверка паттерна
    } else if (regexec(preg, line, 1, &match, 0) != 0 && flags.v == true) {
      matchCounter++;
      if (flags.c == false && flags.l == false) {
        printFileName(flags, files);
        printLineNumber(flags, lineNumber);
        printf("%s\n", line);
      }
      lkey = 1;
    }

    lineNumber++;
  }

  printFlagEL(flags, matchCounter, files, lkey);
}

// grep -o
void printFlagO(regex_t *preg, char *line) {
  int offset = 0;
  regmatch_t match;
  while (regexec(preg, line + offset, 1, &match, 0) == 0) {
    printf("%.*s\n", (int)(match.rm_eo - match.rm_so),
           line + offset + match.rm_so);
    offset += match.rm_eo;
    if (match.rm_so == -1) {
      break;
    }
  }
}

// grep -l
void printFlagEL(Flags flags, int matchCounter, char *files, int lkey) {
  if (flags.c == true && flags.l == false) {
    printFileName(flags, files);
    printf("%d\n", matchCounter);
  } else if (flags.c == true && flags.l == true) {
    printFileName(flags, files);
    if (lkey == 1) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
  if (flags.l == true && lkey == 1) {
    printf("%s\n", files);
  }
}

//название файла
void printFileName(Flags flags, char *files) {
  if (flags.fileIndex > 1 && flags.h == false) {
    printf("%s:", files);
  }
}

//вывод номера строки
void printLineNumber(Flags flags, int lineNumber) {
  if (flags.n == true) {
    printf("%d:", lineNumber);
  }
}

//парсер
Flags parseGrepFlags(int argc, char *argv[], char *patterns, char **files) {
  Flags flags = {0,     false, false, false, false, false, false,
                 false, false, false, false, false, 0,     0};
  int currentFlag;
  while ((currentFlag = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, 0)) !=
         -1) {
    switch (currentFlag) {
      case 'e':
        setFlagE(&flags, patterns);
        break;
      case 'i':
        flags.regexFlag |= REG_ICASE;
        break;
      case 'v':
        flags.v = true;
        break;
      case 'c':
        flags.c = true;
        break;
      case 'l':
        flags.l = true;
        break;
      case 'n':
        flags.n = true;
        break;
      case 'h':
        flags.h = true;
        break;
      case 's':
        flags.s = true;
        break;
      case 'f':
        setFlagF(&flags, patterns);
        break;
      case 'o':
        flags.o = true;
        break;
      case '?':
        flags.error = true;
        break;
      default:
        break;
    }
  }
  //применение флагов
  manageFiles(&flags, files, argc, argv);
  processArguments(argc, argv, &flags, patterns, files);
  return flags;
}

void manageFiles(Flags *flags, char **files, int argc, char *argv[]) {
  if (flags->e || flags->f) {
    flags->fileIndex = argc - optind;
    if (flags->fileIndex > 0) {
      for (int i = 0; i < flags->fileIndex; i++) {
        files[i] = strdup(argv[optind + i]);
      }
    }
  }
}

void processArguments(int argc, char *argv[], Flags *flags, char *patterns,
                      char **files) {
  if (flags->e == false && flags->f == false) {
    bool patternSet = false;
    for (int i = 1; i < argc; i++) {
      files[flags->fileIndex] = NULL;
      if (argv[i][0] == '-') {
        continue;
      }
      if (patternSet == false) {
        strcat(patterns, argv[i]);
        patternSet = true;
      } else {
        files[flags->fileIndex] = strdup(argv[i]);
        flags->fileIndex++;
      }
    }
  }
}

void setFlagE(Flags *flags, char *patterns) {
  flags->e = true;
  flags->regexFlag |= REG_EXTENDED;
  flags->patternIndex++;
  if (flags->patternIndex != 1) {
    strcat(patterns, "|");
  }
  strcat(patterns, optarg);
}

void setFlagF(Flags *flags, char *patterns) {
  int flagError = 0;
  flags->f = true;
  flags->regexFlag |= REG_EXTENDED;
  FILE *file = fopen(optarg, "r");
  if (file == NULL) {
    printf("%s: No such file or directory\n", optarg);
    flagError = 1;
  } else if (!flagError) {
    char *line = NULL;
    size_t bufferSize = 100;
    line = (char *)malloc(bufferSize * sizeof(char));
    if (line == NULL) {
      fprintf(stderr, "Error! Memory allocation error!\n");
      flagError = 1;
    } else if (!flagError) {
      while (fgets(line, bufferSize, file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        flags->patternIndex++;
        if (flags->patternIndex != 1) {
          strcat(patterns, "|");
        }
        strcat(patterns, line);
        if (line[strlen(line) - 1] != '\n' && !flagError) {
          bufferSize *= 2;
          char *temp = realloc(line, bufferSize);
          if (temp == NULL) {
            fprintf(stderr, "Error! Memory allocation error!\n");
            free(line);
            flagError = 1;
          }
          line = temp;
        }
      }
      fclose(file);
      free(line);
    }
  }
}
