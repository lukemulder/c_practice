#include <stdio.h>
#include "asserts.h"

// Function to record the outcome of test cases
void recordTestOutcome(int passed, const char* expression, const char* func, const char* file, int line) {
    const char* outcome = passed ? "PASSED" : "FAILED";
    printf("%s: %s at %s %s:%d\n", outcome, expression, func, file, line);
}