#ifndef BST_PROTOTYPE_H
#define BST_PROTOTYPE_H
#include <memory>

template <typename T>
struct BSTNode {
  T data;
  std::unique_ptr<BSTNode<T>> left, right;
};


#endif  // BST_PROTOTYPE_H
