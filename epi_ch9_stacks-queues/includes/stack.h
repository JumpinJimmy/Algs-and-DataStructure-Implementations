#ifndef STACK_H
#define STACK_H
#include <stack>
#include <algorithm>
#include <exception>
#include <exception>
#include <stdexcept>

class Stack {
    public:
    Stack();
    ~Stack();
    void Push(int val);
    int Pop();
    bool Empty() const;
    int Top();
    int Max() const;

    private:
    // struct with two integer elements (max, count)
    // stack containing struct elements  cache_maxed_vals
    std::stack<int> elements_;
};


#endif // STACK_H
