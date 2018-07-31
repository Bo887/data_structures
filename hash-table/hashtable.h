#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct _HashTable HashTable;

struct _HashTable{
	void* key;
	void* val;
	int m_size;
	int (*hash)(void* key);
};

void insert(HashTable* this, void* key, void* val);

int contains(HashTable* this, void* key);

void* find(HashTable* this, void* key);

void delete(HashTable* this, void* key);

int size(HashTable* this);

void print(HashTable* this);

HashTable* create(size_t key_size, size_t val_size, int (*hash)(void* key));

void destroy(HashTable** table);

#endif
