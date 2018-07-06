#include <stdlib.h>

#include "disjoint_set.h"

DisjointSet* create(int max_size){
	DisjointSet* disjoint_set = malloc(sizeof(DisjointSet));
	int* arr = malloc(sizeof(int)*max_size);
	disjoint_set->parent = arr;
}

void destroy(DisjointSet** disjoint_set){
	free((*disjoint_set)->parent);
	(*disjoint_set)->parent = NULL;
	free(*disjoint_set);
	*disjoint_set = NULL;
}
