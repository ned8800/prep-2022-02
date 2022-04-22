TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c
SRCS = \
	project/src/main.c \
	project/src/record_functions.c \
	project/src/custom_functions.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	./run_linters.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)
	
memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat

#My tests
TARGET_TESTS = ./main_tests.out
HDRS_DIR = project/include

SRCS_TESTS = \
	project/src/main_tests.c \
	project/src/record_functions.c \
	project/src/custom_functions.c

.PHONY: all_tests build_tests rebuild_tests check_tests test_tests clean_tests

all_tests: clean_tests check_tests test_tests

$(TARGET_TESTS): $(SRCS_TESTS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET_TESTS) $(CFLAGS) $(SRCS_TESTS)

build_tests: $(TARGET_TESTS)

rebuild_tests: clean_tests build_tests

check_tests:
	./run_linters.sh

memtest_tests: $(TARGET_TESTS)
	 $(TARGET_TESTS) --memcheck

clean_tests:
	rm -rf $(TARGET_TESTS) *.dat 
