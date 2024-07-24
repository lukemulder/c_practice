# Compiler and flags
CC=gcc
CFLAGS=-I./lib/hash_table -I./lib/stack -I./lib/queue -I./assert -Wall -g

# Output binary
BIN=data_structure_tests

# Source directories
HASH_DIR=lib/hash_table
HASH_TEST_DIR=lib/hash_table/test
STACK_DIR=lib/stack
STACK_TEST_DIR=lib/stack/test
QUEUE_DIR=lib/queue
QUEUE_TEST_DIR=lib/queue/test
ASSERT_DIR=assert

# Source files
SRC_FILES=$(HASH_DIR)/hash_table.c \
          $(HASH_TEST_DIR)/hash_table_tests.c \
					$(STACK_DIR)/stack.c \
					$(STACK_TEST_DIR)/stack_tests.c \
					$(QUEUE_DIR)/queue.c \
					$(QUEUE_TEST_DIR)/queue_tests.c \
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