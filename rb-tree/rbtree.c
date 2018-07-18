#include <stdlib.h>
#include <stdio.h>

#include "rbtree.h"

Node* create_node(int val){
	Node* node = malloc(sizeof(Node));
	node->val = val;
	node->color = RED;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int compare(int a, int b){
	return a > b;
}

static void destroy_node(Node* node){
	if (node == NULL) return;
	destroy_node(node->left);
	destroy_node(node->right);
	free(node);
	node = NULL;
}



static Node* rotate_left(Node* node){
	Node* right = node->right;
	node->right = right->left;
	right->left = node;
	right->color = node->color;
	node->color = RED;
	return right;
}

static Node* rotate_right(Node* node){
	Node* left = node->left;
	node->left = left->right;
	left->right = node;
	left->color = node->color;
	node->color = RED;
	return left;
}

static void flip_colors(Node* node){
	node->color = RED;
	node->right->color = BLACK;
	node->left->color = BLACK;
}

static int is_red(Node* node){
	return node == NULL ? 0 : node->color == RED;
}

static Node* balance_tree(Node* node){
	if (is_red(node->right) && !is_red(node->left)){
		node = rotate_left(node);
	}
	//only rotate right if we can later flip colors
	if (is_red(node->left) && is_red(node->left->left)){ 
		node = rotate_right(node);
	}
	if (is_red(node->left) && is_red(node->right)){
		flip_colors(node);
	}
	return node;
}

static Node* _insert(RBTree* this, Node* node, int val){
	if (node == NULL){
		return create_node(val);
	}
	int cmp = compare(val, node->val);

	if (cmp < 0){
		node->left = _insert(this, node->left, val);
	}
	else if (cmp > 0){
		node->right = _insert(this, node->right, val);
	}
	else{
		node->val = val;
	}

	//do rotations
	node = balance_tree(node);
	return node;
}

static void _print(Node* node){
	if (node == NULL) return;
	_print(node->left);
	printf("%d ", node->val);
	_print(node->right);
}

static int max(int a, int b){
	return a > b ? a : b;
}

static int _height(Node* node){
	if (node == NULL){
		return 0;
	}
	return 1 + max(_height(node->left), _height(node->right));
}

void insert(RBTree* this, int val){
	this->root = _insert(this, this->root, val);	
	this->m_size++;
}

void delete(RBTree* this, int val){
	this->m_size--;
}

int height(RBTree* this){
	return _height(this->root);
}

int size(RBTree* this){
	return this->m_size;
}

void print(RBTree* this){
	printf("Size: %d\n", size(this));
	_print(this->root);		
	printf("\n");
}

RBTree* create(){
	RBTree* tree = malloc(sizeof(RBTree));
	tree->root = NULL;
	tree->m_size = 0;
	return tree;
}

void destroy(RBTree** tree){
	destroy_node((*tree)->root);	
	free(*tree);
	*tree = NULL;
}
