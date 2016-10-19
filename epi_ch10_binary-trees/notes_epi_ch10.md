# Binary Trees #
Page 135 of Elements of Programming Interviews

*   **Exercises:** 10.1, 10.2, 10.4, 10.11, 10.12*

---

**10.1: Test if a Binary Tree is height balanced**

*  `bool IsHeightBalanced(const unique_ptr<BinaryTreeNode<int>>& tree_root_)`

---

**10.2: Test if a Binary Tree is Symmetric**

*   x

`bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree_root)`

---

**10.4: Compute the LCA when Nodes Have Parent Pointers**

*   Any two nodes in a binary tree have a common ancestor, namely the root. The lowest common ancestor of any two nodes in a binary tree is the node furthest from the root that is an ancestor of both nodes
*   Design an algorithm for computing the LCA of two nodes in a binary tree in which nodes do not have a parent field

`BinaryTreeNode<int>* FindLCA(const unique_ptr<BinaryTreeNode<int>>& tree, const unique_ptr<BinaryTreeNode<int>>& nodeA, const unique_ptr<BinaryTreeNode<int>>& nodeB)`

---

**10.11: Implement an In-order Traversal with 0(1) Space**

*   the direct implementation of an in-order traversal using recursion has 0(h) space complexity, where h is the height of the tree. Recursion can be removed with an explicit stack, but space complexity remains O(h). 
*   Write a non-recursive program for computing the in-order traversal sequence for a binary tree. Assume nodes have **parent** fields
*   _hint_: how can you tell whether a node is a left child or right child of its parent?

`vector<int> InOrderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree)`

---

**10.12: Reconstruct a Binary Tree from Traversal Data**

*   Given an inorder traversal sequence and a preorder traversal sequence of a binary tree, write a program to reconstruct the tree.
*   Assume each node has a unique key
*   _hint_: focus on the root

`shared_ptr<BinaryTreeNode<int>> BinaryTreeFromInorderPreorder(const vector<int> &inorder, const vector<int> preorder, unordered_map<int, size_t> node_to_inorder_idx)`




