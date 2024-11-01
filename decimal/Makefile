CC = gcc

CC_FLAGS = -Werror -Wextra -Wall -std=c11
TEST_FLAGS := -lcheck
GCOV_FLAGS = -lgcov -fprofile-arcs -ftest-coverage
SAN = -fsanitize=address

ifeq ($(shell uname -s),Linux)
	CC_FLAGS += -lrt -lm -lsubunit
endif

SRC = ./functions/s21_*.c

TEST_SRC = ./tests/s21_*.c
# Набор всех файлов для cpplint / cppcheck
ALL_C_H_FILES = $(shell find . -type f | grep "\.(c|h)$$" -E)

O_FILES = s21_*.o

LIB_O=s21_decimal.o
LIB_A=s21_decimal.a

NO_MESSAGE := >>/dev/null

all: clean s21_decimal.a

rebuild: clean all

s21_decimal.a:
	@$(CC) -c $(CC_FLAGS) $(SRC)
	@ar -rv s21_decimal.a $(O_FILES) s21_decimal.h $(NO_MESSAGE)
	@ranlib s21_decimal.a $(NO_MESSAGE)
	@rm -rf *.o

test: clean s21_decimal.a
	$(CC) $(TEST_SRC)  $(SRC) s21_decimal.a -o test $(TEST_FLAGS) $(CC_FLAGS)
	@./test
	@make clean

gcov_report: clean s21_decimal.a
	$(CC) $(TEST_SRC)  $(SRC) s21_decimal.a -o test $(TEST_FLAGS) $(CC_FLAGS) $(GCOV_FLAGS)
	@./test
	@lcov -t "test" -o s21_test.info -c -d .
	@genhtml -o report s21_test.info
	@rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
	@rm -rf test
	@open ./report/index.html

style: clean
	@cppcheck ../src
	@clang-format -i tests/*.h tests/*.c functions/*.c *.h 
	@clang-format -n tests/*.h tests/*.c functions/*.c *.h 

clean:
	@rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
	@rm -rf report/*
	@rm -rf test

valgrind_test: clean s21_decimal.a
	@$(CC) $(TEST_SRC) s21_decimal.a -o test $(TEST_FLAGS) $(CC_FLAGS) -g
	@valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./test
