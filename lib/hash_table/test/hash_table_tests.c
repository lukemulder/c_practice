#include "hash_table_tests.h"
#include "asserts.h"
#include <stdlib.h>

static HashTable* ht;

static void HashTableTest_Setup()
{
  ht = (HashTable*)malloc(sizeof(HashTable));
}

static void HashTableTest_Teardown()
{
  free(ht);
}

static void HashTableTest_AddElement()
{
  ASSERT_TRUE(1);
}

typedef void (*TestFunction)(void);

static void HashTableTest_Run(TestFunction testFunc)
{
  HashTableTest_Setup();
  testFunc();
  HashTableTest_Teardown();
}

void HashTableTestSuite_Run()
{
  HashTableTest_Run(HashTableTest_AddElement);
}