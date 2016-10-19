#ifndef CHAP_TEN_H
#define CHAP_TEN_H
#include <memory>
#include "./binary_tree_node.h"
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
    // BinaryTreeNode<int>* BinaryTreeExercises::FindLcaAlt(const unique_ptr<BinaryTreeNode<int>>& tree,
    //                                                   const unique_ptr<BinaryTreeNode<int>>& nodeA,
    //                                                   const unique_ptr<BinaryTreeNode<int>>& nodeB) {

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
