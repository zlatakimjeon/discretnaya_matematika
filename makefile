CFLAGS = -Wall -Wextra -std=c99
SRC = src/subset_iterator.c
TARGET = bin/main

all: $(TARGET)

$(TARGET): $(SRC)
 mkdir -p bin
 $(CC) $(CFLAGS) $< -o $@

clean:
 rm -rf bin

.PHONY: all clean
