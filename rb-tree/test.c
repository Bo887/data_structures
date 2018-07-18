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


	destroy(&tree);
	assert(tree == NULL);
	return 0;
}
