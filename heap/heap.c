#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "heap.h"

static int* double_arr(int* arr, int new_size){
	int* tmp = realloc(arr, sizeof(int)*new_size);
	if (tmp){
		return tmp;
	}
	printf("ERROR!\n");
	return NULL;
}

static int* halve_arr(int* arr, int new_size){
	int* tmp = realloc(arr, sizeof(int)*new_size);
	if (tmp){
		return tmp;
	}
	printf("ERROR!\n");
	return NULL;
}

//if max heap, returns true is a is less than b
//if min heap, returns true if a is greater than b
static int cmp(Type type, int a, int b){
	if (type == MAX){
		return a < b;
	}
	else{
		return a > b;
	}
}

static void swap(int* arr, int idx_a, int idx_b){
	int copy = arr[idx_a];
	arr[idx_a] = arr[idx_b];
	arr[idx_b] = copy;
}

//makes this element swim towards the top of the heap
static void swim(Heap* this, int id){
	//if type is max heap, keep on looping while the element is less than its parent
	//if type is min heap, keep on looping while the element is greater than its parent
	while(id > 1 && cmp(this->type, this->arr[id/2], this->arr[id])){
		swap(this->arr, id/2, id);
		id/=2;
	}
}

static void sink(Heap* this, int id){
	while(2*id <= this->num_elem){
		int child = 2*id;
		//decide which child to go to
		if (child < this->num_elem && cmp(this->type, this->arr[child], this->arr[child+1])){
			child++;
		}
		//if heap conditions are no longer violated, break
		if (!cmp(this->type, this->arr[id], this->arr[child])){
			break;
		}
		//otherwise exchange elements and continue
		swap(this->arr, id, child);
		id = child;
	}
}

static int is_heap_ordered(Heap* this, int id){
	if (id > this->num_elem) return 1;
	int child_l = 2*id;
	if (child_l <= this->num_elem){
		if (cmp(this->type, this->arr[id], this->arr[child_l])){
			return 0;
		}
		else return is_heap_ordered(this, child_l);
	}
	int child_r = child_l+1;
	if (child_r <= this->num_elem){
		if (cmp(this->type, this->arr[id], this->arr[child_r])){
			return 0;
		}
		else return is_heap_ordered(this, child_r);
	}
}

int test_functions(){
	//test resize array
	int* arr = malloc(sizeof(int)*10);
	for(int i=0; i<10; i++){
		arr[i] = i;
	}
	for(int i=0; i<10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	arr = double_arr(arr, 20);
	for(int i=10; i<20; i++){
		arr[i] = i;
	}
	for(int i=0; i<20; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	arr = halve_arr(arr, 10);
	for(int i=0; i<10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	
	//test swap
	arr = malloc(sizeof(int)*8);
	arr[0] = 2;
	arr[7] = 3;
	swap(arr, 0, 7);
	assert(arr[0] == 3);
	assert(arr[7] == 2);
	free(arr);
}

void push(Heap* this, int p){
	if (this->num_elem >= this->curr_max_size-1){
		this->curr_max_size*=2;
		this->arr = double_arr(this->arr, this->curr_max_size);
	}
	this->num_elem++;
	this->arr[this->num_elem] = p;
	swim(this, this->num_elem);
	assert(is_heap_ordered(this, 1));
}

int top(Heap* this){
	return this->arr[1];
}

int pop(Heap* this){
	int val = this->arr[1];
	swap(this->arr, 1, this->num_elem);
	this->num_elem--;
	sink(this, 1);
	if (this->num_elem <= this->curr_max_size/4){
		this->curr_max_size/=2;
		this->arr = halve_arr(this->arr, this->curr_max_size);
	}
	assert(is_heap_ordered(this, 1));
	return val;
}

int size(Heap* this){
	return this->num_elem;
}

void print(Heap* this){
	printf("HEAP: ");
	for(int i=1; i<=this->num_elem; i++){
		printf("%d ", this->arr[i]);
	}
	printf("\n");
}

Heap* create(Type type){
	Heap* heap = malloc(sizeof(Heap));
	//1 based indexing
	int* arr = malloc(sizeof(int)*INITIAL_SIZE+1);
	heap->type = type;
	heap->curr_max_size = INITIAL_SIZE;
	heap->num_elem= 0;
	heap->arr = arr;
}

void destroy(Heap** heap){
	free((*heap)->arr);
	(*heap)->arr = NULL;
	free(*heap);
	(*heap) = NULL;
}
