#ifndef BINARY_TREE_NODE_PARENT_H
#define BINARY_TREE_NODE_PARENT_H
#include <memory>
using std::unique_ptr;
// TODO(jdevore) : extend binary_tree_node.h template class instead of duplicating functionality (later)
template <typename T>
struct BinTreeNodeP {
  T data;
  unique_ptr<BinTreeNodeP<T>> left, right;
  BinTreeNodeP<T>* parent;
};

#endif  // BINARY_TREE_NODE_PARENT_H

