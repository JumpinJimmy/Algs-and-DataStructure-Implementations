#include "includes/chap_nine.h"
#include <cassert> //NOLINT
using namespace std; //NOLINT

void TestMaxElement(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::TestMaxElement <<---<<--- " << std::endl;
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

void IsWellFormedBrackets(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::IsWellFormedBrackets <<---<<--- " << std::endl;
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
    std::cout << "--->>--->> main::EvaluateRPN <<---<<--- " << std::endl;
    std::string expression("3,4,+,2,x,1,+");
    std::cout << "main::EvaluateRPN(" << expression << ") = "
              << sq_exerciser->EvaluateRPN(expression) << std::endl;
}

void RunTests(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    TestMaxElement(sq_exerciser);
    IsWellFormedBrackets(sq_exerciser);
    EvaluateRPN(sq_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch9_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<StackQueueExercises> sq_exerciser(new StackQueueExercises());
    RunTests(sq_exerciser.get());
    return 0;
}
