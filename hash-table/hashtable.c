#include "hashtable.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//djb2 hash function by Dan Bernstein
static long hash(char* key){
    long rv = 5381;
    int c;
    while((c = *key++)){
        rv = ((rv << 5) + rv) + c;
    }
    return rv;
}

HashTable* create(){
    HashTable* this = malloc(sizeof(HashTable));

    this->keys = malloc(sizeof(char*)*INITIAL_SIZE);
    this->vals = malloc(sizeof(int)*INITIAL_SIZE);

    this->table_size = INITIAL_SIZE;
    this->num_keys = 0;

    for(int i=0; i<this->table_size; i++){
        this->keys[i] = NULL;
        this->vals[i] = NULL;
    }

    return this;
}

void insert(HashTable* this, char* key, int val){
   int i = hash(key)%this->table_size;
   for(;this->keys[i] != NULL; i = (i+1)%this->table_size){
        if (strcmp(this->keys[i], key) == 0){
            this->vals[i] = val;
            return;
        }
   }
   this->keys[i] = key;
   this->vals[i] = val;
   this->num_keys++;
}

int size(HashTable* this){
    return this->num_keys;
}

void print(HashTable* this){
    printf("Size:%d ", this->num_keys);
    for(int i=0; i<this->table_size; i++){
        if (this->keys[i] != NULL){
            printf("(%s,%d) ", this->keys[i], this->vals[i]);
        }
    }
    printf("\n");
}

void destroy(HashTable** table){
    free((*table)->keys);
    free((*table)->vals);
    free(*table);
    (*table) = NULL;
}
