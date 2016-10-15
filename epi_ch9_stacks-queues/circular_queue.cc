#include "includes/circular_queue.h"
#include <array>
#include <algorithm>
#include <iostream>
#include <exception>

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
        std::cout << "Enqueue(): QUEUE is FULL.. Resizing" << std::endl;
        rotate(queue_->begin(), queue_->begin() + front_, queue_->end());
        front_ = 0, tail_ = num_elements_;  // Resets head and tail.
        queue_->resize(queue_->size() * resize_operand_);
        std::cout << "======= circular_queue:: new size: " << queue_->size() << std::endl;

    }

    queue_->at(tail_) = element;
    ++num_elements_;
    tail_ = (tail_ + 1) % queue_->size();
    std::cout << " Queue Size: " << num_elements_ << ", tail_ position: " << tail_ << std::endl;
}

int CircularQueue::Dequeue() {
    std::cout << "--->>--->> circular_queue::Dequeue " << std::endl;
    if (num_elements_ > 0) {
        --num_elements_;
        int result = queue_->at(front_);
        front_ = (front_ + 1) % queue_->size();
        std::cout << "--->>--->> circular_queue:: front_ after dequeue " << front_ << std::endl;
        PrintFromHead();
        return result;
    } else {
        std::cout << "Dequeue(): QUEUE is Empty" << std::endl;
        return -1;
    }
}

int CircularQueue::QueueSize() {
    return num_elements_;
}

void CircularQueue::PrintFromHead() {
    std::cout << "--->>--->> circular_queue::PrintQueue(head: " << front_ << ") " << std::endl;
    if (num_elements_ > 0) {
        // const std::vector<int> *v = queue_.get();
        // for ()
        for (int i = 0; i < queue_->size(); ++i) {
            std::cout << "(";
            if (i == front_) std::cout << "<H> ";
            std::cout << queue_->at(i);
            if (i == tail_) std::cout << " <T>";
            std::cout << ")";
        } std::cout << std::endl;
    };
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
