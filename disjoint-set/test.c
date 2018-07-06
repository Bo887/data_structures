#include <stdio.h>
#include <assert.h>

#include "disjoint_set.h"

int main(){
	DisjointSet* test = create(10);
	assert(test != NULL);

	int rv = join(test, 1, 10);
	assert(rv == -1);

	rv = join(test, -1, 3);
	assert(rv == -1);

	rv = join(test, 0, 9);
	assert(rv == 0);
	assert(connected(test, 0, 9));
	assert(!connected(test, 0, 1));

	join(test, 0, 1);
	assert(connected(test, 0, 1));
	assert(connected(test, 1, 9));

	join(test, 4, 5);
	assert(connected(test, 4, 5));
	join(test, 7, 4);
	assert(connected(test, 7, 4));
	assert(connected(test, 5, 7));
	assert(!connected(test, 4, 0));

	join(test, 0, 7);
	assert(connected(test, 0, 7));
	assert(connected(test, 0, 4));
	assert(connected(test, 0, 5));
	assert(connected(test, 1, 7));
	assert(connected(test, 1, 4));
	assert(connected(test, 1, 5));
	assert(connected(test, 9, 5));
	assert(connected(test, 9, 4));
	assert(connected(test, 9, 7));

	assert(!connected(test, 2, 7));
	assert(!connected(test, 8, 1));
	assert(!connected(test, 9, 2));

	destroy(&test);
	assert(test == NULL);
	return 0;
}	
