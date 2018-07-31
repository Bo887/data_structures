# LinkedList
An implementation of a doubly-linked list in C. Supports deque operations (pushing and popping at either end) as well as deletion of a specific value.

**Operations:**
- ```void push_front(List* list, int val)```
- ```void push_back(List* list, int val)```
- ```int pop_front(List* list)```
- ```int pop_back(List* list)```
- ```int delete(List* list, int val)```
- ```int size(List* list)```
- ```int contains(List* list, int val)```
- ```int get(List* list, int index)```
- ```void print(List* list)```
- ```List* create()```
- ```void destroy(List** list)```

**Example:**
```
#include "linkedlist.h"

int main(){
  //allocates memory for a list
  List* list = create();
  
  //pushes 5 to the back of the list
  push_back(list, 5);
  
  //pushes 2 to the front of the list
  push_front(list, 2);
  
  //pushes 4 to the back of the list
  push_back(list, 4);
  
  //pushes 9 to the front of the list
  push_front(list, 9);
  
  //list is now: 9 2 5 4
  print(list);
  
  //returns 4
  size(list);
  
  //returns 1 (true)
  contains(list, 9);
  //returns 0 (false)
  contains(list, 1);
  
  //list is now: 9 5 4
  delete(list, 2);
  //returns -1, since list doesn't contain 2 anymore
  delete(list, 2);
  
  //returns 5 (element at index 1)
  get(list, 1);
  
  //automatically frees memory used by the list and sets list to NULL
  destroy(&list);
  return 0;
}
```
