#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "heap.h"

int main(){
	test_functions();

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
	printf("MAX + POP: %d\n", pop(heap));
	print(heap);
	printf("MAX + POP: %d\n", pop(heap));
	print(heap);
	printf("MAX + POP: %d\n", pop(heap));
	print(heap);

	printf("MAX + POP: %d\n", pop(heap));
	print(heap);
	printf("MAX + POP: %d\n", pop(heap));
	print(heap);
	printf("MAX + POP: %d\n", pop(heap));
	print(heap);
	printf("MAX + POP: %d\n", pop(heap));
	print(heap);
	assert(size(heap) == 0);

	destroy(&heap);
	return 0;
}
