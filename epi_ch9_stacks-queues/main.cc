#include "includes/chap_nine.h"
#include <cassert> //NOLINT
using namespace std; //NOLINT

void TestMaxElement(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::TestMaxElement <<---<<--- " << std::endl;
    std::vector<int> v {1, 2, 3, 4};
    sq_exerciser->TestMaxStack(v);
}

void RunTests(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    TestMaxElement(sq_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch8_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<StackQueueExercises> sq_exerciser(new StackQueueExercises());
    RunTests(sq_exerciser.get());
    return 0;
}
