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

int main(){
	Heap* heap = create(MAX);
	destroy(&heap);
	test_resize_arr();
	return 0;
}
