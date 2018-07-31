# Disjoint-Set
An implmenetation of the disjoint-set (union-find) data structure in C. 

The join algorithm is weighted always make the smaller tree point to the larger tree. 

**Operations:**
- ```int join(DisjointSet* this, int p, int q)```
- ```int find_root(DisjointSet* this, int p, int q)```
- ```int connected(DisjointSet* this, int p, int q)```
- ```DisjointSet* create(int max_size)```
- ```void destroy(DisjointSet** this)```

**Example:**
```
#include "disjoint_set.h"

int main(){
  //creates a disjoint-set data structure with 10 elements (from 0 to 9)
  DisjointSet* ds = create(10);
  
  //returns -1 since 10 is out of bounds
  join(ds, 1, 10);
  
  //connects element 0 and 9
  join(ds, 0, 9);
  //returns 1 (true)
  connected(ds, 0, 9);
  //returns 0 (false) since 0 and 1 are not connected
  connected(ds, 0, 1);
  
  //connects element 0 and 1
  //now elements 0, 1 and 9 are all connected together
  join(ds, 0, 1);
  //returns 1 (true)
  connected(ds, 0, 1);
  //both return 1 (true)
  connected(ds, 0, 9);
  connected(ds, 1, 9);
  
  //frees all the memory used and sets ds to NULL
  destroy(&ds);
  return 0;
}
```
