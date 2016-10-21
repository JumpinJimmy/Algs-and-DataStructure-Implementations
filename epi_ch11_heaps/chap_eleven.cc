#include <functional>
#include <queue>
#include <iostream>
#include "includes/chap_eleven.h"

HeapExercises::HeapExercises() {}

HeapExercises::~HeapExercises() {}

std::vector<int> HeapExercises::SortKSortedList(std::istringstream *sequence, int k) {
    int seq_var = 0;
    std::vector<int> result_list;
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
    for (int i = 0; i < k && *sequence >> seq_var; ++i) {
        std::cout << "Pushing Sequence Var: " << seq_var << std::endl;
        min_heap.push(seq_var);
    }
    while (*sequence >> seq_var) {
        std::cout << min_heap.top();
        result_list.emplace_back(min_heap.top());
        min_heap.pop();
        min_heap.push(seq_var);
    }

    while (!min_heap.empty()) {
        std::cout << min_heap.top();
        result_list.emplace_back(min_heap.top());
        min_heap.pop();
    }
    return result_list;
}
