#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node{
	struct Node* next;
	struct Node* prev;
	int val;
};

typedef struct List List;

struct List{
	Node* start;
	Node* end;
	int m_size;
};

//adds the value to the front of the linked list
void push_front(List* this, int val);

//adds the value to the back of the linked list
void push_back(List* this, int val);

//deletes and returns the first element
//returns -1 on if list is empty
int pop_front(List* this);

//deletes and returns the last element
//returns -1 on if list is empty
int pop_back(List* this);

//deletes the first given instance of the specified value
//returns 0 on success, -1 on failure
int delete(List* this, int val);

int size(List* this);

//returns 1 if found, 0 if not found
int contains(List* this, int val);
	
//returns the value at the specified index 
//returns -1 if the index is out of range
int get(List* this, int index);

//prints the list in a single line format
void print(List* this);

//creates an empty list
List* create();

//destroys the list
void destroy(List** this);

#endif
