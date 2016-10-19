#include <iostream>
#include <string>
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
    if (left == nullptr && right == nullptr) {
        return true;
    } else if (left != nullptr && right != nullptr) {
        return ((left->data == right->data) &&
                CheckSymmetry(left->right, right->left) &&
                CheckSymmetry(left->left, right->right));
    } else {
        return false;
    }
}

/// -------------------------------------------------------------------------------
/// Lowest Common Ancestor Alternate
/// TODO(jdevore): LCA standard binary search (no extra structures)
/// -------------------------------------------------------------------------------
// Nodes must be Distinct,
// The Root is the LCA when the two nodes are on opposite sides of the tree
// find path to nodeA (save node path in list) - binary search for nodeA in left tree, if not found, binary search for node in right tree
// find path to nodeB (save node path to b in list) - binary search for nodeB in left tree, if not found, binary search for node in right tree
// iterate over both lists until an equal node is found , this is the LCA
/// -------------------------------------------------------------------------------
// BinaryTreeNode<int>* BinaryTreeExercises::FindLcaAlt(const unique_ptr<BinaryTreeNode<int>>& tree,
//                                                   const unique_ptr<BinaryTreeNode<int>>& nodeA,
//                                                   const unique_ptr<BinaryTreeNode<int>>& nodeB) {}
/// -------------------------------------------------------------------------------


BinaryTreeNode<int>* BinaryTreeExercises::FindLCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                                                  const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                                  const unique_ptr<BinaryTreeNode<int>>& nodeB) {
    // Nodes must be Distinct,
    // The Root is the LCA when the two nodes are on opposite sides of the tree
    return LCASearchHelper(tree, nodeA, nodeB).lowest_common_ancestor;
}

BinaryTreeExercises::lca_info BinaryTreeExercises::LCASearchHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                                              const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                              const unique_ptr<BinaryTreeNode<int>>& nodeB) {
    if (tree == nullptr) {
        return {0, nullptr}; // return empty lca_info struct
    }

    // Search Left Sub-tree
    auto left_subtree_res = LCASearchHelper(tree->left, nodeA, nodeB);
    if (left_subtree_res.num_discovered_nodes == 2) {
        return left_subtree_res;  // found both target nodes in left subtree
    }

    // Search Right Sub-tree
    auto right_subtree_res = LCASearchHelper(tree->left, nodeA, nodeB);
    if (right_subtree_res.num_discovered_nodes == 2) {
        return right_subtree_res;  // found both target nodes in right subtree
    }

    // Get total of nodes found from both sub trees + if current node == target
    int num_discovered_nodes = right_subtree_res.num_discovered_nodes +
                               left_subtree_res.num_discovered_nodes +
                               (tree == nodeA) + (tree == nodeB);

    // return lca_info struct with number of discovered nodes.
    // If we have found both, return pointer to current node as this is the LCA
    return {num_discovered_nodes , num_discovered_nodes == 2 ? tree.get() : nullptr};
}

BinaryTreeNode<int>* BinaryTreeExercises::FindLcaAlt(const unique_ptr<BinaryTreeNode<int>>& tree,
                                                     const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                                     const unique_ptr<BinaryTreeNode<int>>& nodeB) {
    return nullptr;
}

BinaryTreeNode<int>* BinaryTreeExercises::FindLCAParents(const unique_ptr<BinTreeNodeP<int>>& tree,
                                                         const unique_ptr<BinTreeNodeP<int>>& nodeA,
                                                         const unique_ptr<BinTreeNodeP<int>>& nodeB) {
    return nullptr;
}

