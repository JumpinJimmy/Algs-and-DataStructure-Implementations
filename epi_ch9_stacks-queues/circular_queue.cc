#include "includes/circular_queue.h"
CircularQueue::CircularQueue(unsigned int initial_capacity) : front_(0), tail_(0), size_(0), max_size_(initial_capacity) {
    queue_ = std::make_unique<std::vector<int>>();
    queue_->reserve(max_size_);
    queue_->assign(max_size_, 0);
    std::cout << "======= circular_queue:: queue_->size(): " << queue_->size() << std::endl;
    PrintInline(queue_.get());
}

CircularQueue::~CircularQueue() {
    queue_.reset(nullptr);
}

void CircularQueue::Enqueue(int element) {
    // queue_->ins
}

int CircularQueue::Dequeue() {
    return 0;
}

int CircularQueue::QueueSize() {
    return size_;
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