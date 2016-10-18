#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H
#include <memory>
using std::unique_ptr;

template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};

#endif  // BINARY_TREE_NODE_H
