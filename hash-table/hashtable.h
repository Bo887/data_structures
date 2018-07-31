#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct _HashTable HashTable;

struct _HashTable{
    char** keys;
    int* vals;

    int table_size;
    int num_keys;
};

void insert(HashTable* this, char* key, int val);

int contains(HashTable* this, char* key);

int get(HashTable* this, char* key);

void delete(HashTable* this, char* key);

int size(HashTable* this);

void print(HashTable* this);

void print_all(HashTable* this);

HashTable* create(int initial_size);

void destroy(HashTable** table);

#endif
