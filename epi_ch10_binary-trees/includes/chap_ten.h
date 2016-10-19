#ifndef CHAP_TEN_H
#define CHAP_TEN_H
#include <memory>
#include <vector>
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

    /// LCA where nodes have parent pointers
    BinaryTreeNode<int>* FindLCAParents(const unique_ptr<BinTreeNodeP<int>>& tree,
                                 const unique_ptr<BinTreeNodeP<int>>& nodeA,
                                 const unique_ptr<BinTreeNodeP<int>>& nodeB);

    ////////////////////////////////////////////////////////////////////////////////////
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

    /// In-order traversal using O(1) space
    std::vector<int> InOrderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree);

    std::shared_ptr<BinaryTreeNode<int>> BtFromInPreOrder(const std::vector<int> &inorder,
                                                          const std::vector<int> &preorder,
                                                          std::unordered_map<int, size_t> node_inord_idx);

 private:
    struct lca_info {
        int num_discovered_nodes;
        BinaryTreeNode<int>* lowest_common_ancestor;
    };

    /// Helper method for @FindLCA(tree, node, node)
    lca_info LCASearchHelper(const unique_ptr<BinaryTreeNode<int>>& tree,
                             const unique_ptr<BinaryTreeNode<int>>& nodeA,
                             const unique_ptr<BinaryTreeNode<int>>& nodeB);

    /// IsHeightBalanced Helper Method
    TreeHeightStats GetHeightBalance(const unique_ptr<BinaryTreeNode<int>>& tree);
    bool CheckSymmetry(const unique_ptr<BinaryTreeNode<int>>& left,
                       const unique_ptr<BinaryTreeNode<int>>& right);
};

#endif  // CHAP_TEN_H
