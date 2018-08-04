#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bst.h"

static Node* create_node(void* key, void* val){
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

static void destroy_node(Node* node){
	if (node == NULL) return;
	destroy_node((node)->left);
	destroy_node((node)->right);
	free(node);
	node = NULL;
}

static void _print(BST* bst, Node* node){
	if (node == NULL) return;	
	_print(bst, node->left);
	if (bst->key_type == INT){
		printf("%d ", *(int*)node->key);
	}
	else if (bst->key_type == DOUBLE){
		printf("%f ", *(double*)node->key);
	}
	else if (bst->key_type == STRING){
		printf("%s ", (char*)node->key);
	}
	else assert(0);
	_print(bst, node->right);
}

static Node* _insert(BST* bst, Node* node, void* key, void* val){
	//base case where the node is null, so create a node and put the node here
	if (node == NULL){
		return create_node(key, val);
	}	
	int cmp = bst->compare(key, node->key);
	//go to left child
	if (cmp < 0){
		node->left = _insert(bst, node->left, key, val);
	}
	//go to right child
	else if (cmp > 0){
		node->right = _insert(bst, node->right, key, val);
	}
	//otherwise, the key being inserted is the same as the key of the current node
	//so just update the value
	else{
		node->val = val;
	}
	return node;
}

static Node* _delete(BST* bst, Node* curr, void* key){
	if (curr == NULL){
		return NULL;
	}
	int cmp = bst->compare(key, curr->key);
	if (cmp < 0){
		curr->left = _delete(bst, curr->left, key);
	}
	else if (cmp > 0){
		curr->right = _delete(bst, curr->right, key);
	}
	//we found the right key, so break out of the recursion
	else{
		if (curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		else if (curr->right == NULL){
			Node* copy = curr->left;
			free(curr);
			return copy;
		}
		else if (curr->left == NULL){
			Node* copy = curr->right;
			free(curr);
			return copy;
		}
		else{
		}
	}
	return curr;
}

void insert(BST* bst, void* key, void* val){
	bst->root = _insert(bst, bst->root, key, val);
	bst->m_size++;
}

void* find(BST* bst, void* key){
	Node* curr = bst->root;
	while(curr != NULL){
		int cmp = bst->compare(key, curr->key);	
		if (cmp < 0){
			curr = curr->left;
		}
		else if (cmp > 0){
			curr = curr->right;	
		}
		else{
			return curr->val;
		}
	}
	//not found
	return NULL;
}

void delete(BST* bst, void* key){
	bst->root = _delete(bst, bst->root, key);
	bst->m_size--;
}

int size(BST* bst){
	return bst->m_size;
}

void print(BST* bst){
	printf("BST: ");
	_print(bst, bst->root);	
	printf("\n");
}

BST* create(Type key_type, Type val_type, int (*compare)(void* this, void* other)){
	BST* bst = malloc(sizeof(BST));
	bst->root = NULL;
	bst->key_type = key_type;
	bst->val_type = val_type;
	bst->m_size = 0;
	bst->compare = compare;
	return bst;
}

void destroy(BST** bst){
	destroy_node(((*bst)->root));
	free(*bst);
	*bst = NULL;
}
