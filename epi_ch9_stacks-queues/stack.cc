#include "includes/stack.h"

Stack::Stack() {}

void Stack::Push(int val) {
    /// always emplace new value in standard elemen stack
    /// if pushing a value that is larger than max
    /// emplace new value in max stack with count of one
    /// if same as max, emplace with updated count
    /// if greater than max emplace with count of one
    elements_.push(val);
}

int Stack::Pop() {
    /// save top element
    /// pop element stack
    /// compare popped elemet with max stack top
    /// if popped element == top of max stack
    /// decrement max fequency
    /// if max frequency == zero pop from max stack
    /// return popped element
    if (!elements_.empty()) {
        return elements_.pop()
    }
    return -1;
}

bool Stack::Empty() const {
    return elements_.empty();
}

int Stack::Top() {
    return elements_.top();
}

/// return the maximum value stored in the stack
int Stack::Max() const {
    /// return top of max stack
   return elements_.top();
}