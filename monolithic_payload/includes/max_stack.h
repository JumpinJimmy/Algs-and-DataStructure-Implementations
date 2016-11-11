#ifndef MAX_STACK_H
#define MAX_STACK_H
#include <stack>

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
    std::stack<int> elements_;
    struct CachedMax {
        int max_;
        int count_;
    };
    std::stack<CachedMax> cached_max_values_;
};

#endif  // MAX_STACK_H
