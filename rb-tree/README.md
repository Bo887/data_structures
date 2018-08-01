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
