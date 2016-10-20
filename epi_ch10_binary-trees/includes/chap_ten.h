#ifndef CHAP_TEN_H
#define CHAP_TEN_H
#include <memory>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
#include "./binary_tree_node.h"
#include "./binary_tree_node_parent.h"
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// BinaryTreeExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
struct TreeHeightStats {
    bool balanced;
    int height;
};

class BinaryTreeExercises {
 public:
    BinaryTreeExercises();
    ~BinaryTreeExercises();

    ////////////////////////////////////////////////////////////////////////////////////
    /// IsHeightBalanced
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    bool IsHeightBalanced(const unique_ptr<BinaryTreeNode<int>>& tree_root);

    ////////////////////////////////////////////////////////////////////////////////////
    /// IsSymmetric
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree_root);

    ////////////////////////////////////////////////////////////////////////////////////
    /// FindLCA
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    BinaryTreeNode<int>* FindLCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                                 const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                 const unique_ptr<BinaryTreeNode<int>>& nodeB);

    ////////////////////////////////////////////////////////////////////////////////////
    /// FindLCAParents
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// LCA where nodes have parent pointers
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------

    BinaryTreeNode<int>* FindLCAParents(const unique_ptr<BinTreeNodeP<int>>& tree,
                                 const unique_ptr<BinTreeNodeP<int>>& nodeA,
                                 const unique_ptr<BinTreeNodeP<int>>& nodeB);

    ////////////////////////////////////////////////////////////////////////////////////
    /// FindLCA Alternate TODO(jdevore): LCA standard binary search (no extra structures)
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    BinaryTreeNode<int>* FindLcaAlt(const unique_ptr<BinaryTreeNode<int>>& tree,
                                    const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                    const unique_ptr<BinaryTreeNode<int>>& nodeB);

    ////////////////////////////////////////////////////////////////////////////////////
    /// InOrderTraversal()
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// In-order traversal using O(1) space
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    /// Nodes have parent pointers (if not, you must have a way to keep track of a node's parent)
    /// NOTE: determine how to track whether a node is it's parent's left or right child
    /// Using a stack will get rid of recursion, however, there is no need to store all visited nodes.
    /// Use the parent node pointers to follow the in-order traversal scheme
    /// Visit node, visit left child, go back to parent, vist right child, go back to parent
    /// return a vector containing the inorder traversal sequence
    std::vector<int> InOrderTraversal(const unique_ptr<BinTreeNodeP<int>>& tree);

    std::vector<int> InOrderIterative(const unique_ptr<BinaryTreeNode<int>>& tree);

    std::vector<int> PreOrderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree);
    ////////////////////////////////////////////////////////////////////////////////////
    /// BtFromInPreOrder()
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// Construct a binary tree given inorder and preorder traversals
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    std::shared_ptr<BinaryTreeNode<int>> BtFromInPreOrder(const std::vector<int> &inorder,
                                                          const std::vector<int> &preorder,
                                                          std::unordered_map<int, size_t> node_inord_idx);

    ////////////////////////////////////////////////////////////////////////////////////
    /// Helper Method
    template <typename T>
    void PrintListInline(const std::vector<T> &list, std::string details = "") {
        if (!details.empty()) {
            std::cout << details << " ";
        }
        if (!list.empty()) {
            std::cout << "\n [ ";
            for (auto &val : list) {
                std::cout << val << " ";
            }
            std::cout << "];" << std::endl;
        }
    }

 private:
    /// Helper struct for @FindLCA(). Used within private method @LCASearchHelper
    struct lca_info {
        int num_discovered_nodes;
        BinaryTreeNode<int>* lowest_common_ancestor;
    };

    void PreOrderHelper(BinaryTreeNode<int>* node,
                        std::vector<BinaryTreeNode<int>*> &traversal_queue);

    /// Helper method for @FindLCA(tree, node, node)
    lca_info LCASearchHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                             const unique_ptr<BinaryTreeNode<int>>& nodeA,
                             const unique_ptr<BinaryTreeNode<int>>& nodeB);

    /// Helper Method for @IsHeightBalanced
    TreeHeightStats GetHeightBalance(const unique_ptr<BinaryTreeNode<int>>& tree);

    /// Helper method for @IsSymmetric
    bool CheckSymmetry(const unique_ptr<BinaryTreeNode<int>>& left,
                       const unique_ptr<BinaryTreeNode<int>>& right);
};

#endif  // CHAP_TEN_H
