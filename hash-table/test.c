#include "hashtable.h"

#include <assert.h>

int main(){
	HashTable* test = create(sizeof(char*), sizeof(int), NULL);
	destroy(&test);
	assert(test==NULL);
	return 0;
}
