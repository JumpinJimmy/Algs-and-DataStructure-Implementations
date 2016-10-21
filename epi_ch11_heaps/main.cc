#include <cassert> //NOLINT
#include <iostream>
#include "includes/chap_eleven.h"
using namespace std; //NOLINT

void EvaluateRPN(HeapExercises* heap_exerciser) {
    // std::cout << "\n--->>--->> main::EvaluateRPN <<---<<--- " << std::endl;
    // std::string expression("3,4,+,2,*,1,+");
    // std::cout << "main::EvaluateRPN(" << expression << ") = "
    //           << heap_exerciser->EvaluateRPN(expression) << std::endl;
}

void RunTests(HeapExercises* heap_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    // TestMaxElement(heap_exerciser);
    // EvaluateRPN(heap_exerciser);
    // IsWellFormedBrackets(heap_exerciser);
    // BinaryTreeLevelOrder(heap_exerciser);
    // TestCircularQueue(heap_exerciser);
    // TestQueueStacks(heap_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch9_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HeapExercises> heap_exerciser(new HeapExercises());
    RunTests(heap_exerciser.get());
    return 0;
}
