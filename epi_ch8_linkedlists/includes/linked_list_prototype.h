#ifndef LINKED_LIST_PROTOTYPE_H
#define LINKED_LIST_PROTOTYPE_H
#include <memory>

using std::shared_ptr;

template <typename T>
struct ListNode {
  T data;
  shared_ptr<ListNode<T>> next;
};

#endif // LINKED_LIST_PROTOTYPE_H
