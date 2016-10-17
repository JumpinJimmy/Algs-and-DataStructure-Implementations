#include "includes/max_stack.h"
#include <exception>
#include <stdexcept>

MaxStack::MaxStack() {}
MaxStack::~MaxStack() {}
void MaxStack::Push(int val) {
    /// always emplace new value in staMaxStackndard elemen MaxStack
    /// if pushing a value that is larger than max
    /// emplace new value in max MaxStack with count of one
    /// if same as max, emplace with updated count
    /// if greater than max emplace with count of one
    elements_.emplace(val);
    if (cached_max_values_.empty()) {
        cached_max_values_.emplace(CachedMax {val, 1});
    } else {
        const int curr_max = cached_max_values_.top().max_;
        if (val > curr_max) {
            cached_max_values_.emplace(CachedMax {val, 1});
        } else if (val == curr_max) {
            int& curr_max_frequency = cached_max_values_.top().count_;
            curr_max_frequency++;
        }
    }
    // elements_.push(val);
}

int MaxStack::Pop() {
    /// save top element
    /// pop element MaxStack
    /// compare popped elemet with max MaxStack top
    /// if popped element == top of max MaxStack
    /// decrement max fequency
    /// if max frequency == zero pop from max MaxStack
    /// return popped element
    if (Empty()) {
        throw std::length_error("Pop(): Stack is Empty");
    }

    int popped_value = elements_.top();
    elements_.pop();
    const int curr_max = cached_max_values_.top().max_;
    if (popped_value == curr_max) {
        int& curr_max_frequency = cached_max_values_.top().count_;
        --curr_max_frequency;
        if (curr_max_frequency == 0) {
            cached_max_values_.pop();
        }
    }
    return popped_value;
}

bool MaxStack::Empty() const {
    return elements_.empty();
}

int MaxStack::Top() {
    if (Empty()) {
        throw std::length_error("Top(): Stack is Empty");
    }
    return elements_.top();
}

/// return the maximum value stored in the MaxStack
int MaxStack::Max() const {
    /// return top of max stack
    if (Empty()) {
        throw std::length_error("Max(): Stack is Empty");
    }
    return cached_max_values_.top().max_;
}

int MaxStack::stack_size() {
    return elements_.size();
}
