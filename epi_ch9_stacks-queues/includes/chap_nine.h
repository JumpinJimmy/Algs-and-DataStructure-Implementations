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

    ////////////////////////////////////////////////////////////////////////////////////
    /// EvaluateRPN(const string& RPN_expression)
    /// -------------------------------------------------------------------------------
    /// Evalute and Return Resulting Integer from RPN Expression String
    /// -------------------------------------------------------------------------------
    /// - @param[in] RPN_expression -- string in RPN notation
    /// - @return[out] int         -- resulting int value of RPN expression in base-10
    /// -------------------------------------------------------------------------------
    int EvaluateRPN(const std::string& RPN_expression);

    ////////////////////////////////////////////////////////////////////////////////////
    /// Helper Methods
    std::shared_ptr<MaxStack> CreateStack(int n);
    std::shared_ptr<MaxStack> CreateStack(std::vector<int> &elements);
    void TestMaxStack(std::vector<int> &elements);
    void TestStackScope(std::shared_ptr<MaxStack> &s);

    private:
};

#endif // CHAP_NINE_H
