#include <iostream>
#include <string>
#include <vector>
#include "includes/chap_ten.h"

BinaryTreeExercises::BinaryTreeExercises() {}

BinaryTreeExercises::~BinaryTreeExercises() {}

bool BinaryTreeExercises::IsHeightBalanced(const unique_ptr<BinaryTreeNode<int>>& tree_root) {
    /// Get Height of Left Sub Tree
    /// Get Height of Right Sub Tree
    /// if difference in height between left & right is > 1; It is not balanced
    /// if we reach a leaf, return
    return GetHeightBalance(tree_root).balanced;
}

bool BinaryTreeExercises::IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree_root) {
    /// A symmetric tree:  left and right subtrees are equal
    /// recurse through both sub trees, checking each for equality before moving to next child
    /// an empty tree is symmetric
    if (tree_root == nullptr) {
        return true;
    } else {
        return CheckSymmetry(tree_root->left, tree_root->right);
    }
}

TreeHeightStats BinaryTreeExercises::GetHeightBalance(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (tree == nullptr) {
        return {true, -1};
    }

    auto left_tree_result = GetHeightBalance(tree->left);
    if (!left_tree_result.balanced) {
        return {false, 0};
    }

    auto right_tree_result = GetHeightBalance(tree->right);
    if (!right_tree_result.balanced) {
        return {false, 0};
    }

    bool balanced_result = abs(left_tree_result.height - right_tree_result.height) <= 1;
    int height_result = std::max(left_tree_result.height, right_tree_result.height);
    return {balanced_result, height_result};
}

bool BinaryTreeExercises::CheckSymmetry(const unique_ptr<BinaryTreeNode<int>>& left,
                                        const unique_ptr<BinaryTreeNode<int>>& right) {
    return false;
}
