#ifndef CHAP_FIFTEEN_H
#define CHAP_FIFTEEN_H
#include <memory>
#include "bst_prototype.h"

class BstExercises {
 public:
    BstExercises();
    ~BstExercises();
    bool IsBST(const std::unique_ptr<BSTNode<int>> &tree);
};

#endif  // CHAP_FIFTEEN_H
