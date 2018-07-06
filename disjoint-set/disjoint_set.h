#ifndef DISTJOINT_SET_H
#define DISTJOINT_SET_H

typedef struct _DisjointSet DisjointSet;

struct _DisjointSet{
	//parent[i] = the parent of element i
	int* parent;
	//size[i] = the size of the subtree that has root i
	int* size;
	int max_size;
};

int join(DisjointSet* this, int p, int q);

int find_root(DisjointSet* this, int val);

int connected(DisjointSet* this, int p, int q);

DisjointSet* create(int size);

void destroy(DisjointSet** disjoint_set);

#endif
