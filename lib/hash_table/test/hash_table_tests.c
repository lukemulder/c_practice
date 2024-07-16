#include "hash_table_tests.h"
#include "asserts.h"
#include <stdlib.h>

static HashTable* ht;

static void HashTableTest_Setup() { }
static void HashTableTest_Teardown() { free(ht); }

typedef void (*TestFunction)(void);

static void HashTableTest_Run(TestFunction testFunc)
{
  HashTableTest_Setup();
  testFunc();
  HashTableTest_Teardown();
}

/* TEST CASES */
static void HashTableTest_AddElement()
{
  ht = createHashTable(100);

  ASSERT_TRUE(ht != NULL);
}

HashTable* createHashTable(int size);
void deleteHashTable(HashTable *table);
void hashTableInsert(HashTable *table, int key, int value);
void hashTableRemove(HashTable *table, int key);
HashNode* hashTableGet(HashTable *table, int key);


/* SUITE */

void HashTableTestSuite_Run()
{
  HashTableTest_Run(HashTableTest_AddElement);
}