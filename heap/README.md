# Binary Heap
A priority queue implmenetation in C using a binary heap. 

Supports both maximum and minimum heaps and priority queue operations. 

Uses the array implementation, where:
- the root is at index 1
- the children of index ```i``` are at index ```2i``` and index ```2i+1```
- the parent of index ```i``` is at index ```floor(i/2)```

Automatically resizes the internal array whenever needed.

**Operations:**
- ```void push(Heap* heap, int val);```
- ```int top(Heap* heap);```
  - ```returns the maximum or minimum value, depending on how the heap is configured```
- ```int size(Heap* heap);```
- ```int print(Heap* heap);```
- ```Heap* create(Type type);```
  - ```type can be specified as MAX or MIN, for a maximum or a minimum heap```
- ```void destroy(Heap** heap);```

**Example:**
```
#include "heap.h"

int main(){
  //creates a minimum heap
  Heap* heap = create(MIN);
  
  //pushes values to the heap
  push(heap, 10);
  push(heap, 2);
  push(heap, 7);
  push(heap, 1);
  push(heap, 6);
  push(heap, 8);
  push(heap, 4);
  
  //returns 7
  size(heap);
  
  //returns the top (minimum) element, which is 1
  top(heap);
  //returns and removes the top (minimum) element, which is 1 
  pop(heap);
  //returns and removes the top (minimum) element, which is 2
  pop(heap);
  
  //frees the memory used by the heap
  destroy(&heap);
  return 0;
}
```
