#ifndef QUEUE_STACKS_H
#define QUEUE_STACKS_H

class QueueStacks {
    public:
    QueueStacks();
    ~QueueStacks();
    void Enqueue(int element);
    int Dequeue();
    int QueueSize();
    // void PrintInline(const std::vector<int> *list, std::string details = "");
    // void PrintFromHead();
    private:
    // resize function
    int front_;
    int tail_;
    unsigned int num_elements_;
    unsigned int resize_operand_;
    // std::unique_ptr<std::vector<int>> queue_;
};

#endif // QUEUE_STACKS_H
