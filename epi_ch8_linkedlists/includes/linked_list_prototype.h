#ifndef LINKED_LIST_PROTOTYPE_H
#define LINKED_LIST_PROTOTYPE_H
#include <memory>

using std::shared_ptr;
// @include
template <typename T>
struct ListNode {
  T data;
  shared_ptr<ListNode<T>> next;
};
// @exclude
#endif // LINKED_LIST_PROTOTYPE_H
