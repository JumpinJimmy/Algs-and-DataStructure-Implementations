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

std::vector<int> SortingExercises::ComputeListIntersectionAlt(const std::vector<int>& A1, const std::vector<int>& A2) {
    std::cout << "======= chap_fourteen:: ComputeListIntersectionAlt() " << std::endl;
    PrintCollection(A1, "ComputeListIntersectionAlt List1: ");
    PrintCollection(A2, "ComputeListIntersectionAlt List2: ");
    std::vector<int> result = {};
    unsigned int list_ptr_one = 0;
    unsigned int list_ptr_two = 0;
    while (list_ptr_one < A1.size() && list_ptr_two < A2.size()) {
        if (A1.at(list_ptr_one) == A2.at(list_ptr_two) && (list_ptr_one == 0 || A1.at(list_ptr_one) != A1.at(list_ptr_one - 1))) {
            result.emplace_back(A1.at(list_ptr_one));
            ++list_ptr_two;
            ++list_ptr_one;
        } else if (A1.at(list_ptr_one) > A2.at(list_ptr_two)) {
            ++list_ptr_two;
        } else {
            ++list_ptr_one;
        }
    }
    return result;
}
