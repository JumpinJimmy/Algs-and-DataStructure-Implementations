#ifndef CHAP_FIFTEEN_H
#define CHAP_FIFTEEN_H
#include <memory>
#include <vector>
#include "./bst_prototype.h"

class BstExercises {
 public:
    BstExercises();
    ~BstExercises();
    bool IsBST(const std::unique_ptr<BSTNode<int>> &tree);
    bool IsBinarySearchTreeDFS(const std::unique_ptr<BSTNode<int>> &tree);
    BSTNode<int>* FirstGreaterKey(const std::unique_ptr<BSTNode<int>> &tree, int key);
    std::vector<int> RetreiveKLargestKeys(const std::unique_ptr<BSTNode<int>> &tree, int k);
    BSTNode<int>* FindLCA(const std::unique_ptr<BSTNode<int>> &tree,
                          const std::unique_ptr<BSTNode<int>> &node_a,
                          const std::unique_ptr<BSTNode<int>> &node_b);

 private:
    bool CheckKeysIsBST(const std::unique_ptr<BSTNode<int>> &bst_node, int min, int max);
};

#endif  // CHAP_FIFTEEN_H
