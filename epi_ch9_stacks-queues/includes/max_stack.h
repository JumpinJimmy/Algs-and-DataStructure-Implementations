#ifndef MAX_STACK_H
#define MAX_STACK_H
#include <stack>
#include <algorithm>
#include <exception>
#include <stdexcept>

class MaxStack {
    public:
    MaxStack();
    ~MaxStack();
    void Push(int val);
    int Pop();
    bool Empty() const;
    int Top();
    int Max() const;
    int stack_size();

    private:
    struct CachedMax {
        int max_;
        int count_;
    };
    // struct with two integer elements (max, count)
    // stack containing struct elements  cache_maxed_vals
    std::stack<int> elements_;
    std::stack<CachedMax> cached_max_values_;
};


#endif // MAX_STACK_H
