#include <cassert> //NOLINT
#include <iostream>
#include "includes/chap_eleven.h"
using namespace std; //NOLINT

void SortKSortedList(HeapExercises* heap_exerciser) {
    std::cout << "\n--->>--->> main::SortKSortedList <<---<<--- " << std::endl;
    std::vector<int> int_list {3,-1,2,6,4,5,8};
    int k = 2;
    std::stringstream ss;
    for (int x : int_list) {
      ss << x << ' ';
    }
    istringstream sequence(ss.str());
    std::vector<int> result = heap_exerciser->SortKSortedList(&sequence, k);
    std::cout << "\n[ ";
    for (auto &v : result) {
      std::cout << v << " ";
    }std::cout << "]" <<std::endl;
}

void RunTests(HeapExercises* heap_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    SortKSortedList(heap_exerciser);
    // EvaluateRPN(heap_exerciser);
    // IsWellFormedBrackets(heap_exerciser);
    // BinaryTreeLevelOrder(heap_exerciser);
    // TestCircularQueue(heap_exerciser);
    // TestQueueStacks(heap_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch11_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HeapExercises> heap_exerciser(new HeapExercises());
    RunTests(heap_exerciser.get());
    return 0;
}
