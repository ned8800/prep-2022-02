TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c
SRCS = \
	project/src/main.c \
	project/src/record_data.c \
	project/src/functions.c

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

TARGET_TESTS = ./main_tests.out
HDRS_DIR = project/include

SRCS_TESTS = \
	project/src/main_tests.c \
	project/src/record_data.c \
	project/src/functions.c

.PHONY: all_test build_test rebuild_test check_test memtest_test clean_test

all_test: clean_test check_test memtest_test

$(TARGET_TESTS): $(SRCS_TESTS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET_TESTS) $(CFLAGS) $(SRCS_TESTS)

build_test: $(TARGET_TESTS)

rebuild_test: clean_test build_test

check_test:
	./run_linters.sh

memtest_test: $(TARGET_TESTS)
	./btests/run.sh $(TARGET_TESTS) --memcheck

clean_test:
	rm -rf $(TARGET_TESTS) *.dat 
