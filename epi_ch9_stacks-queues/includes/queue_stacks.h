#ifndef QUEUE_STACKS_H
#define QUEUE_STACKS_H
#include <stack>
#include <memory>

class QueueStacks {
    public:
    QueueStacks();
    ~QueueStacks();
    void Enqueue(int element);
    int Dequeue();
    int QueueSize();
    bool Empty();

    private:
    std::unique_ptr<std::stack<int>> enqueue_queue_;
    std::unique_ptr<std::stack<int>> dequeue_queue_;
};

#endif // QUEUE_STACKS_H
