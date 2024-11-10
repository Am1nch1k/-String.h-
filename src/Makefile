OS = $(shell uname)

ifeq ($(OS), Darwin)
	CHECK = -lcheck  -lm  -lpthread
endif

ifeq ($(OS), Linux)
	CHECK = -lcheck -lsubunit -lm -lrt -lpthread
endif

CC=gcc


CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

all: 
	make test 
	make clean 
	make gcov_report
	make clean

test: s21_string.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c s21_*.c -L.s21_string.a $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_to_upper.c -L. s21_string.a $(CHECK) -o to_upper_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_to_lower.c -L. s21_string.a $(CHECK) -o to_lower_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_insert.c -L. s21_string.a $(CHECK) -o insert_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_trim.c -L. s21_string.a $(CHECK) -o trim_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strtok.c -L. s21_string.a $(CHECK) -o strtok_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strrchr.c -L. s21_string.a $(CHECK) -o strrchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strpbrk.c -L. s21_string.a $(CHECK) -o strpbrk_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strlen.c -L. s21_string.a $(CHECK) -o strlen_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strerror.c -L. s21_string.a $(CHECK) -o strerror_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strstr.c -L. s21_string.a $(CHECK) -o strstr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strcspn.c -L. s21_string.a $(CHECK) -o strcspn_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncmp.c -L. s21_string.a $(CHECK) -o strncmp_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncpy.c -L. s21_string.a $(CHECK) -o strncpy_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memchr.c -L. s21_string.a $(CHECK) -o memchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memcmp.c -L. s21_string.a $(CHECK) -o memcmp_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memcpy.c -L. s21_string.a $(CHECK) -o memcpy_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_memset.c -L. s21_string.a $(CHECK) -o memset_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strchr.c -L. s21_string.a $(CHECK) -o strchr_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_strncat.c -L. s21_string.a $(CHECK) -o strncat_test
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test_sprintf.c -L. s21_string.a $(CHECK) -o sprintf_test
	make run_tests

s21_string.a:
	$(CC) $(CFLAGS) -c s21_*.c
	ar rc s21_string.a *.o
	rm -rf *.o

gcov_report: s21_string.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_to_upper.c test_to_upper.c s21_string.a -o to_upper_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_to_lower.c test_to_lower.c s21_string.a -o to_lower_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_insert.c test_insert.c s21_string.a -o insert_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_trim.c test_trim.c s21_string.a -o trim_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strtok.c test_strtok.c s21_string.a -o strtok_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strrchr.c test_strrchr.c s21_string.a -o strrchr_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strpbrk.c test_strpbrk.c s21_string.a -o strpbrk_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strlen.c test_strlen.c s21_string.a -o strlen_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strerror.c test_strerror.c s21_string.a -o strerror_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strstr.c test_strstr.c s21_string.a -o strstr_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strcspn.c test_strcspn.c s21_string.a -o strcspn_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strncmp.c test_strncmp.c s21_string.a -o strncmp_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strncpy.c test_strncpy.c s21_string.a -o strncpy_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_memchr.c test_memchr.c s21_string.a -o memchr_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_memcmp.c test_memcmp.c s21_string.a -o memcmp_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_memcpy.c test_memcpy.c s21_string.a -o memcpy_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_memset.c test_memset.c s21_string.a -o memset_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strchr.c test_strchr.c s21_string.a -o strchr_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_strncat.c test_strncat.c s21_string.a -o strncat_test $(CHECK)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_sprintf.c test_sprintf.c s21_string.a -o sprintf_test $(CHECK)
	make run_tests
	lcov -o testing.info -c -d .
	genhtml -o report testing.info

clean:
	rm -rf *.o *.a *test s21_string.a *.info  *.gcda *.gcno

run_tests:
	./to_upper_test
	./to_lower_test
	./insert_test
	./trim_test
	./strtok_test
	./strrchr_test
	./strpbrk_test
	./strlen_test
	./strerror_test
	./strstr_test
	./strcspn_test
	./strncmp_test
	./strncpy_test
	./memchr_test
	./memcmp_test
	./memcpy_test
	./memset_test
	./strchr_test
	./strncat_test
	./sprintf_test
