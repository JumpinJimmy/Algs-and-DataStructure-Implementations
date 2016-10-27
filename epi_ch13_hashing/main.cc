#include <cassert> //NOLINT
#include <iostream>
#include <memory>

#include "includes/chap_thirteen.h"
using namespace std; //NOLINT

// void test(HashTableExercises* ht_exerciser) {

// }

void RunTests(HashTableExercises* ht_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    // TestMaxElement(ht_exerciser);
    // EvaluateRPN(ht_exerciser);
    // IsWellFormedBrackets(ht_exerciser);
    // BinaryTreeLevelOrder(ht_exerciser);
    // TestCircularQueue(ht_exerciser);
    // TestQueueStacks(ht_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch9_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HashTableExercises> ht_exerciser(new HashTableExercises());
    RunTests(ht_exerciser.get());
    return 0;
}
