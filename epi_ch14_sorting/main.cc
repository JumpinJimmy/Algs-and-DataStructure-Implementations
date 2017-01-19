#include <cassert>
#include <iostream>
#include <algorithm>
#include <memory>
#include "includes/chap_fourteen.h"

void ComputeListIntersection(SortingExercises *sorting_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::ComputeListIntersection() " << std::endl;
    std::vector<int> list_one = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    std::vector<int> list_two = {5, 5, 6, 8, 8, 9, 10, 10};
    std::vector<int> intersection_result = sorting_exerciser->ComputeListIntersection(list_one, list_two);
}

void run_tests(std::shared_ptr<SortingExercises> sorting_exerciser) {
    ComputeListIntersection(sorting_exerciser.get());
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch14_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<SortingExercises> sorting_exerciser(new SortingExercises());
    run_tests(sorting_exerciser);
    return 0;
}
