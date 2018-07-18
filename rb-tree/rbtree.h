#ifndef RBTREE_H
#define RBTREE_H

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

typedef struct _Node Node;
typedef struct _RBTree RBTree;
typedef enum {RED, BLACK} Color;

struct _Node{
	int val;
	Node* left;
	Node* right;
	//color of the connection between this node and its parent
	Color color;
};

struct _RBTree{
	Node* root;
	int m_size;
};

void insert(RBTree* this, int val);

void delete(RBTree* this, int val);

void print(RBTree* this);

int height(RBTree* this);

int size(RBTree* this);

RBTree* create();

void destroy(RBTree** tree);
#endif
