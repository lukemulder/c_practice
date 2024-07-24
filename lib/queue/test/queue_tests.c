#include "queue_tests.h"
#include "asserts.h"
#include <stdlib.h>

static Queue* q;

static void QueueTest_Setup() { }
static void QueueTest_Teardown() { deleteQueue(q); }

typedef void (*TestFunction)(void);

static void QueueTest_Run(TestFunction testFunc)
{
  QueueTest_Setup();
  testFunc();
  QueueTest_Teardown();
}

/* TEST CASES */
static void QueueTest_CreateDelete()
{
  q = createQueue();

  ASSERT_TRUE(q != NULL);

  deleteQueue(q);
  q = NULL;
}

static void QueueTest_EnqueueNULL()
{
  int value = 4;
  q = NULL;

  queueEnqueue(q, value);
}

static void QueueTest_EnqueuePeakDequeue()
{
  int value = 4;

  q = createQueue();

  ASSERT_TRUE(q != NULL);

  queueEnqueue(q, value);

  ASSERT_TRUE(queuePeak(q) == value);

  ASSERT_TRUE(queueDequeue(q) == value);

  ASSERT_TRUE(queuePeak(q) == INT32_MAX);
}

static void QueueTest_EnqueueOrder()
{
  int v1 = 4;
  int v2 = 39;

  q = createQueue();

  ASSERT_TRUE(q != NULL);

  queueEnqueue(q, v1);
  queueEnqueue(q, v2);

  ASSERT_TRUE(queuePeak(q) == v1);

  ASSERT_TRUE(queueDequeue(q) == v1);

  ASSERT_TRUE(queuePeak(q) == v2);

  ASSERT_TRUE(queueDequeue(q) == v2);
}

/* SUITE */

void QueueTestSuite_Run()
{
  QueueTest_Run(QueueTest_CreateDelete);
  QueueTest_Run(QueueTest_EnqueueNULL);
  QueueTest_Run(QueueTest_EnqueuePeakDequeue);
  QueueTest_Run(QueueTest_EnqueueOrder);
}