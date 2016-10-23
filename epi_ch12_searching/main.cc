#include "includes/chap_twelve.h"
#include <cassert> //NOLINT
using namespace std; //NOLINT

// void MergeSortedLists(SearchExercises* search_exerciser) {
//     std::cout << "--->>--->> main::MergeSortedLists <<---<<--- " << std::endl;
//     shared_ptr<ListNode<int>> L1 = search_exerciser->CreateIntLinkedList(5);
//     search_exerciser->PrintInline("\tMergeSortedLists List 1: ", L1);
//     shared_ptr<ListNode<int>> L2 = search_exerciser->CreateIntLinkedList(5);
//     search_exerciser->PrintInline("\tMergeSortedLists List 2: ", L2);
//     shared_ptr<ListNode<int>> merged_list = search_exerciser->MergeTwoSortedLists(L1, L2);
//     std::cout << "\tMergeSortedLists Merge Result: ";
//     search_exerciser->PrintInline(merged_list);
// }

void RunTests(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    // MergeSortedLists(search_exerciser);
    // ReverseSubList(search_exerciser);
    // HasCycle(search_exerciser);
    // CheckOverlap(search_exerciser);
    // RemoveKthLast(search_exerciser);
    // EvenOddMerge(search_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch12_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<SearchExercises> search_exerciser(new SearchExercises());
    RunTests(search_exerciser.get());
    return 0;
}
