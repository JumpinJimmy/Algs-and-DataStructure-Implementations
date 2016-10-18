#include <cassert> //NOLINT
#include <iostream>
#include "includes/chap_ten.h"
using namespace std; //NOLINT

void IsSymmetric(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::IsSymmetric <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> non_sym_tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    std::cout << "\t -IsSymmetric: " << std::boolalpha
                                     << bintree_exerciser->IsSymmetric(non_sym_tree) << std::endl;
    unique_ptr<BinaryTreeNode<int>> sym_tree =
        make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    sym_tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    sym_tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    std::cout << "\t -IsSymmetric: " << std::boolalpha
                                     << bintree_exerciser->IsSymmetric(sym_tree) << std::endl;
}
void IsHeightBalanced(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::IsHeightBalanced <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    std::cout << "\t -IsHeightBalanced: " << std::boolalpha
                                          << bintree_exerciser->IsHeightBalanced(tree) << std::endl;
}

void RunTests(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    IsHeightBalanced(bintree_exerciser);
    IsSymmetric(bintree_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch10_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<BinaryTreeExercises> bintree_exerciser(new BinaryTreeExercises());
    RunTests(bintree_exerciser.get());
    return 0;
}
