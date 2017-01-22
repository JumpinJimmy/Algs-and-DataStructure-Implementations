#include <limits>
#include "includes/chap_fifteen.h"

BstExercises::BstExercises() {}

BstExercises::~BstExercises() {}

bool BstExercises::IsBST(const std::unique_ptr<BSTNode<int>> &tree) {
    if (!tree) {
        return true;
    }
    return CheckKeysIsBST(tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool BstExercises::CheckKeysIsBST(const std::unique_ptr<BSTNode<int>> &bst_node, int min, int max) {
    if (!bst_node) return true;
    if (bst_node->data > max || bst_node->data < min) {
        return false;
    } else {
        return CheckKeysIsBST(bst_node->right, bst_node->data, max) && CheckKeysIsBST(bst_node->left, min, bst_node->data);
    }
}
