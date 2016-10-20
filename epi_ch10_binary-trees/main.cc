#include <cassert>
#include <iostream>
#include "includes/chap_ten.h"
using namespace std; //NOLINT

void TraversalTests(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::BtFromInPreOrder <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> treeA = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    treeA->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    treeA->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    treeA->left->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});

    unique_ptr<BinaryTreeNode<int>> treeB = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    treeB->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    treeB->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    treeB->right->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});

    std::vector<int> inorder_result = bintree_exerciser->InOrderIterative(treeA);
    std::vector<int> preorder_result = bintree_exerciser->PreOrderTraversal(treeA);
    bintree_exerciser->PrintListInline(inorder_result, "Inorder ResultA:");
    bintree_exerciser->PrintListInline(preorder_result, "Preorder ResultA:");
    inorder_result = bintree_exerciser->InOrderIterative(treeB);
    preorder_result = bintree_exerciser->PreOrderTraversal(treeB);
    bintree_exerciser->PrintListInline(inorder_result, "Inorder ResultB:");
    bintree_exerciser->PrintListInline(preorder_result, "Preorder ResultB:");
}
// TODO(jdevore): Clean up the test methods and write a function to build a tree
// TODO(jdevore): write more intensive tests casses
// TODO(jdevore): clean up debug out put
void BtFromInPreOrder(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::BtFromInPreOrder <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{10});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->left->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->left->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0});
    // tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    // tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    // tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    std::vector<int> inorder_result = bintree_exerciser->InOrderIterative(tree);
    std::vector<int> preorder_result = bintree_exerciser->PreOrderTraversal(tree);
    bintree_exerciser->PrintListInline(inorder_result, "Inorder Result:");
    bintree_exerciser->PrintListInline(preorder_result, "Preorder Result:");
    bintree_exerciser->BtFromInPreOrder(inorder_result, preorder_result);
    // std::vector<int> inorder = bintree_exerciser->InOrderIterative(tree);
    // std::vector<int> inorder = bintree_exerciser->PreOrderTraversal(tree);
}

void InOrderTraversalParents(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::InOrderTraversalParents <<---<<--- " << std::endl;
    unique_ptr<BinTreeNodeP<int>> root = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{3, nullptr, nullptr});
    root->parent = nullptr;
    root->right = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{5, nullptr, nullptr});
    root->right->parent = root.get();
    root->right->left = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{4, nullptr, nullptr});
    root->right->left->parent = root->right.get();
    root->right->right = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{6, nullptr, nullptr});
    root->right->right->parent = root->right.get();

    auto inorder_result = bintree_exerciser->InOrderTraversal(root);
    vector<int> golden_res = {1, 2, 3, 4, 5, 6};
    bintree_exerciser->PrintListInline(inorder_result);
}

void InOrderIterative(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::InOrderIterative <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    std::vector<int> inorder_result = bintree_exerciser->InOrderIterative(tree);
    bintree_exerciser->PrintListInline(inorder_result);
}

void FindLcaAlt(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::FindLcaAlt <<---<<--- " << std::endl;
    unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
    tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
    tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
    tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
    tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
    tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
    BinaryTreeNode<int> *result = bintree_exerciser->FindLcaAlt(tree,
                                                             tree->left->left,
                                                             tree->right->left);
    std::cout << "\t -FindLcaAlt(leftnode: " << tree->left->left->data
              << ", rightnode: " << tree->right->left->data << "): "
              << (result ? std::to_string(result->data) : "(empty)") << std::endl;
}

void FindLCAParents(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::FindLCAParents <<---<<--- " << std::endl;
    //      3
    //    2   5
    //  1    4 6
    auto parentp_node_tree = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{3, nullptr, nullptr, nullptr});
    parentp_node_tree->left = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{2, nullptr, nullptr, parentp_node_tree.get()});
    parentp_node_tree->left->left = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{1, nullptr, nullptr, parentp_node_tree->left.get()});
    parentp_node_tree->right = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{5, nullptr, nullptr, parentp_node_tree.get()});
    parentp_node_tree->right->left = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{4, nullptr, nullptr, parentp_node_tree->right.get()});
    parentp_node_tree->right->right = make_unique<BinTreeNodeP<int>>(
        BinTreeNodeP<int>{6, nullptr, nullptr});

    bintree_exerciser->FindLCAParents(parentp_node_tree,
                                      parentp_node_tree->left->left,
                                      parentp_node_tree->right->left);
}

void FindLCA(BinaryTreeExercises* bintree_exerciser) {
    std::cout << "\n--->>--->> main::FindLCA <<---<<--- " << std::endl;
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
    FindLCAParents(bintree_exerciser);
    FindLcaAlt(bintree_exerciser);
    InOrderIterative(bintree_exerciser);
    InOrderTraversalParents(bintree_exerciser);
    BtFromInPreOrder(bintree_exerciser);
    TraversalTests(bintree_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch10_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<BinaryTreeExercises> bintree_exerciser(new BinaryTreeExercises());
    RunTests(bintree_exerciser.get());
    return 0;
}
