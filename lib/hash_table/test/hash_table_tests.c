#include "hash_table_tests.h"
#include "asserts.h"
#include <stdlib.h>

static HashTable* ht;

static void HashTableTest_Setup() { }
static void HashTableTest_Teardown() { deleteHashTable(ht); }

typedef void (*TestFunction)(void);

static void HashTableTest_Run(TestFunction testFunc)
{
  HashTableTest_Setup();
  testFunc();
  HashTableTest_Teardown();
}

/* TEST CASES */
static void HashTableTest_CreateDelete()
{
  ht = createHashTable(100);

  ASSERT_TRUE(ht != NULL);

  deleteHashTable(ht);
  ht = NULL;
}

static void HashTableTest_InsertNullHT()
{
  int key = 10;
  int value = 4;
  ht = NULL;

  hashTableInsert(ht, key, value);
}

static void HashTableTest_InsertFind()
{
  int key = 10;
  int value = 4;
  HashNode* node;

  ht = createHashTable(10);

  ASSERT_TRUE(ht != NULL);

  hashTableInsert(ht, key, value);

  node = hashTableFind(ht, key);

  ASSERT_TRUE(node->value == value);
}

static void HashTableTest_FindNullHT()
{
  ht = NULL;

  HashNode* n = hashTableFind(ht, 10);

  ASSERT_TRUE(n == NULL);
}

static void HashTableTest_FindNull()
{
  ht = createHashTable(100);

  ASSERT_TRUE(ht != NULL);

  HashNode* n = hashTableFind(ht, 10);

  ASSERT_TRUE(n == NULL);
}

/* SUITE */

void HashTableTestSuite_Run()
{
  HashTableTest_Run(HashTableTest_CreateDelete);
  HashTableTest_Run(HashTableTest_InsertNullHT);
  HashTableTest_Run(HashTableTest_InsertFind);
  HashTableTest_Run(HashTableTest_FindNullHT);
  HashTableTest_Run(HashTableTest_FindNull);
}