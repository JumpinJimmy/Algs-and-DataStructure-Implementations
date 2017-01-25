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

bool BstExercises::IsBinarySearchTreeDFS(const std::unique_ptr<BSTNode<int>> &tree) {
    // PSEUDO
    /*
    Depth first Search Tree, storing upper and lower bounds alongside each node in traversal queue
    struct BSTValue { key, lower, upper}
    queue<BSTValue> q.enqueue(tree, numeric_limits:min, numeric_limits:max)

    while (!q.empty()) {
        if (q.front().tree_node.get()) {
            if (q.front().data < q.front.data.min || q.front().data > q.front.data.max) return false
            q.enqueue(q.front().tree_node.left(), q.front().lower, q.front().tree_node.data)
            q.enqueue(q.front().tree_node.right(),q.front().tree_node.data, q.front().upper )
        }
        q.pop()
    }
    return true;
     */

    return true;
}

BSTNode<int>* BstExercises::FirstGreaterKey(const std::unique_ptr<BSTNode<int>> &tree, int key) {
    // PSEUDO: Search BST using bst property (binary search) and keep track of most recently visited node
    /*
        subtree_node = tree; result = nullptr
        while (subtree_node)
            if (subtree_node.data > Key) {
                result = subtree_node
                subtree_node = subtree_node.left
            } else {
                subtree_node = subtree_node.right
            }
        return result
     */
    BSTNode<int> *result = tree.get();
    return result;
}

std::vector<int> BstExercises::RetreiveKLargestKeys(const std::unique_ptr<BSTNode<int>> &tree, int k) {
    // PSEUDO: K Largest Keys, Visit / traverse the tree from largest to smallest until we have K entries
    // right subtree, root / node , left subtree  == largest to smallest
    // store results in a list as we traverse backwards. Stop when list is of size K
    return {};
}

// TODO(jdevore): test this method
BSTNode<int>* BstExercises::FindLCA(const std::unique_ptr<BSTNode<int>> &tree,
                                    const std::unique_ptr<BSTNode<int>> &node_a,
                                    const std::unique_ptr<BSTNode<int>> &node_b) {
    // PSEUDO:
    // if (tree->data == node_a->data OR tree->data == node_b->data) return tree
    // goal: find node that satisfies the following: node_a < tree > node_b
    auto *curr_root_ptr = tree.get(); // deref unique ptr so we can update tree during traversal / search
    while (curr_root_ptr->data < node_a->data || curr_root_ptr->data > node_b->data) {
        // current root node is not inside [A,B] range
        while (curr_root_ptr->data < node_a->data) {
            // current root node is smaller than both, go to right subtree
            curr_root_ptr = curr_root_ptr->right.get();
        }
        while (curr_root_ptr->data > node_b->data) {
            // current root node is larger that both, so go left
            curr_root_ptr = curr_root_ptr->left.get();
        }
    }
        // node_a <= curr_root <= node_b --> this is the LCA
        return curr_root_ptr;
}

bool BstExercises::CheckKeysIsBST(const std::unique_ptr<BSTNode<int>> &bst_node, int min, int max) {
    if (!bst_node) return true;
    if (bst_node->data > max || bst_node->data < min) {
        return false;
    } else {
        return CheckKeysIsBST(bst_node->right, bst_node->data, max) && CheckKeysIsBST(bst_node->left, min, bst_node->data);
    }
}

