#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

// Private function hashing function for the hash table
// @param key The key associated with the value being hashed
// @param size The initial size of the hash table
// @return Index of the hash table for the key provided
static int hashFunction(int key, int size)
{
    int hash = key % size;

    if(hash < 0)
        hash += size;

    return hash;
}

// Function to create a new hash table
// @param size The initial size of the hash table
// @return Pointer to the newly created hash table
HashTable* createHashTable(int size)
{
    if(size <= 0) { return NULL; }

    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));

    if(ht == NULL) { return NULL; }

    ht->node_list = (HashNode**)malloc(sizeof(HashNode*) * size);

    if(ht->node_list == NULL) { free(ht); return NULL; }

    ht->size = size;
    ht->count = 0;

    for(int i = 0; i < size; i++)
    {
        ht->node_list[i] = NULL;
    }

    return ht;
}

// Function to delete a hash table
// @param table The hash table to delete
void deleteHashTable(HashTable *table)
{
    if(table == NULL)
        return;

    HashNode* node;

    for(int i = 0; i < table->size; i++)
    {
        node = table->node_list[i];

        while(node != NULL)
        {
            HashNode* temp = node;

            node = node->next;
            free(temp);
        }
    }

    free(table->node_list);
    free(table);
}

// Function to insert a key-value pair into the hash table
// @param table The hash table
// @param key The key associated with the value
// @param value The value to insert
void hashTableInsert(HashTable *table, int key, int value)
{
    if(table == NULL) { return; }

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));

    if(newNode == NULL) { return; }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    table->count++;

    HashNode* node;
    int index = hashFunction(key, table->size);

    if(table->node_list[index] == NULL)
    {
        table->node_list[index] = newNode;
    }
    else
    {
        node = table->node_list[index];
        while(node->next != NULL)
        {
            node = node->next;
        }
        node->next = newNode;
    }
}

// Function to remove a key-value pair from the hash table
// @param table The hash table
// @param key The key of the pair to remove
void hashTableRemove(HashTable *table, int key)
{
    if(table == NULL) { return; }

    int index;
    HashNode* node;

    index = hashFunction(key, table->size);
    node = table->node_list[index];

    if(node != NULL && node->key == key)
    {
        table->node_list[index] = node->next;
        table->count--;

        free(node);

        return;
    }

    HashNode* head = node;
    node = node->next;

    while(node != NULL)
    {
        if(node->key == key)
        {
            head->next = node->next;

            free(node);
            return;
        }

        head = node;
        node = node->next;
    }
}

// Function to retrieve a value from the hash table by its key
// @param table The hash table
// @param key The key of the value to retrieve
// @return The value associated with the key, or NULL if the key is not found
HashNode* hashTableFind(HashTable *table, int key)
{
    if(table == NULL) { return NULL; }

    int index;
    HashNode* node;

    index = hashFunction(key, table->size);
    node = table->node_list[index];

    while(node != NULL)
    {
        if(node->key == key)
            return node;
        
        node = node->next;
    }

    return NULL;
}
