CFLAGS = -Wall -Wextra -std=c99
TARGET = bin/main
TEST_TARGET = bin/test_runner
SRC = subset_iterator.c
TEST_SRC = test_runner.c test_subset_iterator.c

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SRC)
 mkdir -p bin
 $(CC) $(CFLAGS) $< -o $@

$(TEST_TARGET): $(TEST_SRC)
 mkdir -p bin
 $(CC) $(CFLAGS) $^ -o $@

test: $(TEST_TARGET)
 ./$(TEST_TARGET)

clean:
 rm -rf bin

.PHONY: all test clean
