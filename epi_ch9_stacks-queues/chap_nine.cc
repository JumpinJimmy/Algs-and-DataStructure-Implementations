#include "includes/chap_nine.h"
StackQueueExercises::StackQueueExercises() {}

StackQueueExercises::~StackQueueExercises() {}

int StackQueueExercises::EvaluateRPN(const std::string& RPN_expression) {
    return 0;
}

/// Helper Methods
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

void StackQueueExercises::TestStackScope(std::shared_ptr<MaxStack> &s) {
    std::cout << "--->>--->> TestStackScope s->Top(): " << s->Top()
              << ", s->Max(): " << s->Max()
              << ", s->stack_size(): " << s->stack_size() << std::endl;
}

std::shared_ptr<MaxStack> StackQueueExercises::CreateStack(int n) {
    std::shared_ptr<MaxStack> test_stack(new MaxStack());
    for (int i = n - 1; i >= 0; --i) {
        test_stack->Push(i);
    }
    return test_stack;
}

std::shared_ptr<MaxStack> StackQueueExercises::CreateStack(std::vector<int> &elements) {
    std::shared_ptr<MaxStack> new_stack(new MaxStack());
    for (auto &element : elements) {
        new_stack->Push(element);
    }
    return new_stack;
}