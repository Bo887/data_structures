#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "bst.h"

int compare(void* this, void* other){
	return strcmp((char*)this, (char*)other);
}

int main(){
	BST* bst = create(STRING, INT, compare);
	int nums[27];
	for(int i=1; i<=26; i++){
		nums[i] = i;
	}
	print(bst);
	insert(bst, "HELLO", &nums[8]);
	print(bst);
	insert(bst, "APPLE", &nums[1]);
	print(bst);
	insert(bst, "BEAR", &nums[2]);
	print(bst);
	assert(size(bst) == 3);

	int* rv = (int*)find(bst, "APPLE");
	assert(*rv == 1);
	rv = (int*)find(bst, "HELLO");
	assert(*rv == 8);
	rv = (int*)find(bst, "BEAR");
	assert(*rv == 2);
	rv = (int*)find(bst, "FAIL");
	assert(rv == NULL);

	delete(bst, "APPLE");
	print(bst);
	delete(bst, "HELLO");
	print(bst);
	delete(bst, "BEAR");
	print(bst);
	assert(size(bst) == 0);

	destroy(&bst);
	assert(bst == NULL);
	return 0;
}
