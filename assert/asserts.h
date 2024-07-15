#include <stdio.h>
#include <string.h>

extern void recordTestOutcome(int passed, const char* expression, const char* file, int line);

#define ASSERT_TRUE(expression) \
    do { \
        if (expression) { \
            recordTestOutcome(1, #expression, __FILE__, __LINE__); \
        } else { \
            recordTestOutcome(0, #expression, __FILE__, __LINE__); \
        } \
    } while (0)

#define ASSERT_FALSE(expression) ASSERT_TRUE(!(expression))

#define EQUALS(actual, expected) \
    do { \
        int a_ = (actual); \
        int e_ = (expected); \
        if (a_ != e_) { \
            recordTestOutcome(0, #actual " == " #expected, __FILE__, __LINE__); \
        } else { \
            recordTestOutcome(1, #actual " == " #expected, __FILE__, __LINE__); \
        } \
    } while (0)

#define STR_EQUALS(actual, expected) \
    do { \
        char* a_ = (actual); \
        char* e_ = (expected); \
        if (strcmp(a_, e_) != 0) { \
            recordTestOutcome(0, #actual " == " #expected, __FILE__, __LINE__); \
        } else { \
            recordTestOutcome(1, #actual " == " #expected, __FILE__, __LINE__); \
        } \
    } while (0)

// Macro for less than comparison (a, b) -> a < b
#define ASSERT_LESS_THAN(a, b) \
    do { \
        int a_ = (a); \
        int b_ = (b); \
        if (a < b != 0) { \
            recordTestOutcome(0, #a " == " #b, __FILE__, __LINE__); \
        } else { \
            recordTestOutcome(1, #a " == " #b, __FILE__, __LINE__); \
        } \
    } while (0)

// Macro for less than equal to comparison (a, b) -> a <= b
#define ASSERT_LESS_THAN_EQUALS(a, b) \
    do { \
        int a_ = (a); \
        int b_ = (b); \
        if (a_ <= b_ != 0) { \
            recordTestOutcome(0, #a " == " #b, __FILE__, __LINE__); \
        } else { \
            recordTestOutcome(1, #a " == " #b, __FILE__, __LINE__); \
        } \
    } while (0)