#include "includes/chap_eight.h"
LinkedListExercises::LinkedListExercises() {
    int n = 10;
    shared_ptr<ListNode<int>> head = CreateLinkedList(n);
    Print(head);
}

LinkedListExercises::~LinkedListExercises() {}

shared_ptr<ListNode<int>> LinkedListExercises::MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                                                   shared_ptr<ListNode<int>> L2) {
    shared_ptr<ListNode<int>> result_head(new ListNode<int>);
    auto tail_node = result_head;
    while (L1 && L2) {
        if (L1->data <= L2->data) {
            AppendSingleNode(&L1, &tail_node);
        } else {
            AppendSingleNode(&L2, &tail_node);
        }
    }
    tail_node->next = L1 ? L1 : L2;
    return result_head->next;
}

/// MergeTwoSortedLists Helper Method
void LinkedListExercises::AppendSingleNode(shared_ptr<ListNode<int>> *candidate_node,
                                           shared_ptr<ListNode<int>> *tail_node) {
    (*tail_node)->next = *candidate_node;
    *tail_node = *candidate_node;
    *candidate_node = (*candidate_node)->next;
}

/// TODO(jdevore): Create another method to build list w/ custom data field vs. 0 - N
shared_ptr<ListNode<int>> LinkedListExercises::CreateLinkedList(int n) {
    shared_ptr<ListNode<int>> head = nullptr;
    for (int i = n - 1; i >= 0; --i) {
        auto curr = std::make_shared<ListNode<int>>(ListNode<int> {i, nullptr});
        curr->next = head;
        head = curr;
    }
    return head;
}
