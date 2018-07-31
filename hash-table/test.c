#include "hashtable.h"

#include <stdlib.h>
#include <assert.h>

int main(){
	HashTable* test = create();
        print(test);
        insert(test, "HELLO", 1);
        print(test);
        insert(test, "BYE", 2);
        print(test);
        insert(test, "BYE", 4);
        print(test);
	destroy(&test);
	assert(test==NULL);
	return 0;
}
