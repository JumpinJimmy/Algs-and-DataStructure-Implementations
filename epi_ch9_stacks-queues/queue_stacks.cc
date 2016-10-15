#include "includes/queue_stacks.h"
#include <iostream>

QueueStacks::QueueStacks():enqueue_queue_(std::make_unique<std::stack<int>>()), dequeue_queue_(std::make_unique<std::stack<int>>()) {
    std::cout << "--->>--->> queue_stacks:: constructor "  << std::endl;
}

QueueStacks::~QueueStacks() {
    dequeue_queue_.reset(nullptr);
    enqueue_queue_.reset(nullptr);
}

void QueueStacks::Enqueue(int element) {
    enqueue_queue_->emplace(element);
}

int QueueStacks::Dequeue() {
    return 0;
}

int QueueStacks::QueueSize() {
    return enqueue_queue_->size() + dequeue_queue_->size();
    // return 0;
}

