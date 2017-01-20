#include <cassert>
#include <iostream>
#include <memory>
#include "includes/chap_fourteen.h"

// Exercise 14.1
void ComputeListIntersection(SortingExercises *sorting_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::ComputeListIntersection() " << std::endl;
    std::vector<int> list_one = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    std::vector<int> list_two = {5, 5, 6, 8, 8, 9, 10, 10};
    std::vector<int> intersection_result = sorting_exerciser->ComputeListIntersection(list_one, list_two);
    sorting_exerciser->PrintCollection(intersection_result, "Intersection Result: ");
    intersection_result = sorting_exerciser->ComputeListIntersectionAlt(list_one, list_two);
    sorting_exerciser->PrintCollection(intersection_result, "Alt Intersection Result: ");
}

void MergeTwoSortedArrays(SortingExercises *sorting_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::::MergeTwoSortedArrays() " << std::endl;
    int size_one = 3;
    std::vector<int> B = {3, 7, 11, 19};
    std::vector<int> A(size_one + B.size());
    A[0] = 5;
    A[1] = 13;
    A[2] = 17;

    sorting_exerciser->PrintCollection(A, "A1 List MergeTwoArrays: ");
    sorting_exerciser->PrintCollection(B, "A2 List MergeTwoArrays: ");
    sorting_exerciser->MergeTwoSortedArrays(A.data(), size_one, B.data(), B.size());
    sorting_exerciser->PrintCollection(A, "A1 Result for MergeTwoArrays: ");
    // Verify result
    for (size_t i = 1; i < A.size(); ++i) {
        assert(A[i - 1] <= A[i]);
    }
}

void run_tests(std::shared_ptr<SortingExercises> sorting_exerciser) {
    ComputeListIntersection(sorting_exerciser.get());
    MergeTwoSortedArrays(sorting_exerciser.get());
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch14_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<SortingExercises> sorting_exerciser(new SortingExercises());
    run_tests(sorting_exerciser);
    return 0;
}
