#include "hashtable.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(){
	HashTable* test = create(1);
        
        char* keys[] = {"APPLE", "FROG", "BEAR", "GHOST", "TREE", "COW", "HAM", "JAGUAR", "PIRATE", "DOG", "CHICKEN", "EGGPLANT", "WAVE", "ZEBRA", "KEY"};

        print(test);
    
        for(int i=0; i<15; i++){
            insert(test, keys[i], i);
            assert(size(test) == i+1);
        }

        print(test);
        printf("\n");
        print_all(test);

        for(int i=0; i<15; i++){
            assert(contains(test, keys[i]) == 1);
        }

        for(int i=0; i<15; i++){
            assert(get(test, keys[i]) == i);
        }

        for(int i=0; i<15; i++){
            delete(test, keys[i]);
            assert(size(test) == 15-1-i);
        }
        print_all(test);
        print(test);

	destroy(&test);
	assert(test==NULL);
	return 0;
}
