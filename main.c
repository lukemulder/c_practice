#include <stdio.h>
#include <stdlib.h>
#include "lib/hash_table/test/hash_table_tests.h"
#include "lib/stack/test/stack_tests.h"

int main()
{
  HashTableTestSuite_Run();
  StackTestSuite_Run();

  return EXIT_SUCCESS;
}