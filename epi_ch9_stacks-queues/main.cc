#include "includes/chap_nine.h"
#include <cassert> //NOLINT
using namespace std; //NOLINT

void test(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::test <<---<<--- " << std::endl;
    // shared_ptr<ListNode<int>> L1 = sq_exerciser->CreateIntLinkedList(5);
    // sq_exerciser->PrintInline("\ttest List 1: ", L1);
    // shared_ptr<ListNode<int>> L2 = sq_exerciser->CreateIntLinkedList(5);
    // sq_exerciser->PrintInline("\ttest List 2: ", L2);
    // shared_ptr<ListNode<int>> merged_list = sq_exerciser->MergeTwoSortedLists(L1, L2);
    // std::cout << "\ttest Merge Result: ";
    // sq_exerciser->PrintInline(merged_list);
}

void RunTests(StackQueueExercises* sq_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    test(sq_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch8_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<StackQueueExercises> sq_exerciser(new StackQueueExercises());
    RunTests(sq_exerciser.get());
    return 0;
}
