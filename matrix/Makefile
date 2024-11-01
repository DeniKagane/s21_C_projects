CC = gcc
OS = $(shell uname)

CC_FLAGS = -Werror -Wextra -Wall -std=c11
GCOV_FLAGS = -lgcov -fprofile-arcs -ftest-coverage
SAN = -fsanitize=address

ifeq ($(OS), Linux)
	TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	TEST_FLAGS = -lcheck
endif

SRC = ./s21_*.c

TEST_SRC = ./tests/s21_*.c
ALL_C_H_FILES = $(shell find . -type f | grep "\.(c|h)$$" -E)

O_FILES = s21_*.o

LIB_O=s21_matrix.o
LIB_A=s21_matrix.a

NO_MESSAGE := >>/dev/null

all: clean s21_matrix.a

rebuild: clean all

s21_matrix.a:
	@$(CC) -c $(CC_FLAGS) $(SRC)
	@ar -rv s21_matrix.a $(O_FILES) s21_matrix.h $(NO_MESSAGE)
	@ranlib s21_matrix.a $(NO_MESSAGE)
	@rm -rf *.o

test: clean s21_matrix.a
	$(CC) $(TEST_SRC) $(SRC) s21_matrix.a -o test $(TEST_FLAGS) $(CC_FLAGS)
	@./test
	@make clean

gcov_report: clean s21_matrix.a
	$(CC) $(TEST_SRC) $(SRC) s21_matrix.a -o test $(TEST_FLAGS) $(CC_FLAGS) $(GCOV_FLAGS)
	@./test
	@lcov -t "test" -o s21_test.info -c -d .
	@genhtml -o report s21_test.info
	@rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
	@rm -rf test
	@open ./report/index.html

style: clean
	@cppcheck ../src
	@clang-format -i tests/*.c *.c *.h 
	@clang-format -n tests/*.c *.c *.h 

clean:
	@rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
	@rm -rf report/*
	@rm -rf test

valgrind_test: clean s21_matrix.a
	@$(CC) $(TEST_SRC) s21_matrix.a -o test $(TEST_FLAGS) $(CC_FLAGS) -g
	@valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./test
