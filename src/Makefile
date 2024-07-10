CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
GCOVFLAGS = -ftest-coverage -fprofile-arcs
TESTFLAGS = -lcheck

OS := $(shell uname)
ifeq ($(OS), Linux)
    TESTFLAGS += -lm -lrt -lsubunit -lpthread
endif

SOURCE = s21_math.c 
HEADER = s21_math.h
OBJECTS= $(patsubst %.c, %.o, $(SOURCE))

TESTS_SOURCE = $(wildcard ./tests/test_*.c)
TESTS_OBJECTS = $(patsubst ./tests/%.c, ./tests/%.o, ${TESTS_SOURCE})
TESTS_HEADER = ./test_includes/s21_tests.h

all: s21_math.a test

s21_math.a: $(SOURCE) $(HEADER)
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar rc s21_math.a $(OBJECTS)
	ranlib s21_math.a
	rm -rf *.o


test: s21_math.a main.c ${TESTS_SOURCE} $(TESTS_HEADER) 
	$(CC) $(CFLAGS) main.c ${TESTS_SOURCE} $(TESTFLAGS) s21_math.a -o atest
	./atest
	rm -rf *.o *.a atest

gcov_report: main.c ${TESTS_SOURCE} $(TESTS_HEADER) $(SOURCE) 
	$(CC) $(CFLAGS) $(GCOVFLAGS) main.c ${TESTS_SOURCE} $(TESTFLAGS) s21_math.c -o test
	./test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	rm -rf *.o *.gcno *.gcda *.info test

open:
	open report/index.html

valgrind: s21_math.a main.c ${TESTS_SOURCE} $(TESTS_HEADER)
	$(CC) $(CFLAGS) main.c ${TESTS_SOURCE} $(TESTFLAGS) s21_math.a -o test 
	valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

style: clean
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(SOURCE) $(HEADER) ${TESTS_SOURCE} $(TESTS_HEADER)

leaks: s21_math.a main.c ${TESTS_SOURCE} $(TESTS_HEADER)
	$(CC) $(CFLAGS) main.c ${TESTS_SOURCE} $(TESTFLAGS) s21_math.a -o test
	leaks -atExit -- ./test

clean:
	rm -rf *.o *.gcno *.a *.gcda
	rm -rf ./report/ *.info
	rm -rf test_report test

re:	clean all

.PHONY: all test gcov_report valgrind clean
