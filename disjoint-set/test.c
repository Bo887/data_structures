#include <stdio.h>
#include "disjoint_set.h"

int main(){
	DisjointSet* test = create(10);
	destroy(&test);
	return 0;
}	
