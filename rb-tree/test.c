#include <assert.h>
#include <stdio.h>

#include "rbtree.h"

int main(){
	RBTree* tree = create();
	print(tree);
	assert(tree != NULL);
	assert(size(tree) == 0);

	//insert in increasing order, the worst case for unbalanced bsts
	insert(tree, 1);
	print(tree);
	insert(tree, 2);
	print(tree);
	assert(height(tree) == 2);
	insert(tree, 3);
	insert(tree, 4);
	insert(tree, 5);
	insert(tree, 6);
	insert(tree, 7);
	//the height for an unbalanced bst would be 7, but for a r-b bst would be 3
	assert(height(tree) == 3);
	assert(size(tree) == 7);
	print(tree);

	//delete min
	assert(min(tree) == 1);
	delete_min(tree);
	print(tree);
	assert(min(tree) == 2);
	delete_min(tree);
	print(tree);
	assert(min(tree) == 3);
	delete_min(tree);
	print(tree);

	//test re-inserting	
	insert(tree, 1);
	insert(tree, 3);
	insert(tree, 2);
	print(tree);

	assert(max(tree) == 7);
	delete_max(tree);
	print(tree);
	assert(max(tree) == 6);
	delete_max(tree);
	print(tree);
	assert(max(tree) == 5);
	delete_max(tree);
	print(tree);

	insert(tree, 7);
	insert(tree, 6);
	insert(tree, 5);
	print(tree);

	for(int i=1; i<=7; i++){
		assert(contains(tree, i) != 0);
	}
	assert(contains(tree, 0) == 0);
	assert(contains(tree, 8) == 0);

	printf("\n");

	delete(tree, 4);
	print(tree);
	delete(tree, 7);
	print(tree);
/*
	delete(tree, 1);
	print(tree);
	delete(tree, 1);
	print(tree);

	insert(tree, 7);
	insert(tree, 4);
	insert(tree, 1);
	print(tree);

	delete(tree, 7);
	delete(tree, 1);
	delete(tree, 2);
	delete(tree, 3);
	delete(tree, 6);
	delete(tree, 5);
	delete(tree, 4);
	*/

	destroy(&tree);
	assert(tree == NULL);
	return 0;
}
