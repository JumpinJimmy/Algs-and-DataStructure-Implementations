#include <cassert> //NOLINT
#include <iostream>
#include "includes/chap_ten.h"
using namespace std; //NOLINT

void FindLCA(BinaryTreeExercises* bintree_exerciser) {
    //      3
    //    2   5
    //  1    4 6
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    BinaryTreeNode<int> *result = bintree_exerciser->FindLCA(tree,
                                                             tree->left->left,
                                                             tree->right->left);
    std::cout << "\t -FindLCA(leftnode: " << tree->left->left->data
              << ", rightnode: " << tree->right->left->data << "): "
              << (result ? std::to_string(result->data) : "(empty)") << std::endl;

    // assert(3 == bintree_exerciser->FindLCA(tree, tree->left->left, tree->right->left)->data);
    // bintree_exerciser->FindLCA(tree, nodeA, nodeB);
}

void IsSymmetric(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::IsSymmetric <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> non_sym_tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    non_sym_tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    std::cout << "\t -IsSymmetric(non symmetric tree): " << std::boolalpha
                                     << bintree_exerciser->IsSymmetric(non_sym_tree) << std::endl;

    unique_ptr<BinaryTreeNode<int>> sym_tree =
        make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    sym_tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    sym_tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>());
    std::cout << "\t -IsSymmetric(symmetric tree): " << std::boolalpha
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
    FindLCA(bintree_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch10_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<BinaryTreeExercises> bintree_exerciser(new BinaryTreeExercises());
    RunTests(bintree_exerciser.get());
    return 0;
}
