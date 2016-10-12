#include "includes/stack.h"

Stack::Stack() {}

void Stack::Push(int val) {
    elements_.push(val);
}

int Stack::Pop() {
    if (!elements_.empty()) {
        return elements_.pop()
    }
    return -1;
}

bool Stack::Empty() {
    return elements_.empty();
}

int Stack::Top() {
    return elements_.top();
}
