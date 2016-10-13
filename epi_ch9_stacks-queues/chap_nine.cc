#include "includes/chap_nine.h"
StackQueueExercises::StackQueueExercises() {}

StackQueueExercises::~StackQueueExercises() {}

int StackQueueExercises::EvaluateRPN(const std::string& RPN_expression) {
    if (RPN_expression.empty()) {
        throw std::invalid_argument("EvaluateRPN(): RPN_expression String is Empty");
    }
    // foreach (char c: RPN_expression)
    // if C.isDigit (!operator +-/*)
    //  operand_stack.emplace(stoi(c))
    // else if (c.isOperator(+-/*)) {
    //    int operand_a = operand_stack.top()
    //    operand_stack.pop()
    //    int operaand_b = operand_stack.top()
    //    operand_stack.pop()
    //    switch(c):
    //      -case"+": operand_stack.emplace(operand_a+operand_b)
    //      -case"-": operand_stack.emplace(operand_a-operand_b)
    //      -case"*": operand_stack.emplace(operand_a*operand_b)
    //      -case"/": operand_stack.emplace(operand_a/operand_b)
    // }
    // return operand_stack.top()
    return 0;
}

bool StackQueueExercises::IsWellFormedBrackets(const std::string& bracket_str) {
    if (bracket_str.empty() || bracket_str.size() == 1) {
        throw std::invalid_argument("IsWellFormedBrackets(): bracket_str.size must be > 1 char");
        return false;
    }
    // foreach (char c: bracket_str)
    // if C.isLeftBracket (`[`,`{`,`(`) )
    //     left_stack.emplace(c)
    //     // or emplace its compliment.... e.g. if c == [ emplace ]
    //  else if (c.isRightBracket(`]`,`}`,`)`))
    //      switch(c)
    //          -case"]": if left_stack.top() == '['; left_stack.pop(); continue;
    //          -case"}": if left_stack.top() == '{'; left_stack.pop(); continue;
    //          -case")": if left_stack.top() == '('; left_stack.pop(); continue;
    //      return false
    //  // end forloop
    //  if (left_stack.size >= 1) return false  // return left_stack.empty()

    return true;
}

std::vector<std::vector<int>> StackQueueExercises::BSTDepthOrder(const std::unique_ptr<BinaryTreeNode<int>>& tree) {
    return {{}};
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