#ifndef BST_H
#define BST_H

typedef struct _Node Node;
typedef struct _BST BST;
typedef enum {INT, DOUBLE, STRING} Type;

struct _Node{
	void* key;
	void* val;
	Node* left;
	Node* right;
};

struct _BST{
	Node* root;
	Type key_type;
	Type val_type;
	int m_size;
	int (*compare)(void* this, void* other);
};

void insert(BST* bst, void* key, void* val);

void* find(BST* bst, void* key);

void delete(BST* bst, void* key);

int size(BST* bst);

void print(BST* bst);

BST* create(Type key_type, Type val_type, int (*compare)(void* this, void* other));

void destroy(BST** bst);

#endif
