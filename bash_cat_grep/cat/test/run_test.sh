#!/bin/bash

GREEN='\e[32m'
NC='\e[0m'
RED='\e[31m'

printf "${GREEN}-----RUNNING TESTS-----${NC}\n"
cp ../s21_cat ./

cat test1.txt > a
./s21_cat test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./s21_grep $PAT test1.txt

failed=0
i=1

# TEST 1 cat file
if [ $? -eq 0 ]; then
    printf " TEST cat #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 2 cat -b
cat -b test1.txt > a
./s21_cat -b test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -b #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -b #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 3 cat --number-nonblank
cat --number-nonblank test1.txt > a
./s21_cat --number-nonblank test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat --number-nonblank #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat --number-nonblank #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 4 cat -e
cat -e test2.txt > a
./s21_cat -e test2.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -e #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -e #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 5 cat -E
cat -E test3.txt > a
./s21_cat -E test3.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -E #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -E #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 6 cat -n
cat -n test1.txt > a
./s21_cat -n test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -n #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -n #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 7 cat -s
cat -s test1.txt > a
./s21_cat -s test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -s #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -s #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 8 cat --squeeze-blank
cat --squeeze-blank test1.txt > a
./s21_cat --squeeze-blank test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat --squeeze-blank #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat --squeeze-blank #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 9 cat -t
cat -t test1.txt > a
./s21_cat -t test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -t #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -t #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))


# TEST 10 cat -T
cat -T test1.txt > a
./s21_cat -T test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST cat -T #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST cat -T #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))