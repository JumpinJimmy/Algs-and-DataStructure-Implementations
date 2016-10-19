// #include <stack>
// #include <deque>
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
    /// A symmetric tree:  left and right are "mirror" images
    /// recurse through both sub trees respective left and right decendents,
    /// checking each current node for equality before moving to next children
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

BinaryTreeNode<int>* BinaryTreeExercises::FindLCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                                                  const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                                  const unique_ptr<BinaryTreeNode<int>>& nodeB) {
    /// Nodes must be Distinct
    /// QUESTION: if one of the target nodes is the root, the only possible LCA is the root (if other node exists)
    /// The Root is the LCA when the two nodes are on opposite sides of the tree
    return LCASearchHelper(tree, nodeA, nodeB).lowest_common_ancestor;
}

BinaryTreeExercises::lca_info BinaryTreeExercises::LCASearchHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                                              const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                              const unique_ptr<BinaryTreeNode<int>>& nodeB) {
    if (tree == nullptr) {
        return {0, nullptr};  /// return empty lca_info struct (reached bottom leaf or tree is empty)
    }

    /// Search Left Sub-tree
    auto left_subtree_res = LCASearchHelper(tree->left, nodeA, nodeB);
    if (left_subtree_res.num_discovered_nodes == 2) {
        return left_subtree_res;  // found both target nodes in left subtree
    }

    /// Search Right Sub-tree
    auto right_subtree_res = LCASearchHelper(tree->right, nodeA, nodeB);
    if (right_subtree_res.num_discovered_nodes == 2) {
        return right_subtree_res;  /// found both target nodes in right subtree
    }

    /// Have not found both Nodes yet
    /// Get total of nodes found thus far + if current node == targetA and/or targetB
    int num_discovered_nodes = right_subtree_res.num_discovered_nodes +
                               left_subtree_res.num_discovered_nodes +
                               (tree == nodeA) + (tree == nodeB);

    /// return lca_info struct with number of discovered nodes.
    /// If we have found both, return pointer to current node as this is the LCA
    return {num_discovered_nodes , num_discovered_nodes == 2 ? tree.get() : nullptr};
}

BinaryTreeNode<int>* BinaryTreeExercises::FindLcaAlt(const unique_ptr<BinaryTreeNode<int>>& tree,
                                                     const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                                     const unique_ptr<BinaryTreeNode<int>>& nodeB) {
    /// Nodes must be Distinct
    /// The Root is the LCA if one of the target nodes == root || the nodes are on opposite sides of tree stemming from ROOT
    /// find path to nodeA (save node path in lista)
    ///     binary search for nodeA in left tree, if not found, binary search for node in right tree
    /// find path to nodeB (save node path to b in listb)
    ///     binary search for nodeB in left tree, if not found, binary search for node in right tree
    /// if node path lists have equal length,
    ///     traverse both in order until an equal node is found, this is the LCA
    /// if node path lists have differing length,
    ///     traverse longer list N times (where N = list length difference)
    ///     Once finished iterating over longer list N times:
    ///         iterate over both lists in tandem until an equal node is found, this is the LCA
    return nullptr;
}

BinaryTreeNode<int>* BinaryTreeExercises::FindLCAParents(const unique_ptr<BinTreeNodeP<int>>& tree,
                                                         const unique_ptr<BinTreeNodeP<int>>& nodeA,
                                                         const unique_ptr<BinTreeNodeP<int>>& nodeB) {
    /// if one of the nodes is the root, return root (if other node exists)
    /// locate nodeA via traversal of tree, recording depthA of traversal along the way
    /// locate nodeA via traversal of tree, recording depthB of traversal along the way
    /// if both have been located; compare the depths of the two traversals.
    ///    if depth equal for both, follow both node parent pointers up tree in tandem until ancestor is found (nodeA == nodeB)
    ///    if depth !equal; follow deepest node parent pointer up tree until depths equal
    ///       (follow deepest parent ptr up N iterations where N is the differnce in depths )
    ///       Once depths are equal:
    ///           follow both node parent points up tree in tandem unil ancestor is found
    ///           return ancestor
    return nullptr;
}
    // std:stack<BinTreeNodeP<int>> traversal_stack;
    // std::stack<int> c1;
    // // BinTreeNodeP<int> *curr_node = tree.get();
    // traversal_stack.push(curr_node);
std::vector<int> BinaryTreeExercises::InOrderTraversal(const unique_ptr<BinTreeNodeP<int>>& tree) {
    /// Start by implementing in order traversal without recrsion

    if (!tree) {
        std::cout << "--->>--->> BinaryTreeExercises::InOrderTraversal ERROR tree is null" << std::endl;
        return {};
    }

    BinTreeNodeP<int> *curr_node = tree.get();
    std::vector<int> result_list;
    std::stack<BinTreeNodeP<int>*> traversal_stack;

    while (true) {
        if (curr_node != nullptr) {
            BinTreeNodeP<int> *left_child = curr_node->left.get();
            traversal_stack.push(curr_node);
            curr_node = left_child;
        } else if (traversal_stack.empty()) {
            return result_list;
        } else {
            curr_node = traversal_stack.top();
            std::cout << (curr_node != nullptr ? std::to_string(curr_node->data) : "nullptr") << std::endl;
            result_list.emplace_back(curr_node->data);
            BinTreeNodeP<int> *right_child = curr_node->right.get();
            traversal_stack.pop();
            curr_node = right_child;
        }
    }
    return result_list;
}

std::vector<int> BinaryTreeExercises::InOrderIterative(const unique_ptr<BinTreeNodeP<int>>& tree) {
    if (!tree) {
        std::cout << "--->>--->> BinaryTreeExercises::InOrderTraversal ERROR tree is null" << std::endl;
        return {};
    }

    BinTreeNodeP<int> *curr_node = tree.get();
    std::vector<int> result_list;
    std::stack<BinTreeNodeP<int>*> traversal_stack;

    while (true) {
        if (curr_node != nullptr) {
            BinTreeNodeP<int> *left_child = curr_node->left.get();
            traversal_stack.push(curr_node);
            curr_node = left_child;
        } else if (traversal_stack.empty()) {
            return result_list;
        } else {
            curr_node = traversal_stack.top();
            std::cout << (curr_node != nullptr ? std::to_string(curr_node->data) : "nullptr") << std::endl;
            result_list.emplace_back(curr_node->data);
            BinTreeNodeP<int> *right_child = curr_node->right.get();
            traversal_stack.pop();
            curr_node = right_child;
        }
    }
    return result_list;
}

/// Construct a binary tree given inorder and preorder traversals
std::shared_ptr<BinaryTreeNode<int>> BinaryTreeExercises::BtFromInPreOrder(const std::vector<int> &inorder,
                                                                           const std::vector<int> &preorder,
                                                                           std::unordered_map<int, size_t> node_inord_idx) {
    /// Assume each node has a unique key
    /// There exists a single unique Binary Tree that can be represented via a pre-order & In-order traversal of that tree
    /// Given those two traversal sequences, construct that unique binary tree
    /// NOTE: if only one traversal type is given, one could construct numerous valid binary trees from the one sequence
    ///       It is important to note that the presence of two traversals indicates that there is only one possible tree result
    return nullptr;
}
