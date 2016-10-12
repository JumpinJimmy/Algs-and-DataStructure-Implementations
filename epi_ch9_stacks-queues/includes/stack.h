#ifndef STACK_H
#define STACK_H
#include <stack>

class Stack {
    public:
    Stack();
    ~Stack();
    void Push(int val);
    int Pop();
    bool Empty();
    int Top();

    private:
    // int size_;
    std::stack<int> elements_;
};


#endif // STACK_H
