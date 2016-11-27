# Ch10 Binary Tree Notes # 
_Page 135 - 137_

---

*  represents a hierarchy
*  Each node, except the root is itself the root of a left subtree or right subtree
    *  if L is the root of P's left subtree, L is the left child of P and P is the parent of L
*  Every node has a unique parent
*  Search Path: For any node, there exists a unique sequence of nodes from the root to that node with each node
*  A node is an ancestor of D if it lies on the search path from the root to D
*  Leaf: a node that has no descendants
*  Depth: number of nodes on the search path from the root to target node not including itslef
*  Height: maximum depth of any node
*  Level: nodes on the same depth
*  **Full Binary Tree:** every node other than the leaves have two children
*  **Perfect Binary Tree:** is a full binary tree, all leaves are at the same depth and every parent has two children
*  **Complete Binary Tree:** every level except possibly the last is completely filled and all nodes are as far left as possible
*  A perfect binary tree of height H contains exactly 2^h+1 - 1 nodes of which 2^h are leaves
*  A complete binary tree has height floor(log N)

---

** Traversals: **
*  _Inorder:_ left , root, right
*  _Preorder:_ root, left, right
*  _Postorder:_ left, right, root

*   Traversals have 
*   O(n) time complxity
*   O(h) space
*   If nodes have parents, the space complexity can be improved to 0(1)

---

*   **Recursive Algorithms** are well suited to tree problems
    *   space complexity analysis must include the function call stack
*   Consider **left** and **right skewed** trees when doing complexity analysis. 
    *   O(h) complexity where h is the height of the tree translates into O(log n) complexity for balanced trees but O(n) for skewed
*   if each node has a parent field, it can reduce time and space complexity

---

## Test if a binary tree is Height Balanced ##

*   
---

## Compute the LCA when nodes have parent pointers ##

