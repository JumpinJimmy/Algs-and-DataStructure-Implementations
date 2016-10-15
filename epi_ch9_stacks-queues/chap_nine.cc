#include "includes/chap_nine.h"
#include <utility>
#include <numeric>
#include <cmath>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>

StackQueueExercises::StackQueueExercises() {}

StackQueueExercises::~StackQueueExercises() {}

int StackQueueExercises::EvaluateRPN(const std::string& RPN_expression) {
    if (RPN_expression.empty()) {
        std::cout << "ERROR- EvaluateRPN(): RPN_expression String is Empty" << std::endl;
        return -1;
    }
    std::stack<int> operand_stack;
    std::stringstream ss(RPN_expression);
    std::string char_token;
    const char kDelimiter = ',';

    while (getline(ss, char_token, kDelimiter)) {
        if (char_token == "+" || char_token == "-" || char_token == "*" || char_token == "/") {
            const int operand_a = operand_stack.top();
            operand_stack.pop();
            const int operand_b = operand_stack.top();
            operand_stack.pop();
            switch (char_token.front()) {
                case '+':
                    operand_stack.emplace(operand_b + operand_a);
                    break;
                case '-':
                    operand_stack.emplace(operand_b - operand_a);
                    break;
                case '*':
                    operand_stack.emplace(operand_b * operand_a);
                    break;
                case '/':
                    operand_stack.emplace(operand_b / operand_a);
                    break;
            }
        } else {
            operand_stack.emplace(std::stoi(char_token));
        }
    }

    return operand_stack.top();
}

bool StackQueueExercises::IsWellFormedBrackets(const std::string& bracket_str) {
    if (bracket_str.empty() || bracket_str.size() == 1) {
        throw std::invalid_argument("IsWellFormedBrackets(): bracket_str.size must be > 1 char");
        return false;
    }
    std::stack<char> bracket_stack;
    for (const char &c : bracket_str) {
        if (c == '[' || c == '{' || c == '(') {
            bracket_stack.emplace(c);
        } else {
            if (bracket_stack.empty()) return false;
            switch (c) {
                case ']' : if (bracket_stack.top() == '[') {
                            bracket_stack.pop();
                            continue;
                        };
                case '}' : if (bracket_stack.top() == '{') {
                            bracket_stack.pop();
                            continue;
                        };
                case ')' : if (bracket_stack.top() == '(') {
                            bracket_stack.pop();
                            continue;
                        };
                default: return false;
            }
        }
    }
    return bracket_stack.empty();
}

/// Esentially pre-order traversal with constraints on each level's list size
std::vector<std::vector<int>> StackQueueExercises::BinTreeLevelOrder(const std::unique_ptr<BinaryTreeNode<int>>& tree) { //NOLINT
    if (!tree) {
        throw std::invalid_argument("BinTreeLevelOrder(): Tree is null");
        return {{}};
    }

    std::vector<std::vector<int>> final_results;
    std::vector<int> curr_level_list;
    std::queue<BinaryTreeNode<int>*> traversal_queue;
    traversal_queue.emplace(tree.get());
    int nodes_left_level = traversal_queue.size();

    while (!traversal_queue.empty()) {
        BinaryTreeNode<int> *curr_node = traversal_queue.front();
        --nodes_left_level;
        traversal_queue.pop();
        curr_level_list.emplace_back(curr_node->data);
        if (curr_node->left != nullptr) {traversal_queue.emplace(curr_node->left.get());}
        if (curr_node->right != nullptr) {traversal_queue.emplace(curr_node->right.get());}
        if (!nodes_left_level) {
            nodes_left_level = traversal_queue.size();
            if (!curr_level_list.empty()) {
               final_results.emplace_back(move(curr_level_list));
            }
        }
    }

    /// Debug output only
    std::cout << "{ ";
    for (auto &sub_list : final_results) {
        std::cout << "( ";
        for (auto &node : sub_list) {
            std::cout << node << " ";
        }
        std::cout << "),";
    }
    std::cout << " }" << std::endl;

    return final_results;
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

void StackQueueExercises::TestCircularQueue() {
    unsigned int initial_size = 4;
    CircularQueue cq(initial_size);
    while (initial_size--) {
        cq.Enqueue(initial_size);
    }
    cq.PrintFromHead();
    cq.Enqueue(11);

    std::cout << "Front: " << cq.Dequeue() << std::endl;
    std::cout << "Frontb: " << cq.Dequeue() << std::endl;
}

void StackQueueExercises::TestQueueStacks() {
    QueueStacks qs;
    int element_count = 10;
    int dequeue_count = 6;
    std::cout << "Pre Enqueue - qs.Empty() = " << std::boolalpha << qs.Empty() << std::endl;
    while (element_count--) {
        qs.Enqueue(element_count);
    }
    std::cout << "Post Enqueue - qs.Empty() = " << std::boolalpha << qs.Empty() << std::endl;
    std::cout << "QueueStacks qs->size(): " << qs.QueueSize() << std::endl;

    while (dequeue_count--) {
        std::cout << "QueueStacks Dequeue() result = " << qs.Dequeue() << std::endl;
    }
    int remaining_size = qs.QueueSize();
    std::cout << "Post Dequeue - QueueStacks qs->size(): " << remaining_size << std::endl;
    std::cout << "Post Dequeue - qs.Empty() = " << std::boolalpha << qs.Empty() << std::endl;
    while (remaining_size--) {
        std::cout << "QueueStacks Dequeue() result = " << qs.Dequeue() << std::endl;
    }
    std::cout << "Post Dequeue - QueueStacks qs->size(): " << qs.QueueSize() << std::endl;
    std::cout << "Post Dequeue - qs.Empty() = " << std::boolalpha << qs.Empty() << std::endl;
}
