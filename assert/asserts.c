#include <stdio.h>
#include "asserts.h"

// Function to record the outcome of test cases
void recordTestOutcome(int passed, const char* expression, const char* file, int line) {
    const char* outcome = passed ? "PASSED" : "FAILED";
    printf("Test %s: %s at %s:%d\n", outcome, expression, file, line);
}