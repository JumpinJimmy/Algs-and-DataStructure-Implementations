#ifndef CHAP_EIGHT_H
#define CHAP_EIGHT_H
#include <iostream>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include "linked_list_prototype.h"
#include "doubly_linked_list_prototype.h"

class LinkedListExercises {
    public:
        LinkedListExercises();
        ~LinkedListExercises();
        shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                                      shared_ptr<ListNode<int>> L2);

        /// Helper Functions
        shared_ptr<ListNode<int>> CreateLinkedList(int n);

        template <typename T> /// See if we can move Print impl to .cc
        void Print(shared_ptr<ListNode<T>> head) {
          if (head) {
            std::cout << "(" << head->data << ")" << std::endl;
            Print(head->next);
          }
        };
    private:
        void AppendSingleNode(shared_ptr<ListNode<int>> *candidate_node,
                              shared_ptr<ListNode<int>> *tail_node);
};

#endif // CHAP_EIGHT_H
