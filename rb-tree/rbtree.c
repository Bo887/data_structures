#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

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
	if (a < b) return -1;
	else if (a > b) return 1;
	else return 0;
}

static int is_red(Node* node){
	return node == NULL ? 0 : node->color == RED;
}

static int is_bst(Node* node, int low_bound, int upper_bound){
	if (node == NULL){
		return 1;	
	}
	if (compare(node->val, low_bound) < 0) return 0;
	if (compare(node->val, upper_bound) > 0) return 0;
	return is_bst(node->left, low_bound, node->val) && is_bst(node->right, node->val, upper_bound);
}

static int check_size(Node* node){
	if (node == NULL){
		return 0;
	}
	return 1 + check_size(node->left) + check_size(node->right);
}

//check left-leaning red-black tree properties
static int check_rbtree_property(Node* node, Node* root){
	if (node == NULL){
		return 1;
	}
	//no right-leaning red links
	if (is_red(node->right)) return 0;
	//make sure there's no 2 red links in a row
	if (node != root && is_red(node) && is_red(node->left)){
		return 0;	
	}
	return check_rbtree_property(node->left, root) && check_rbtree_property(node->right, root);
}

//check if the tree is balanced
static int check_balanced(Node* node, int height, int curr){
	if (node == NULL){
		return curr == height;
	}
	if (!is_red(node)) curr++;
	return check_balanced(node->left, height, curr) && check_balanced(node->right, height, curr);
}

static void check_tree(RBTree* this){
	assert(is_bst(this->root, INT_MIN, INT_MAX));
	assert(check_size(this->root) == size(this));
	assert(check_rbtree_property(this->root, this->root));

	//calculate black link height
	//the # black links from the root to any node should be equal
	int val = 0;
	Node* node = this->root;
	while(node != NULL){
		if (!is_red(node)) val++;	
		node = node->left;
	}
	assert(check_balanced(this->root, val, 0));
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
	right->color = right->left->color;
	right->left->color = RED;
	return right;
}

static Node* rotate_right(Node* node){
	Node* left = node->left;
	node->left = left->right;
	left->right = node;
	left->color = left->right->color;
	left->right->color = RED;
	return left;
}

static void flip_colors(Node* node){
	node->color = !node->color;
	node->right->color = !node->right->color;
	node->left->color = !node->left->color;
}

static Node* balance_tree(Node* node){
	if (is_red(node->right)){
		node = rotate_left(node);
	}
	//only rotate right if we can later flip both colors
	if (is_red(node->left) && is_red(node->left->left)){ 
		node = rotate_right(node);
	}
	if (is_red(node->left) && is_red(node->right)){
		flip_colors(node);
	}
	return node;
}

static Node* _insert(Node* node, int val){
	if (node == NULL){
		return create_node(val);
	}
	int cmp = compare(val, node->val);

	if (cmp < 0){
		node->left = _insert(node->left, val);
	}
	else if (cmp > 0){
		node->right = _insert(node->right, val);
	}
	else{
		node->val = val;
	}
	node = balance_tree(node);
	return node;
}

static void _print(Node* node){
	if (node == NULL) return;
	_print(node->left);
	printf("%d ", node->val);
	_print(node->right);
}

static int max_cmp(int a, int b){
	return a > b ? a : b;
}

static int _height(Node* node){
	if (node == NULL){
		return -1;
	}
	return 1 + max_cmp(_height(node->left), _height(node->right));
}

static int _contains(Node* node, int val){
	if (node == NULL){
		return 0;
	}
	if (node->val == val) return 1;
	return _contains(node->left, val) || _contains(node->right, val);
}

static Node* move_red_left(Node* node){
	flip_colors(node);
	if (is_red(node->right->left)){
		node->right = rotate_right(node->right);
		node = rotate_left(node);
		flip_colors(node);
	}
	return node;
}

static Node* move_red_right(Node* node){
	flip_colors(node);
	if (is_red(node->left->left)){
		node = rotate_right(node);
		flip_colors(node);
	}
	return node;
}

static Node* _min(Node* node){
	if (node->left == NULL){
		return node;
	}
	return _min(node->left);
}

static Node* _max(Node* node){
	if (node->right == NULL){
		return node;
	}
	return _max(node->right);
}

static Node* _delete_min(Node* node){
	if (node->left == NULL){
		free(node);
		return NULL;
	}
	if (!is_red(node->left) && !is_red(node->left->left)){
		node = move_red_left(node);
	}
	node->left = _delete_min(node->left);
	return balance_tree(node);
}

static Node* _delete_max(Node* node){
	if (is_red(node->left)){
		node = rotate_right(node);
	}
	if (node->right == NULL){
		free(node);
		return NULL;
	}
	if (!is_red(node->right) && !is_red(node->right->left)){
		node = move_red_right(node);
	}
	node->right = _delete_max(node->right);
	return balance_tree(node);
}

static Node* _delete(Node* node, int val){
	if (compare(val, node->val) < 0){
		if (!is_red(node->left) && !is_red(node->left->left)){
			node = move_red_left(node);
		}
		node->left = _delete(node->left, val);
	}
	else{
		if (is_red(node->left)){
			node = rotate_right(node);
		}
		//printf("DEBUG: %d\t%d\n", node->val, node->right->val);
		if (compare(val, node->val) == 0 && node->right == NULL){
			free(node);
			return NULL;
		}
		if (!is_red(node->right) && !is_red(node->right->left)){
			node = move_red_right(node);
		}
		if (compare(val, node->val) == 0){
			node->val = _min(node->right)->val;
			node->right = _delete_min(node->right);
		}
		else{
			node->right = _delete(node->right, val);
		}
	}
	return balance_tree(node);
}

void insert(RBTree* this, int val){
	if (contains(this, val)) return;
	this->root = _insert(this->root, val);	
	this->root->color = BLACK;
	this->m_size++;
	check_tree(this);
}

void delete_min(RBTree* this){
	if (!is_red(this->root->left) && !is_red(this->root->right)){
		this->root->color = RED;
	}
	this->root = _delete_min(this->root);
	this->m_size--;
	if (size(this) != 0){
		this->root->color = BLACK;
	}
	check_tree(this);
}

int min(RBTree* this){
	if (size(this) == 0) return INT_MIN;
	return _min(this->root)->val;
}

void delete_max(RBTree* this){
	if (!is_red(this->root->left) && !is_red(this->root->right)){
		this->root->color = RED;
	}
	this->root = _delete_max(this->root);
	this->m_size--;
	if (size(this) != 0){
		this->root->color = BLACK;
	}
	check_tree(this);
}

int max(RBTree* this){
	if (size(this) == 0) return INT_MAX;
	return _max(this->root)->val;
}

void delete(RBTree* this, int val){
	if (!contains(this, val)) return;
	if (!is_red(this->root->left) && !is_red(this->root->right)){
		this->root->color = RED;
	}
	this->root = _delete(this->root, val);
	this->m_size--;
	if (size(this) != 0){
		this->root->color = BLACK;
	}
	check_tree(this);
}

int height(RBTree* this){
	return _height(this->root);
}

int size(RBTree* this){
	return this->m_size;
}

int contains(RBTree* this, int val){
	return _contains(this->root, val);
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
