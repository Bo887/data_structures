#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

int* double_arr(int* arr, int new_size){
	int* tmp = realloc(arr, sizeof(int)*new_size);
	if (tmp){
		return tmp;
	}
	printf("ERROR!\n");
	return NULL;
}

int* halve_arr(int* arr, int new_size){
	int* tmp = realloc(arr, sizeof(int)*new_size);
	if (tmp){
		return tmp;
	}
	printf("ERROR!\n");
	return NULL;
}

Heap* create(Type type){
	Heap* heap = malloc(sizeof(Heap));
	int* arr = malloc(sizeof(int)*INITIAL_SIZE);
	heap->type = type;
	heap->curr_size = INITIAL_SIZE;
	heap->arr = arr;
}

void destroy(Heap** heap){
	free((*heap)->arr);
	(*heap)->arr = NULL;
	free(*heap);
	(*heap) = NULL;
}
