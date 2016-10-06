#include "includes/chap_eight.h"
using namespace std; //NOLINT

void ReverseSubList(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main::ReverseSubList <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> list = llist_exerciser->CreateIntLinkedList(5);
    int start_pos = 2;
    int end_pos = 4;
    shared_ptr<ListNode<int>> reversed = llist_exerciser->ReverseSubList(list, start_pos, end_pos);
}

void MergeSortedLists(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main::MergeSortedLists <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> L1 = llist_exerciser->CreateIntLinkedList(5);
    shared_ptr<ListNode<int>> L2 = llist_exerciser->CreateIntLinkedList(5);
    shared_ptr<ListNode<int>> merged_list = llist_exerciser->MergeTwoSortedLists(L1, L2);
    llist_exerciser->Print(merged_list);
}

void RunTests(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    MergeSortedLists(llist_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch8_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<LinkedListExercises> llist_exerciser(new LinkedListExercises());
    RunTests(llist_exerciser.get());
    return 0;
}
