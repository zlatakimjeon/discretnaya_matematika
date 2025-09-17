CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

# Основная программа
$(BIN_DIR)/main: $(SRC_DIR)/main.c
 mkdir -p $(BIN_DIR)
 $(CC) $(CFLAGS) $< -o $@

# Тесты
$(BIN_DIR)/test_runner: $(TEST_DIR)/test_runner.c $(TEST_DIR)/test_main.c $(SRC_DIR)/main.c
 mkdir -p $(BIN_DIR)
 $(CC) $(CFLAGS) $^ -o $@

# Цели
all: $(BIN_DIR)/main $(BIN_DIR)/test_runner

test: $(BIN_DIR)/test_runner
 ./$(BIN_DIR)/test_runner

clean:
 rm -rf $(BIN_DIR)

.PHONY: all test clean