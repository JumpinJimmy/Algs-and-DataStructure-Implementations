#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include "includes/chap_fifteen.h"

// Exercise 14.4
void TestName(BstExercises *bst_exerciser) {
    // std::cout << "--->>--->> ch14-Sorting::TestName() " << std::endl;
    // std::vector<Event> A = {{1, 5}, {2, 7}, {4, 5}, {6, 10}, {8, 9},
    //                         {9, 17}, {11, 13}, {12, 15}, {14, 15}};
    // int expected_answer = 3;

    // int result = bst_exerciser->FindMaxSimultaneousEvents(A);
    // std::cout << "\t\\--->> ch14-Sorting::FindMaxSimultaneousEvents Result:" << result << std::endl;
    // assert(result == expected_answer);
}

void run_tests(std::shared_ptr<BstExercises> bst_exerciser) {
    TestName(bst_exerciser.get());
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch14_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<BstExercises> bst_exerciser(new BstExercises());
    run_tests(bst_exerciser);
    return 0;
}
