# Red-Black Tree
Implements a left-leaning red-black tree in C based on [Robert Sedgewick's paper](https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf).

**Properties:**
- All the red nodes are left-leaning
- There cannot be two red links in a row
- Counting only black nodes, the tree is perfectly balanced (i.e. the number of black links from the root to any other node is constant).

**Operations:**
- ```void insert(RBTree* tree, int val)```
- ```void delete_min(RBTree* tree)```
- ```int min(RBTree* tree)```
- ```void delete_max(RBtree* tree)```
- ```int max(RBTree* tree)```
- ```void delete(RBTree* tree)```
- ```int contains(RBtree* tree, int val)```
- ```void print(RBTree* tree)```
  - ```prints the tree in increasing (left->right) order```
- ```int height(RBTree* tree)```
- ```int size(RBTree* tree)```
- ```RBTree* create()```
- ```void destroy(RBTree** tree)```

**Example:**
```
#include "rbtree.h"

int main(){
  //create a tree
  RBTree* tree = create();
  
  //insert into the tree
  insert(tree, 1);
  insert(tree, 2);
  insert(tree, 3);
  insert(tree, 4);
  insert(tree, 5);
  insert(tree, 6);
  insert(tree, 7);
  
  //1 2 3 4 5 6 7
  print(tree);
  //returns 7
  size(tree);
  //returns 2
  height(tree);
  
  //returns 1
  min(tree);
  delete_min(tree);
  //returns 2
  min(tree);
  
  //returns 7
  max(tree);
  delete_max(tree);
  //returns 6
  max(tree);
  
  //2 3 4 5 6
  print(tree);
  
  delete(tree,4);
  //2 3 5 6 
  print(tree);

  destroy(&tree);
  return 0;
}
```
