#ifndef TEST_FRAMEWORK_HEADER
#define TEST_FRAMEWORK_HEADER

typedef enum {
    OUTPUT_PRINTF = 0,
    OUTPUT_FILE
} OutputType;

typedef enum {
    TEST_PASSED = 0,
    TEST_FAILED
} TestResult;

typedef TestResult (*TestFunction)(void);
typedef void (*TestSetupFunc)(void);
typedef void (*TestTeardFunc)(void);

typedef struct {
    char* testName;
    TestFunction testFunc;
    TestSetupFunc setupFunc;
    TestTeardFunc tearDFunc;
} Test;

typedef struct TestSuite {
    char* suiteName;
    Test* tests;
    int numTests;
} TestSuite;

typedef struct TestReport {
    char* suiteName;
    int testsPassed;
    int testsFailed;
    int totalTests;
} TestReport;

void TestFramework_Initialize(OutputType type, char* fileName);

void TestFramework_AddSuite(TestSuite* suite);

void TestFramework_RemoveSuite(TestSuite* suite);

void TestFramework_RunAllSuites();

void TestFramework_Cleanup();

#endif