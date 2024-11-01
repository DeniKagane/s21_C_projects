#ifndef CAT_FUNC

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int numberAll;
  int numberNonblank;
  int squeezeBlank;
  int showEnds;
  int showTabs;
  int suppressV;
  int showEndsOnly;
  int showTabsOnly;
  int error;
} Flag;

Flag parseFlags(int argc, char *argv[]);
void applyFlagLogic(Flag flags, int c, int *previousChar, int *lineIndex,
                    int *consecutiveNewlines);
void handleFiles(int argc, char *argv[], Flag flags);

#endif