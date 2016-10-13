#include "includes/circular_queue.h"
CircularQueue::CircularQueue(unsigned int initial_capacity):front_(0), tail_(0), num_elements_(0),
                                                            resize_operand_(2),
                                                            queue_(std::make_unique<std::vector<int>>(initial_capacity)) {
    std::cout << "======= circular_queue:: queue_->size(): " << queue_->size() << std::endl;
    PrintInline(queue_.get());
}

CircularQueue::~CircularQueue() {
    queue_.reset(nullptr);
}

void CircularQueue::Enqueue(int element) {
    std::cout << "======= circular_queue::Enqueue(" << element << ");";
    if (num_elements_ == queue_->size()) {
        std::cout << "Enqueue(): QUEUE is FULL" << std::endl;
        return;
        // std::cout << "======= circular_queue:: QUEUE is Full! " << std::endl;
    }
    queue_->at(tail_) = element;
    ++num_elements_;
    tail_ = (tail_ + 1) % queue_->size();
    std::cout << " Queue Size: " << num_elements_ << ", tail_ position: " << tail_ << std::endl;
    // queue_->ins
}

int CircularQueue::Dequeue() {
    return 0;
}

int CircularQueue::QueueSize() {
    return num_elements_;
}

void CircularQueue::PrintInline(const std::vector<int> *list, std::string details) {
    if (!details.empty()) {
        std::cout << details << " ";
    }
    for (auto node : *list) {
        std::cout << "(" << node << ")";
    }
    std::cout << std::endl;
}