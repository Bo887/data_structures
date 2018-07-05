#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef struct Node{
	struct Node* next;
	int val;
} Node;

typedef struct List{
	Node* start;

	int (*add)(int val);

	int (*delete)(int val);

	int (*size)(int val);

	int (*contains)(int val);
		
	int (*get)(int index);

	void (*display)();

} List;

List* create();

#endif
