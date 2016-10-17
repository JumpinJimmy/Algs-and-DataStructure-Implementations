#ifndef CHAP_NINE_H
#define CHAP_NINE_H
#include <stdlib.h>
#include <vector>
#include "max_stack.h"
#include "queue_stacks.h"
#include "bst_node_prototype.h"
#include "circular_queue.h"
#include "queue_stacks.h"
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
    /// IsWellFormedBrackets(const string& s)
    /// -------------------------------------------------------------------------------
    /// Evalute return whether provided string of characters `(`, `)`, `[`, `]`, `{`, `}`
    /// is well formed.
    /// The string is well-formed if each open bracket has a corresponding closing bracket
    /// in the correct order
    /// -------------------------------------------------------------------------------
    /// - @param[in] bracket_str -- string containing sequence of bracket characers (listed above)
    /// - @return[out] bool      -- True for well-formed. False for malformed
    /// -------------------------------------------------------------------------------
    bool IsWellFormedBrackets(const std::string& bracket_str);

    std::vector<std::vector<int>> BinTreeLevelOrder(const std::unique_ptr<BinaryTreeNode<int>>& tree); //NOLINT

    ////////////////////////////////////////////////////////////////////////////////////
    /// Helper Methods
    std::shared_ptr<MaxStack> CreateStack(int n);
    std::shared_ptr<MaxStack> CreateStack(std::vector<int> &elements);
    void TestMaxStack(std::vector<int> &elements);
    void TestStackScope(std::shared_ptr<MaxStack> &s);
    void TestCircularQueue();
    void TestQueueStacks();

    private:
};

#endif // CHAP_NINE_H
