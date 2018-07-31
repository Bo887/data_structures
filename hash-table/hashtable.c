#include "hashtable.h"

#include <stdlib.h>
#include <stdio.h>

HashTable* create(size_t key_size, size_t val_size, int (*hash)(void* key)){
	HashTable* this = malloc(sizeof(HashTable));
	void** keys = malloc(key_size*INITIAL_SIZE);
	void** vals = malloc(val_size*INITIAL_SIZE);
	this->keys = keys;
	this->vals = vals;
	this->m_size = INITIAL_SIZE;
	this->hash = hash;
	return this;
}

void destroy(HashTable** table){
	free((*table)->keys);
	free((*table)->vals);
	free(*table);
	(*table) = NULL;
}
