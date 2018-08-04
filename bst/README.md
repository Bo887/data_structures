# Unbalanced Binary Search Tree
Implements an ordered symbol table using an unbalanced binary search tree. Supports ```char*```, ```double```, and ```int``` types for both keys and values. To make this generic, data types are passed and returned through ```void*```, so the user will have to make some manual casts.

**Operations:**
- ```void insert(BST* bst, void* key, void* val)```
- ```void* find(BST* bst, void* key)```
- ```void delete(BST* bst, void* key)```
- ```int size(BST* bst)```
- ```void print(BST* bst)```
    - ```prints the bst from left to right (increasing order)```
- ```BST* create(Type key_type, Type val_type, int (*compare)(void* this, void* other))```
    - ```Type is one of the following: INT, DOUBLE, STRING```
    - ```*compare is a function pointer for comparison, with an example below```
- ``` void destroy(BST** bst)```

**Example:**
```
#include "bst.h"

//for strcmp
#include <string.h>

//comparison function for a string key
int compare(void* this, void* other){
    return strcmp((char*) this, (char*) other);
}

int main(){
    //create a bst with key type string (char*), and value type int
    BST* bst = create(STRING, INT, compare);

    int nums[10];
    for(int i=0; i<10; i++){
        nums[i] = i;
    }

    //insert the following into the bst: ("HELLO", 8);
    insert(bst, "HELLO", &nums[8]); 
    //insert the following into the bst: ("APPLE", 1);
    insert(bst, "APPLE", &nums[1]);
    //insert the following into the bst: ("BEAR", 2);
    insert(bst, "BEAR", &nums[2]);

    //returns 3
    size(bst);

    int* rv = (int*)find(bst, "APPLE");
    //(*rv) is now 1  

    rv = (int*)find(bst, "HELLO");
    //(*rv) is now 8

    rv = (int*)find(bst, "BEAR");
    //(*rv) is now 2

    //deletes "APPLE"
    delete(bst, "APPLE");
    //returns 2
    size(bst); 

    //frees the memory used by bst, and bst is set to NULL
    destroy(&bst);
    return 0;
}
```
