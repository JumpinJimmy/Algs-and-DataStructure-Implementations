#include <cassert>
#include <iostream>
#include <random>
#include "includes/chap_fifteen.h"

// Exercise 14.4
void IsBST(BstExercises *bst_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::IsBST() " << std::endl;
    std::unique_ptr<BSTNode<int>> treeA = std::make_unique<BSTNode<int>>(BSTNode<int>{1});

    std::cout << " \t--> isBst() Result: " << std::boolalpha << bst_exerciser->IsBST(treeA) << std::endl;
}

void run_tests(std::shared_ptr<BstExercises> bst_exerciser) {
    IsBST(bst_exerciser.get());
}

// valgrind --leak-check=full --show-leak-kinds=all ./bst_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<BstExercises> bst_exerciser(new BstExercises());
    run_tests(bst_exerciser);
    return 0;
}
