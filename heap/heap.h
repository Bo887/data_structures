#ifndef HEAP_H
#define HEAP_H

#define INITIAL_SIZE 10

typedef enum {MAX, MIN} Type;
typedef struct _Heap Heap;

struct _Heap{
	Type type;
	int* arr;
	int curr_size;
};

int* double_arr(int* arr, int new_size);
int* halve_arr(int* arr, int new_size);

void push(Heap* this, int p);

//returns maximum value if type is max
//returns minimum value if type is min
int top(Heap* this);

//deletes top element and returns it
int pop(Heap* this);

//size of the heap
int size(Heap* this);

Heap* create(Type type);

void destroy(Heap** heap);

#endif
