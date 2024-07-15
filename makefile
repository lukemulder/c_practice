# Compiler and flags
CC=gcc
CFLAGS=-I./lib/hash_table -I./assert -Wall -g

# Output binary
BIN=hash_table_tests

# Source directories
SRC_DIR=lib/hash_table
TEST_DIR=lib/hash_table/test
ASSERT_DIR=assert

# Source files
SRC_FILES=$(SRC_DIR)/hash_table.c \
          $(TEST_DIR)/hash_table_tests.c \
          $(ASSERT_DIR)/asserts.c \
          main.c

# Object files
OBJ_FILES=$(SRC_FILES:.c=.o)

# Dependencies
DEPS=$(SRC_FILES:.c=.h)

# Build the application
$(BIN): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f $(BIN) $(OBJ_FILES)

# Run the application
run: $(BIN)
	./$(BIN)