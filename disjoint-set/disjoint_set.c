#include <stdlib.h>
#include <stdio.h>

#include "disjoint_set.h"

static int within_bounds(DisjointSet* this, int val){
	int max_size = this->max_size;
	return val >= 0 && val < max_size;
}

int join(DisjointSet* this, int p, int q){
	if (!within_bounds(this, p) || !within_bounds(this,q)){
		return -1;
	}
	int root_p = find_root(this, p);
	int root_q = find_root(this, q);
	if (root_p != root_q){
		//make the smaller subtree point to the larger one
		if (this->size[root_p] < this->size[root_q]){
			this->parent[root_p] = root_q;
			this->size[root_q] += this->size[root_p];
		}
		else{
			this->parent[root_q] = root_p;
			this->size[root_p] += this->size[root_q];
		}
	}
	return 0;
}

int find_root(DisjointSet* this, int val){
	if (!within_bounds(this, val)) return -1;
	//loop until the parent of this element is itself
	while(val != this->parent[val]){
		val = this->parent[val];
	}
	return val;
}

int connected(DisjointSet* this, int p, int q){
	if (!within_bounds(this, p) || !within_bounds(this, q)){
		return -1;
	}
	//two items are connected if their roots are the same
	return find_root(this, p) == find_root(this, q);
}

DisjointSet* create(int max_size){
	DisjointSet* disjoint_set = malloc(sizeof(DisjointSet));
	int* parent = malloc(sizeof(int)*max_size);
	int* size = malloc(sizeof(int)*max_size);
	//the parent of each element starts as itself, since nothing is connected yet
	for(int i=0; i<max_size; i++){
		parent[i] = i;
		size[i] = 1;
	}
	disjoint_set->parent = parent;
	disjoint_set->size = size;
	disjoint_set->max_size = max_size;
	return disjoint_set;
}

void destroy(DisjointSet** disjoint_set){
	free((*disjoint_set)->parent);
	(*disjoint_set)->parent = NULL;
	free((*disjoint_set)->size);
	(*disjoint_set)->size = NULL;
	free(*disjoint_set);
	*disjoint_set = NULL;
}
