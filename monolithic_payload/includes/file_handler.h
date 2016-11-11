#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <vector>
#include <string>
#include <memory>
static const uint8_t kTYPE_MASK = 7;
static const uint8_t kTYPE_OFFSET = 5;
static const uint8_t kSIZE_MASK = 31;
static const uint8_t kSIZE_OFFSET = 0;
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

    bool MarshalValue(const std::string& payload_string, int type);
    // ////////////////////////////////////////////////////////////////////////////////////
    // /// IsWellFormedBrackets(const string& s)
    // /// -------------------------------------------------------------------------------
    // /// Evalute return whether provided string of characters `(`, `)`, `[`, `]`, `{`, `}`
    // /// is well formed.
    // /// The string is well-formed if each open bracket has a corresponding closing bracket
    // /// in the correct order
    // /// -------------------------------------------------------------------------------
    // /// - @param[in] bracket_str -- string containing sequence of bracket characers (listed above)
    // /// - @return[out] bool      -- True for well-formed. False for malformed
    // /// -------------------------------------------------------------------------------
    // bool IsWellFormedBrackets(const std::string& bracket_str);

    // std::vector<std::vector<int>> BinTreeLevelOrder(const std::unique_ptr<BinaryTreeNode<int>>& tree); //NOLINT

    // ////////////////////////////////////////////////////////////////////////////////////
    // /// Helper Methods
    // std::shared_ptr<MaxStack> CreateStack(int n);
    // std::shared_ptr<MaxStack> CreateStack(const std::vector<int> &elements);
    // void TestMaxStack(const std::vector<int> &elements);
    // void TestStackScope(const std::shared_ptr<MaxStack> &s);
    // void TestCircularQueue();
    // void TestQueueStacks();
};

#endif  // FILE_HANDLER_H
