#include <cassert>
#include <iostream>
#include <random>
#include "includes/chap_fifteen.h"

// Exercise 15.1
void IsBST(BstExercises *bst_exerciser) {
    //       3
    //    2     5
    //  1     4   6
    std::cout << "--->>--->> ch14-Sorting::IsBST() " << std::endl;
    auto tree = std::make_unique<BSTNode<int>>(BSTNode<int>{3});
    tree->left = std::make_unique<BSTNode<int>>(BSTNode<int>{2});
    tree->left->left = std::make_unique<BSTNode<int>>(BSTNode<int>{1});
    tree->right = std::make_unique<BSTNode<int>>(BSTNode<int>{5});
    tree->right->left =
      std::make_unique<BSTNode<int>>(BSTNode<int>{4});
    tree->right->right =
      std::make_unique<BSTNode<int>>(BSTNode<int>{6});

    assert(bst_exerciser->IsBST(tree) == true);
    std::cout << " \t--> isBst(valid BST) Result: " << std::boolalpha << bst_exerciser->IsBST(tree) << std::endl;
    //  Invalidate BST property by setting root value larger than both sub trees
    //       10
    //    2     5
    //  1     4   6
    tree->data = 10;
    assert(!(bst_exerciser->IsBST(tree)));  // should output false.
    std::cout << " \t--> isBst(Invalid Root Value) Result: " << std::boolalpha << bst_exerciser->IsBST(tree) << std::endl;

    // Test Empty Tree
    assert(bst_exerciser->IsBST(nullptr) == true);
    std::cout << " \t--> isBst(nullptr) Result: " << std::boolalpha << bst_exerciser->IsBST(nullptr) << std::endl;
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
