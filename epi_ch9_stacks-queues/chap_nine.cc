#include "includes/chap_nine.h"
StackQueueExercises::StackQueueExercises() {}

StackQueueExercises::~StackQueueExercises() {}

void StackQueueExercises::TestMaxStack(std::vector<int> &elements) {
    MaxStack test_stack;
    for (auto &element : elements) {
        test_stack.Push(element);
    }
    std::cout << "\t--->> Stack Size: " << test_stack.stack_size()  << std::endl;
    std::cout << "\t--->> Max Element: " << test_stack.Max() << std::endl;
    int top_value = test_stack.Pop();
    std::cout << "\t--->> Pop() Result: " << top_value << std::endl;
    std::cout << "\t--->> Max Element: " << test_stack.Max() << std::endl;
    std::cout << "\t--->> Stack Size: " << test_stack.stack_size()  << std::endl;
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