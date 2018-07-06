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

	
	destroy(&test);
	assert(test == NULL);
	return 0;
}	
