#ifndef DOUBLY_LINKED_LIST_PROTOTYPE_H
#define DOUBLY_LINKED_LIST_PROTOTYPE_H
#include <memory>

using std::shared_ptr;

// @include
template <typename T>
struct DListNode {
  T data;
  shared_ptr<DListNode<T>> prev, next;
};
// @exclude
#endif // DOUBLY_LINKED_LIST_PROTOTYPE_H
