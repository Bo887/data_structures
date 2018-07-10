#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "heap.h"

int test_resize_arr(){
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
}

int test_swap(){
	int* arr = malloc(sizeof(int)*8);
	arr[0] = 2;
	arr[7] = 3;
	swap(arr, 0, 7);
	assert(arr[0] == 3);
	assert(arr[7] == 2);
	free(arr);
}

int main(){
	test_swap();
	test_resize_arr();

	Heap* heap = create(MAX);
	push(heap, 10);
	print(heap);
	push(heap, 3);
	print(heap);
	push(heap, 4);
	print(heap);
	push(heap, 2);
	print(heap);
	push(heap, 5);
	print(heap);
	push(heap, 6);
	print(heap);
	push(heap, 7);
	print(heap);
	push(heap, 1);
	print(heap);

	printf("MAX + POP: %d\n", pop(heap));
	print(heap);

	destroy(&heap);
	return 0;
}
