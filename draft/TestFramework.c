#include "TestFramework.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TestSuiteNode
{
    TestSuite* suite;
    struct TestSuiteNode* next;
} TestSuiteNode;

static TestSuiteNode* suites;
static int numSuites;

void TestFramework_Initialize(OutputType type, char* fileName)
{
    suites = NULL;
    numSuites = 0;
}

void TestFramework_AddSuite(TestSuite* suite)
{
    TestSuiteNode* newNode = (TestSuiteNode*)malloc(sizeof(TestSuiteNode));
    TestSuiteNode* tail = suites;

    newNode->suite = suite;
    newNode->next = NULL;

    if(tail == NULL)
    {
        suites = newNode;
        numSuites++;
        return;
    }

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    numSuites++;
}

void TestFramework_RemoveSuite(TestSuite* suite)
{
    TestSuiteNode* node = suites;
    TestSuiteNode* nodeNext;

    if(node == NULL)
        return;

    if(node->suite == suite)
    {
        suites = suites->next;
        free(node);
        numSuites--;
        return;
    }

    nodeNext = node->next;

    while(nodeNext != NULL)
    {
        if(nodeNext->suite == suite)
        {
            node->next = nodeNext->next;
            free(nodeNext);
            numSuites--;
            return;
        }

        node = nodeNext;
        nodeNext = nodeNext->next;
    }
}

static void TestFramework_PrintTestReport(TestReport report)
{
    printf("*******************************\n");
    printf("TEST SUITE:   %s\n", report.suiteName);
    printf("*******************************\n");
    printf("TOTAL TESTS:   %d\n", report.totalTests);
    printf("TESTS PASSED: (%d/%d)\n", report.testsFailed, report.totalTests);
    if(report.testsFailed > 0)
    {
        printf("FAILURES!\n");
        printf("TESTS FAILED:  %d\n", report.testsFailed);
    }
    printf("*******************************\n");
}

void TestFramework_RunAllSuites()
{
    TestSuiteNode* currSuite = suites;
    while(currSuite != NULL)
    {
        TestReport report = {0}; // Initialize report
        report.suiteName = (currSuite->suite)->suiteName;
        for (int i = 0; i < (currSuite->suite)->numTests; ++i) {
            Test currentTest = (currSuite->suite)->tests[i];
            printf("RUNNING TEST: %s\n", currentTest.testName);
            currentTest.setupFunc();
            TestResult result = currentTest.testFunc();
            currentTest.tearDFunc();
            if (result == TEST_PASSED) {
                report.testsPassed++;
            } else {
                report.testsFailed++;
            }
        }
        report.totalTests = (currSuite->suite)->numTests;
        TestFramework_PrintTestReport(report);

        currSuite = currSuite->next;
    }
}

void TestFramework_Cleanup()
{
    TestSuiteNode* node = suites;
    TestSuiteNode* nodeNext;

    while(node != NULL)
    {
        nodeNext = node->next;
        free(node);

        node = nodeNext;
    }
}