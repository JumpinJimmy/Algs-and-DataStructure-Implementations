# Binary Search Trees Chapter 15 #

**Problems / Exercises:** 15.1, 15.2, 15.3, 15.4, 15.5, 15.8, 15.9

[Exercises & Tasks Project Page](https://github.com/JumpinJimmy/Algs-and-DataStructure-Implementations/projects/1)

**15.1: Test If A Binary Tree Satisfies the BST Property**
*   **Overview:** write a program that takes as input a binary tre and checks if the tree satisfies the BST property
*   **Input:** Root of binary tree  
*   **Output:** True or False
*   **Example:**

`bool IsBinarySearchTreeDFS(const std::unique_ptr<BSTNode<int>> &tree);`
`bool IsBST(const std::unique_ptr<BSTNode<int>> &tree);`


**15.2: Find First Key Larger than K**
*   **Overview:**
*   **Input:**
*   **Output:**
*   **Example:**

`BSTNode<int>* FirstGreaterKey(const std::unique_ptr<BSTNode<int>> &tree, int key);`


**15.3: Get K Largest Keys**
*   **Overview:**
*   **Input:**
*   **Output:**
*   **Example:**

`std::vector<int> RetreiveKLargestKeys(const std::unique_ptr<BSTNode<int>> &tree, int k);`


**15.4: Compute the LCA in a BST**
*   **Overview:** Given a BSTree and two Nodes, Find their LCA
*   **Input:** three pointers, one is the tree root, the other two are the nodes sharing the lowest common ancestor
*   **Output:** Return the LCA Node
*   **Example:**

`BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>> &tree, const unique_ptr<BSTNode<int>> &node_a, const unique_ptr<BSTNode<int>> &node_b);`


**15.5: Reconstruct BST from Traversal Data(preorder)**
*   **Overview:** 
*   **Input:**
*   **Output:**
*   **Example:**
*   PSUEDO: Build(sequence, lower, upper, root_index_reference)
    *   maintain a root index reference, an upper bound, and a lower bound
    *   select sequence list value at root index reference 
    *   if root value > upper or < lower, return null
    *   increment root index reference
    *   start building left sub tree with the now updated root index reference (recurse)
        *   leftsub = Build(sequence_list, lower, rootval, root_index_reference)
    *   after left subtree has finished, the rood index reference should be at the right subtree "root" index
    *   start building right sub tree (recurse)
        *   rightsub = Build(sequence_list, rootval, root_index_reference)
    *   both sub trees are finished, join the two subtrees via move() under the original root node.
    *   return completed tree

`function signature()`


**15.6: Find Closest Entires (smallest interval) in N sorted Arrays**
*   **Overview:**
*   **Input:**
*   **Output:**
*   **Example:**
*   **Pseudo Code Solution:**
    *   maintain a sorted set of the smallest element from each list
    *   get the difference between the max and min element of the set
    *   if the difference is less than any previously observed differences, update smallest difference 
    *   evict the smallest element from the set and retrieve and add  the next item in the the evicted elements associated list to the sorted set
    *   if you reach the end of any of the N sorted arrays, return the smallest difference seen thus far
    *   recurse... again getting the difference between the current min and max elements in the sorted set ... so on and so forth until you have reached the end of any of the lists. 

`function signature()`

**15.8: Most Visited Page Problem** 
>this problem needs to be reviewed more closely

*   **Overview:**
*   **Input:**
*   **Output:**
*   **Example:**

`function signature()`


**15.9: Build Minimum Height BST from Sorted Array**
*   **Overview:**
*   **Input:**
*   **Output:**
*   **Example:**
*   **Pseudo Solution:**
    *    select the lists mid element as root, 
    *    recursively build left and right sub trees by selecting the middle of the sublists left[0 - currRoot-1] and right [currRoot+1 - Array.size()]

`function signature()`

