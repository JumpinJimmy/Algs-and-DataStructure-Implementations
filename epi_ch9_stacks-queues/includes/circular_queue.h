#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <array>
#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include <ios>
#include <string>
#include <exception>

class CircularQueue {
    public:
    explicit CircularQueue(unsigned int initial_capacity = 1);
    ~CircularQueue();
    // TODO(jdevore): handle copy and assignment ops
    void Enqueue(int element);
    int Dequeue();
    int QueueSize();
    void PrintInline(const std::vector<int> *list, std::string details = "");
    void PrintFromHead();
    private:
    // resize function
    int front_;
    int tail_;
    unsigned int num_elements_;
    unsigned int resize_operand_;
    std::unique_ptr<std::vector<int>> queue_;
};

#endif // CIRCULAR_QUEUE_H
