#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <vector>
#include <string>
#include <memory>
#include "./max_stack.h"
#include "./queue_stacks.h"
#include "./bst_node_prototype.h"
#include "./circular_queue.h"
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// FileHandler
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class FileHandler {
 public:
    FileHandler();
    ~FileHandler();

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
    std::shared_ptr<MaxStack> CreateStack(const std::vector<int> &elements);
    void TestMaxStack(const std::vector<int> &elements);
    void TestStackScope(const std::shared_ptr<MaxStack> &s);
    void TestCircularQueue();
    void TestQueueStacks();
};

#endif  // FILE_HANDLER_H
