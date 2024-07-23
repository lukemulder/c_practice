#include "stack_tests.h"
#include "asserts.h"
#include <stdlib.h>

static Stack* s;

static void StackTest_Setup() { }
static void StackTest_Teardown() { deleteStack(s); }

typedef void (*TestFunction)(void);

static void StackTest_Run(TestFunction testFunc)
{
  StackTest_Setup();
  testFunc();
  StackTest_Teardown();
}

/* TEST CASES */
static void StackTest_CreateDelete()
{
  s = createStack();

  ASSERT_TRUE(s != NULL);

  deleteStack(s);
  s = NULL;
}

static void StackTest_PushNULL()
{
  int value = 4;
  s = NULL;

  stackPush(s, value);
}

static void StackTest_PushPeakPop()
{
  int value = 4;

  s = createStack();

  ASSERT_TRUE(s != NULL);

  stackPush(s, value);

  ASSERT_TRUE(stackPeak(s) == value);

  ASSERT_TRUE(stackPop(s) == value);

  ASSERT_TRUE(stackPeak(s) == INT32_MAX);
}

/* SUITE */

void StackTestSuite_Run()
{
  StackTest_Run(StackTest_CreateDelete);
  StackTest_Run(StackTest_PushNULL);
  StackTest_Run(StackTest_PushPeakPop);
}