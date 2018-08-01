# Hash Table
A hash table implementation in C. 

Using linear probing to handle collisions.

Supports string keys and integer values and automatic resizing.

**Operations:**
- ```void insert(HashTable* table, char* key, int val)```
- ```int contains(HashTable* table, char* key)```
- ```int get(HashTable* table, char* key)```
- ```void delete(HashTable* table, char* key)```
- ```int size(HashTable* table)```
- ```void print(HashTable* table)```
- ```HashTable* create(int initial_size)```
- ```void destroy(HashTable** table)```

**Example:**
```
#include "hashtable.h"

int main(){
    //create a hashtable with an initial size of 10
    HashTable* table = create(10);

    //keys for testing
    char* keys[] = {"APPLE", "FROG", "BEAR", "GHOST", "TREE", "COW", "HAM", "JAGUAR", "PIRATE", "DOG", "CHICKEN", "EGGPLANT", "WAVE", "ZEBRA", "KEY"};

    for(int i=0; i<15; i++){
        //insert {keys[i], i} into hashtable
        insert(table, keys[i], i);
    }

    //returns 15
    size(table);

    //returns 1 (true)
    contains(table, "ZEBRA");
    //returns 0 (false)
    contains(table, "GOAT");
    
    //returns 0 ("APPLE"'s value is 0)
    get(table, "APPLE");
    //returns 14 ("KEY"'s value is 14)
    get(table, "KEY");
    //returns -1 ("MONKEY" is not in the table)
    get(table, "MONKEY");

    //removes "APPLE"
    delete(table, "APPLE");
    //returns -1 ("APPLE" is no longer in the table)
    get(table, "APPLE");

    //returns 14
    size(table);

    //free the memory used by table
    destroy(&table);
    return 0;
}
```
