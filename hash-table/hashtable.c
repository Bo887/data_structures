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

static char** create_keys(char** keys, int old_size, int new_size){
    char** tmp = malloc(sizeof(char*)*new_size); 
    for(int i=0; i<new_size; i++){
        tmp[i] = NULL;
    }
    if (tmp){
         return tmp;
    }    
    printf("RESIZE KEYS FAILED!\n");
    return NULL;
}

static int* create_vals(int* vals, int old_size, int new_size){
    int* tmp = malloc(sizeof(int)*new_size);
    for(int i=0; i<old_size; i++){
        tmp[i] = vals[i];
    }
    if (tmp){
        return tmp;
    }
    printf("RESIZE VALS FAILED!\n");
    return NULL;
}

static void resize(HashTable* this, int new_size){
    char** new_keys = create_keys(this->keys, this->table_size, new_size);
    int* new_vals = create_vals(this->vals, this->table_size, new_size);

    //rehash all the keys when we resize
    for(int i=0; i<this->table_size; i++){
        if (this->keys[i] != NULL){
            int j = hash(this->keys[i])%new_size;
            for(; new_keys[j] != NULL; j = (j+1)%new_size){
                if (strcmp(new_keys[j], this->keys[i]) == 0){
                    new_vals[j] = this->vals[i];
                    break;
                }
            }
            new_keys[j] = this->keys[i];
            new_vals[j] = this->vals[i];
        }
    }

    char** realloced_keys = realloc(this->keys, sizeof(char*)*new_size);
    int* realloced_vals = realloc(this->vals, sizeof(int)*new_size);

    for(int i=0; i<new_size; i++){
        realloced_keys[i] = new_keys[i];
        realloced_vals[i] = new_vals[i];
    }

    free(new_keys);
    free(new_vals);
    this->keys = realloced_keys;
    this->vals = realloced_vals;
}

HashTable* create(int initial_size){
    HashTable* this = malloc(sizeof(HashTable));

    this->keys = malloc(sizeof(char*)*initial_size);
    this->vals = malloc(sizeof(int)*initial_size);

    this->table_size = initial_size;
    this->num_keys = 0;

    for(int i=0; i<this->table_size; i++){
        this->keys[i] = NULL;
        this->vals[i] = 0;
    }

    return this;
}

void insert(HashTable* this, char* key, int val){
    //resize array
    if (this->num_keys > this->table_size/2){
        resize(this, this->table_size*2);
        this->table_size*=2;
    }
    
    //compute hash value
    int i = hash(key)%this->table_size;

    //handle collision through linear probing
    for(; this->keys[i] != NULL; i = (i+1)%this->table_size){
        //if this key already exists, replace the value
         if (strcmp(this->keys[i], key) == 0){
             this->vals[i] = val;
             return;
         }
    }
    //otherwise, insert the key and value
    this->keys[i] = key;
    this->vals[i] = val;
    this->num_keys++;
}

int contains(HashTable* this, char* key){
    int i = hash(key)%this->table_size;
    for(; this->keys[i] != NULL; i = (i+1)%this->table_size){
        if (strcmp(this->keys[i], key) == 0){
            return 1;
        }
    }
    return 0;
}

int get(HashTable* this, char* key){
    int i = hash(key)%this->table_size;
    for(; this->keys[i] != NULL; i = (i+1)%this->table_size){
        if (strcmp(this->keys[i], key) == 0){
            return this->vals[i];
        }
    }
    return -1;
}

void delete(HashTable* this, char* key){
    if (!contains(this, key)){
        printf("Hash Table doesn't contain key %s\n", key);
        return;
    }
    int i = hash(key)%this->table_size;
    for(; strcmp(this->keys[i], key) != 0; i = (i+1)%this->table_size);
    this->keys[i] = NULL;
    this->vals[i] = -1;

    //rehash all the keys in the same group
    i = (i+1)%this->table_size;
    while(this->keys[i] != NULL){
        char* curr_k = this->keys[i];
        int curr_v = this->vals[i];
        this->keys[i] = NULL;
        this->vals[i] = -1;
        this->num_keys--;
        insert(this, curr_k, curr_v);
        i = (i+1)%this->table_size;
    }
    this->num_keys--;
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

void print_all(HashTable* this){
    printf("PrintAll: Size:%d ", this->table_size);
    for(int i=0; i<this->table_size; i++){
        if (this->keys[i] != NULL){
            printf("(%s,%d) ", this->keys[i], this->vals[i]);
        }
        else{
            printf("NULL ");
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
