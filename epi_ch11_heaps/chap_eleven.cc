#include <functional>
#include <queue>
#include <iostream>
#include "includes/chap_eleven.h"

HeapExercises::HeapExercises() {}

HeapExercises::~HeapExercises() {}

std::vector<int> HeapExercises::SortKSortedList(std::istringstream *sequence, int k) {
    if (k < 1) {
        std::cout << "HeapExercises::SortKSortedList: List is already sorted according to k value of " << k << std::endl;
        return {};
    }

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

std::vector<int> HeapExercises::ComputeClosestStars(std::istringstream *starmap_sequence, int k) {
    /// read in k-1 stars, into a maxheap
    ///
    /// then for every remaining star in the starmap final
    /// if current star is < maxheap.top(), emplace new star
    /// pop top of maxheap
    int curr_star = 0;
    std::vector<int> result_list;
    std::priority_queue< int, std::vector< int >, std::less<>> distance_maxheap;
    for (int i = 0; i < k && *starmap_sequence >> curr_star; ++i) {
        std::cout << "Pushing Sequence Var: " << curr_star << std::endl;
        distance_maxheap.push(curr_star);
    }

    while (*starmap_sequence >> curr_star) {
        if (curr_star < distance_maxheap.top()) {
            std::cout << "Current star(" << curr_star << ") less than top of distanceheap ("
                      << distance_maxheap.top() << ").  Evicting top and emplacing new star" << std::endl;
            distance_maxheap.pop();
            distance_maxheap.push(curr_star);
        } else {
            std::cout << "Current star(" << curr_star << ") NOT larger than distanceheap top("
                      << distance_maxheap.top() << ").  Skipping Star" << std::endl;
        }
    }

    while (!distance_maxheap.empty()) {
        result_list.emplace_back(distance_maxheap.top());
        distance_maxheap.pop();
    }

    return result_list;
}
