#include "includes/max_stack.h"

MaxStack::MaxStack() {}
MaxStack::~MaxStack() {}
void MaxStack::Push(int val) {
    /// always emplace new value in staMaxStackndard elemen MaxStack
    /// if pushing a value that is larger than max
    /// emplace new value in max MaxStack with count of one
    /// if same as max, emplace with updated count
    /// if greater than max emplace with count of one
    elements_.push(val);
}

int MaxStack::Pop() {
    /// save top element
    /// pop element MaxStack
    /// compare popped elemet with max MaxStack top
    /// if popped element == top of max MaxStack
    /// decrement max fequency
    /// if max frequency == zero pop from max MaxStack
    /// return popped element
    if (!elements_.empty()) {
        int value = elements_.top();
        elements_.pop();
        // return elements_.pop();
        return value;
    }
    return -1;
}

bool MaxStack::Empty() const {
    return elements_.empty();
}

int MaxStack::Top() {
    return elements_.top();
}

/// return the maximum value stored in the MaxStack
int MaxStack::Max() const {
    /// return top of max stack
   return elements_.top();
}