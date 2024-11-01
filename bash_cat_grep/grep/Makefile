CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
COMMON-FILES = s21_grep.c

all: s21_grep 

s21_grep:
	$(CC) $(CFLAGS) $(COMMON-FILES) -o s21_grep

clean:
	rm -rf s21_grep

rebuild:
	rm -rf s21_grep
	$(CC) $(CFLAGS) $(COMMON-FILES) -o s21_grep