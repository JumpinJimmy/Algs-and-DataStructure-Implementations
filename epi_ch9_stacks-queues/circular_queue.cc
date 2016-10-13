#include "includes/circular_queue.h"
CircularQueue::CircularQueue(unsigned int initial_capacity) : front_(0), tail_(0), size_(0), max_size_(initial_capacity) {
    queue_ = std::make_unique<std::vector<int>>();
    while (initial_capacity--) {
        queue_->push_back(0);
    }
    std::cout << "======= circular_queue:: queue_->size(): " << queue_->size() << std::endl;
}

CircularQueue::~CircularQueue() {}

void CircularQueue::Enqueue(int element) {}

int CircularQueue::Dequeue() {
    return 0;
}

int CircularQueue::QueueSize() {
    return size_;
}
