#include <algorithm>
#include "includes/chap_fourteen.h"

SortingExercises::SortingExercises() {}

SortingExercises::~SortingExercises() {}

std::vector<int> SortingExercises::ComputeListIntersection(const std::vector<int>& A1, const std::vector<int>& A2) {
    PrintCollection(A1, "ComputeIntersection List1: ");
    PrintCollection(A2, "ComputeIntersection List2: ");
    std::vector<int> result = {};
    int index = 0;
    for (auto &val : A1) {
        if (((index == 0) || (val != A1.at(index-1))) && (std::binary_search(A2.begin(), A2.end(), val))) {
            result.emplace_back(val);
        }
        ++index;
    }
    return result;
}
