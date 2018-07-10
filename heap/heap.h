#ifndef HEAP_H
#define HEAP_H

#define INITIAL_SIZE 10

typedef enum {MAX, MIN} Type;
typedef struct _Heap Heap;

struct _Heap{
	Type type;
	int* arr;
	int num_elem;
	int curr_max_size;
};

int* double_arr(int* arr, int new_size);
int* halve_arr(int* arr, int new_size);
void swap(int* arr, int a, int b);

void push(Heap* this, int p);

//returns maximum value if type is max
//returns minimum value if type is min
int top(Heap* this);

//deletes top element and returns it
int pop(Heap* this);

//size of the heap
int size(Heap* this);

//prints out the heap array, where node n's children are at 2*n && 2*n+1 and where n's parent is n/2
void print(Heap* this);

Heap* create(Type type);

void destroy(Heap** heap);

#endif
