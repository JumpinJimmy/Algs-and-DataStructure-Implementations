#include "includes/queue_stacks.h"
#include <iostream>

QueueStacks::QueueStacks():enqueue_queue_(std::make_unique<std::stack<int>>()),
                           dequeue_queue_(std::make_unique<std::stack<int>>()) {}

QueueStacks::~QueueStacks() {
    dequeue_queue_.reset(nullptr);
    enqueue_queue_.reset(nullptr);
}

void QueueStacks::Enqueue(int element) {
    enqueue_queue_->emplace(element);
}

int QueueStacks::Dequeue() {
    if (dequeue_queue_->empty()) {
        while (!enqueue_queue_->empty()) {
            dequeue_queue_->emplace(enqueue_queue_->top());
            enqueue_queue_->pop();
        }
    }
    if (dequeue_queue_->empty()) {
        std::cout << "QueueStacks->Dequeue(): QUEUE is Empty" << std::endl;
        return -1;
    }
    int result = dequeue_queue_->top();
    dequeue_queue_->pop();
    return result;
}

int QueueStacks::QueueSize() {
    return enqueue_queue_->size() + dequeue_queue_->size();
}

bool QueueStacks::Empty() {
    return enqueue_queue_->empty() && dequeue_queue_->empty();
}
