#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

#define INITIAL_SIZE 10
typedef struct _HashTable HashTable;

struct _HashTable{
    char** keys;
    int* vals;

    int table_size;
    int num_keys;
};

void insert(HashTable* this, char* key, int val);

int contains(HashTable* this, char* key);

void* find(HashTable* this, char* key);

void delete(HashTable* this, char* key);

int size(HashTable* this);

void print(HashTable* this);

HashTable* create();

void destroy(HashTable** table);

#endif
