#include <stdio.h>
#include <stdlib.h>
#include "lib/hash_table/test/hash_table_tests.h"
#include "lib/stack/test/stack_tests.h"
#include "lib/queue/test/queue_tests.h"

int main()
{
  HashTableTestSuite_Run();
  StackTestSuite_Run();
  QueueTestSuite_Run();

  return EXIT_SUCCESS;
}