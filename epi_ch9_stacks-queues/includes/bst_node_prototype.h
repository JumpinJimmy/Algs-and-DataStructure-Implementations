#ifndef BST_NODE_PROTOTYPE_H
#define BST_NODE_PROTOTYPE_H
#include <memory>

using std::unique_ptr;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};

// REGISTER_TREE_TYPE(unique_ptr<BinaryTreeNode<T>>)
#endif // BST_NODE_PROTOTYPE_H
