#include <iostream>
#include <vector>
#include <memory>
#include <cassert> //NOLINT
#include "includes/chap_twelve.h"
using namespace std; //NOLINT

void SearchFirstOfK(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::SearchFirstOfK <<---<<--- " << std::endl;
    std::vector<int> int_list {-14, -10, 2, 108, 108, 243, 285, 285, 401};
    int k = 185;
    int result_index = search_exerciser->SearchFirstOfK(int_list, k);
    std::cout << "\t SearchFirstOfK Index Result: " << result_index << std::endl;
}

void RunTests(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    SearchFirstOfK(search_exerciser);
    // ReverseSubList(search_exerciser);
    // HasCycle(search_exerciser);
    // CheckOverlap(search_exerciser);
    // RemoveKthLast(search_exerciser);
    // EvenOddMerge(search_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch12_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<SearchExercises> search_exerciser(new SearchExercises());
    RunTests(search_exerciser.get());
    return 0;
}
