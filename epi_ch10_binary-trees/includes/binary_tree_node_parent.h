#ifndef BINARY_TREE_NODE_PARENT_H
#define BINARY_TREE_NODE_PARENT_H
#include <memory>
using std::unique_ptr;

template <typename T>
struct BinTreeNodeP {
  T data;
  unique_ptr<BinTreeNodeP<T>> left, right;
  BinTreeNodeP<T>* parent;
};

#endif  // BINARY_TREE_NODE_PARENT_H

