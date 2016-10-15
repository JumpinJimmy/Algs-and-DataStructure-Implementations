#include "includes/chap_ten.h"
#include <cassert> //NOLINT
#include <iostream>
using namespace std; //NOLINT

void IsHeightBalanced(BinaryTreeExercises* bintree_exerciser) {

}

void RunTests(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch10_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<BinaryTreeExercises> bintree_exerciser(new BinaryTreeExercises());
    RunTests(bintree_exerciser.get());
    return 0;
}
