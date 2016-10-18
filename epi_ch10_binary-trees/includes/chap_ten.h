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
    bool IsHeightBalanced(const unique_ptr<BinaryTreeNode<int>>& tree_root);
    bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree_root);
    BinaryTreeNode<int>* FindLCA(const unique_ptr<BinaryTreeNode<int>>& tree,
                                 const unique_ptr<BinaryTreeNode<int>>& nodeA,
                                 const unique_ptr<BinaryTreeNode<int>>& nodeB);

 private:
    /// IsHeightBalanced Helper Method
    TreeHeightStats GetHeightBalance(const unique_ptr<BinaryTreeNode<int>>& tree);
    bool CheckSymmetry(const unique_ptr<BinaryTreeNode<int>>& left,
                       const unique_ptr<BinaryTreeNode<int>>& right);
};

#endif  // CHAP_TEN_H
