#include "includes/chap_nine.h"
#include <cassert> //NOLINT
#include <iostream>
using namespace std; //NOLINT

void TestQueueStacks(StackQueueExercises* sq_exerciser) {
  std::cout << "\n--->>--->> main::TestQueueStacks <<---<<--- " << std::endl;
  sq_exerciser->TestQueueStacks();
}

void TestCircularQueue(StackQueueExercises* sq_exerciser) {
  std::cout << "\n--->>--->> main::TestCircularQueue <<---<<--- " << std::endl;
  sq_exerciser->TestCircularQueue();
}

void TestMaxElement(StackQueueExercises* sq_exerciser) {
    std::cout << "\n--->>--->> main::TestMaxElement <<---<<--- " << std::endl;
    std::vector<int> v {1, 2, 3, 4};
    // sq_exerciser->TestMaxStack(v);
    std::shared_ptr<MaxStack> stack = sq_exerciser->CreateStack(v);
    std::cout << "TestMaxElement::CreateStack Result->Top(): " << stack->Top()
              << ", Result->Max(): " << stack->Max()
              << ", Result->stack_size(): " << stack->stack_size() << std::endl;
    sq_exerciser->TestStackScope(stack);
    std::shared_ptr<MaxStack> int_stack = sq_exerciser->CreateStack(10);
    std::cout << "TestMaxElement::CreateStack stack_size->Top(): " << int_stack->Top()
              << ", stack_size->Max(): " << int_stack->Max()
              << ", stack_size->stack_size(): " << int_stack->stack_size() << std::endl;
    sq_exerciser->TestStackScope(int_stack);
}

void BinaryTreeLevelOrder(StackQueueExercises* sq_exerciser) {
  /*********************************
          Binary Tree to Test
                  3
                /   \
               2      5
              / \    /
             1   4  6
            /
          10
         /
        13
  *********************************/
    std::cout << "\n--->>--->> main::BinaryTreeLevelOrder <<---<<--- " << std::endl;
  std::unique_ptr<BinaryTreeNode<int>> tree = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {3, nullptr, nullptr});
  tree->left = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {2, nullptr, nullptr});
  tree->left->left = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {1, nullptr, nullptr});
  tree->left->left->left = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {10, nullptr, nullptr});
  tree->left->left->left->right = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {13, nullptr, nullptr});
  tree->right = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {5, nullptr, nullptr});
  tree->right->left = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {4, nullptr, nullptr});
  tree->right->right = std::make_unique<BinaryTreeNode<int>>(
      BinaryTreeNode<int> {6, nullptr, nullptr});

  auto result = sq_exerciser->BinTreeLevelOrder(tree);
  vector<vector<int>> golden_res = {{3}, {2, 5}, {1, 4, 6}, {10}, {13}};
  assert(equal(golden_res.begin(), golden_res.end(), result.begin(),
               result.end()));
}

void IsWellFormedBrackets(StackQueueExercises* sq_exerciser) {
    std::cout << "\n--->>--->> main::IsWellFormedBrackets <<---<<--- " << std::endl;
    std::string bracket_str("([]){()}");
    std::cout << "main::IsWellFormedBrackets(" << bracket_str << ") = "
              << std::boolalpha << sq_exerciser->IsWellFormedBrackets(bracket_str) << std::endl;
    bracket_str.assign("[()[]{()()}]");
    std::cout << "main::IsWellFormedBrackets(" << bracket_str << ") = "
              << std::boolalpha << sq_exerciser->IsWellFormedBrackets(bracket_str) << std::endl;
    bracket_str.assign("{)}");
    std::cout << "main::IsWellFormedBrackets(" << bracket_str << ") = "
              << std::boolalpha << sq_exerciser->IsWellFormedBrackets(bracket_str) << std::endl;
    bracket_str.assign("[()[]{()()");
    std::cout << "main::IsWellFormedBrackets(" << bracket_str << ") = "
              << std::boolalpha << sq_exerciser->IsWellFormedBrackets(bracket_str) << std::endl;
}

void EvaluateRPN(StackQueueExercises* sq_exerciser) {
    std::cout << "\n--->>--->> main::EvaluateRPN <<---<<--- " << std::endl;
    std::string expression("3,4,+,2,*,1,+");
    std::cout << "main::EvaluateRPN(" << expression << ") = "
              << sq_exerciser->EvaluateRPN(expression) << std::endl;
}

void RunTests(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    TestMaxElement(sq_exerciser);
    EvaluateRPN(sq_exerciser);
    IsWellFormedBrackets(sq_exerciser);
    BinaryTreeLevelOrder(sq_exerciser);
    TestCircularQueue(sq_exerciser);
    TestQueueStacks(sq_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch9_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<StackQueueExercises> sq_exerciser(new StackQueueExercises());
    RunTests(sq_exerciser.get());
    return 0;
}
