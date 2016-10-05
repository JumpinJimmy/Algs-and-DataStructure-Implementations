#include "includes/chap_eight.h"
LinkedListExercises::LinkedListExercises() {
    int n = 10;
    shared_ptr<ListNode<int>> head = CreateLinkedList(n);
    Print(head);
}

LinkedListExercises::~LinkedListExercises() {}

shared_ptr<ListNode<int>> LinkedListExercises::CreateLinkedList(int n) {
    shared_ptr<ListNode<int>> head = nullptr;
    for (int i = n - 1; i >= 0; --i) {
        auto curr = std::make_shared<ListNode<int>>(ListNode<int> {i, nullptr});
        curr->next = head;
        head = curr;
    }
    return head;
}
