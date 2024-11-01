CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
COMMON-FILES = s21_cat.c

all: s21_cat 

s21_cat:
	$(CC) $(CFLAGS) $(COMMON-FILES) -o s21_cat

clean:
	rm -rf s21_cat

rebuild:
	rm -rf s21_cat
	$(CC) $(CFLAGS) $(COMMON-FILES) -o s21_cat