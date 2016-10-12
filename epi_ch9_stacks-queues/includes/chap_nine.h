#ifndef CHAP_NINE_H
#define CHAP_NINE_H
#include <iostream>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>
#include <numeric>
#include <memory>
#include "max_stack.h"
// #include "linked_list_prototype.h"
// #include "doubly_linked_list_prototype.h"

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// StackQueueExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class StackQueueExercises {
    public:
    StackQueueExercises();
    ~StackQueueExercises();
    void TestMaxStack(std::vector<int> &elements);
    void TestStackScope(std::shared_ptr<MaxStack> &s);
    std::shared_ptr<MaxStack> CreateStack(int n);
    std::shared_ptr<MaxStack> CreateStack(std::vector<int> &elements);

    private:
};

#endif // CHAP_NINE_H
