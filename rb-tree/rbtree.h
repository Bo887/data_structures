#ifndef RBTREE_H
#define RBTREE_H

typedef struct _Node Node;
typedef struct _RBTree RBTree;
typedef enum {RED = 0, BLACK = 1} Color;

struct _Node{
	int val;
	Node* left;
	Node* right;
	//color of the connection between this node and its parent
	Color color;
};

//left leaning red-black tree
struct _RBTree{
	Node* root;
	int m_size;
};

void insert(RBTree* this, int val);

void delete_min(RBTree* this);

int min(RBTree* this);

void delete_max(RBTree* this);

int max(RBTree* this);

void delete(RBTree* this, int val);

int contains(RBTree* this, int val);

void print(RBTree* this);

int height(RBTree* this);

int size(RBTree* this);

RBTree* create();

void destroy(RBTree** tree);
#endif
