#ifndef CHAP_FIFTEEN_H
#define CHAP_FIFTEEN_H
#include <memory>
#include "./bst_prototype.h"

class BstExercises {
 public:
    BstExercises();
    ~BstExercises();
    bool IsBST(const std::unique_ptr<BSTNode<int>> &tree);

 private:
    bool CheckKeysIsBST(const std::unique_ptr<BSTNode<int>> &bst_node, int min, int max);
};

#endif  // CHAP_FIFTEEN_H
