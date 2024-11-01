#define _GNU_SOURCE

#ifndef GREP_FUNC

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
  int regexFlag;
  int e;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  char *patterns;
  int error;
  int fileIndex;
  int patternIndex;

} Flags;

void grep(Flags flags, char *patterns, char **files);
void grepFile(FILE *file, Flags flags, regex_t *preg, char *files);
void printFlagO(regex_t *preg, char *line);
void printFlagEL(Flags flags, int matchCounter, char *files, int lkey);
void printFileName(Flags flags, char *files);
void printLineNumber(Flags flags, int lineNumber);
Flags parseGrepFlags(int argc, char *argv[], char *patterns, char **files);
void manageFiles(Flags *flags, char **files, int argc, char *argv[]);
void processArguments(int argc, char *argv[], Flags *flags, char *patterns,
                      char **files);
void setFlagE(Flags *flags, char *patterns);
void setFlagF(Flags *flags, char *patterns);
#endif