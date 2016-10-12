#include "includes/chap_nine.h"
StackQueueExercises::StackQueueExercises() {}

StackQueueExercises::~StackQueueExercises() {}

void StackQueueExercises::TestMaxStack(std::vector<int> &elements) {
    MaxStack test_stack;
    for (auto &element : elements) {
        test_stack.Push(element);
    }
}
// std::shared_ptr<Stack> CreateStack(int n) {
//     // shared_ptr<ListNode<int>> head = nullptr;
//     // for (int i = n - 1; i >= 0; --i) {
//     //     auto curr = std::make_shared<ListNode<int>>(ListNode<int> {i, nullptr});
//     //     curr->next = head;
//     //     head = curr;
//     // }
//     // return head;
//     // std::shared_ptr<Stack> new_stack = nullptr;
//     // new_stack = std::make_shared<Stack>(new Stack());
//     // return new_stack;
// }