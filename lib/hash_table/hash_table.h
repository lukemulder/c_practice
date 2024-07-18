#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Node for the linked list (bucket)
typedef struct HashNode {
    int key; // Key of the node
    int value; // Value associated with the key
    struct HashNode *next; // Pointer to the next node in the bucket
} HashNode;

// Hash table structure
typedef struct HashTable {
    HashNode **node_list; // Array of pointers to bucket nodes
    int size; // Number of buckets in the hash table
    int count; // Number of key-value pairs stored in the hash table
} HashTable;

// Function to create a new hash table
// @param size The initial size of the hash table
// @return Pointer to the newly created hash table
HashTable* createHashTable(int size);

// Function to delete a hash table
// @param table The hash table to delete
void deleteHashTable(HashTable *table);

// Function to insert a key-value pair into the hash table
// @param table The hash table
// @param key The key associated with the value
// @param value The value to insert
void hashTableInsert(HashTable *table, int key, int value);

// Function to remove a key-value pair from the hash table
// @param table The hash table
// @param key The key of the pair to remove
void hashTableRemove(HashTable *table, int key);

// Function to retrieve a value from the hash table by its key
// @param table The hash table
// @param key The key of the value to retrieve
// @return The value associated with the key, or NULL if the key is not found
HashNode* hashTableFind(HashTable *table, int key);

#endif // HASH_TABLE_H