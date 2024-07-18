#ifndef STACK_H
#define STACK_H

// Node for the stack
typedef struct StackNode {
    int value; // Value associated with the key
    struct StackNode *next; // Pointer to the next node in the bucket
} StackNode;

// Stack structure
typedef struct Stack {
    StackNode *head; // Head of the stack
    int size; // Number of elements in the stack
} Stack;

// Function to create a new stack
// @return Pointer to the newly created stack
Stack* createStack();

// Function to delete a stack
// @param table The stack to delete
void deleteStack(Stack *s);

// Function to insert value onto the top of the stack
// @param table The stack
// @param value The value to insert
void stackPush(Stack *s, int value);

// Function to remove a value from the stack
// @param stack
// @return The value on the top of the stack
int stackPop(Stack *s);

// Function to peak at the top value of the stack
// @param stack
// @return The value on the top of the stack
int stackPeak(Stack *s);

// Function to retrieve a size of the stack
// @param stack
// @return The size of the stack
int stackSize(Stack *s);

#endif // HASH_TABLE_H