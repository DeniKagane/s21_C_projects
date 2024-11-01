#!/bin/bash

GREEN='\e[32m'
NC='\e[0m'
RED='\e[31m'
PATFILE=test2.txt
PAT=top
TESTFILE=test1.txt

printf "${GREEN}-----RUNNING TESTS-----${NC}\n"
cp ../s21_grep ./

grep $PAT test1.txt > a
./s21_grep $PAT test1.txt > b
result=$(diff a b)
# leaks -atExit -- ./s21_grep $PAT test1.txt

failed=0
i=1

# TEST 1 grep pat file
if [ $? -eq 0 ]; then
    printf " TEST grep #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 2 grep -v pat file
grep -v $PAT $TESTFILE > a
./s21_grep -v $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -v #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -v #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 3 grep -i pat file
grep -i $PAT $TESTFILE > a
./s21_grep -i $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -i #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -i #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 4 grep -c pat file
grep -c $PAT $TESTFILE > a
./s21_grep -c $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -c #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -c #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 5 grep -l pat file
grep -l $PAT $TESTFILE > a
./s21_grep -l $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -l #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -l #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 6 grep -n pat file
grep -n $PAT $TESTFILE > a
./s21_grep -n $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -n #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -n #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 7 grep -h pat file
grep -h $PAT $TESTFILE > a
./s21_grep -h $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -h #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -h #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 8 grep -s pat file
grep -s $PAT $TESTFILE > a
./s21_grep -s $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -s #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -s #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 9 grep -f pat file
grep -f $PATFILE $TESTFILE > a
./s21_grep -f $PATFILE $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -f #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -f #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

# TEST 10 grep -o file
grep -o $PAT $TESTFILE > a
./s21_grep -o $PAT $TESTFILE > b
result=$(diff a b)
# leaks -atExit -- ./a.out -v $PAT $TESTFILE

if [ $? -eq 0 ]; then
    printf " TEST grep -o #$i ${GREEN}PASSED${NC}\n"
else
    printf " TEST grep -o #$i ${RED}FAILED${NC}\n"
    printf "$result\n"
    ((failed++))
fi

((i++))

