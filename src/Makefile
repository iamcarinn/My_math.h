CC= gcc
FLAGS= -Wall -Wextra -Werror -std=c11
M1=

ifeq ($(shell uname -p), arm)
	CC= gcc-12
	M1 = ${shell pkg-config --cflags --libs check}
endif

all: clean gcov_report

style:
	clang-format -i *.c
	clang-format -n *.c

leaks: test
	CK_FORK=no leaks -atExit -- ./run_tests
	rm -rf *.o *.gcov *.gcno *.gcda *.info test run_tests s21_math s21_math.a

s21_math.a: s21_math
	ar rc s21_math.a s21_*.o
	ranlib s21_math.a

s21_math: s21_math.c s21_math.h
	gcc ${FLAGS} -c s21_math.c

test: s21_math.a test.c
	${CC} ${FLAGS} -c test.c ${M1}
	${CC} -c -fprofile-arcs -ftest-coverage s21_math.c
	${CC} -fprofile-arcs -ftest-coverage s21_math.c test.o ${M1} -lcheck -lm -lpthread -o run_tests
	./run_tests

gcov_report: test
	lcov -t "s21_math_report" -o report.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report report.info --rc lcov_branch_coverage=1
	rm -rf *.o *.gcov *.gcno *.gcda *.info test run_tests s21_math s21_math.a
	open ./report/index.html

clean:
	rm -rf *.o *.gcov *.gcno *.gcda *.info test run_tests s21_math s21_math.a report
