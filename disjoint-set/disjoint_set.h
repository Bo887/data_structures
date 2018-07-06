#ifndef DISTJOINT_SET_H
#define DISTJOINT_SET_H

typedef struct DisjointSet DisjointSet;

struct DisjointSet{
	int* parent;
};

void (*join)(DisjointSet this, int p, int q);

int (*add)(DisjointSet this, int p);

int (*connected)(DisjointSet this, int p, int q);

int (*size)(DisjointSet this);

DisjointSet* create();

void free(DisjointSet* dset);

#endif
