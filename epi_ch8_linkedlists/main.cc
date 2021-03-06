#include "includes/chap_eight.h"
#include <cassert> //NOLINT
using namespace std; //NOLINT

void EvenOddMerge(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main:EvenOddMerge <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> list = llist_exerciser->CreateIntLinkedList(5);
    llist_exerciser->PrintInline("\tOriginal List EvenOdd Merge:", list);
    shared_ptr<ListNode<int>> result = llist_exerciser->EvenOddMerge(list);
    llist_exerciser->PrintInline("\tEvenOdd Merge Result: ", result);
}

void RemoveKthLast(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main:RemoveKthLast <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> list = llist_exerciser->CreateIntLinkedList(5);
    int k = 3;
    llist_exerciser->PrintInline("\tOriginal List Pre Removal:", list);
    shared_ptr<ListNode<int>> result = llist_exerciser->RemoveKthLast(list, k);
    assert(result != nullptr);
    llist_exerciser->PrintInline("\tRemoveKthLast Result: ", result);
    k = 6;
    result = llist_exerciser->RemoveKthLast(list, k);
    assert(result == nullptr);
}

void CheckOverlap(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main:CheckOverlap <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> L1, L2;
    L1 = make_shared<ListNode<int>>(ListNode<int> {
        1, make_shared<ListNode<int>>(ListNode<int> {
            2, make_shared<ListNode<int>>(ListNode<int> {3, nullptr})})});

    L2 = L1->next->next;
    llist_exerciser->PrintInline("\tCheckOverlap L1: ", L1);
    llist_exerciser->PrintInline("\tCheckOverlap L2: ", L2);
    shared_ptr<ListNode<int>> result = llist_exerciser->CheckOverlap(L1, L2);
    assert(result != nullptr);
    llist_exerciser->PrintInline("\t Checkoverlap Result: ", result);
}

void HasCycle(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main:HasCycle <<---<<--- " << std::endl;
    /// Create Basic List
    shared_ptr<ListNode<int>> list_head = nullptr;
    auto first = std::make_shared<ListNode<int>>(ListNode<int> {1, nullptr});
    first->next = list_head;
    list_head = first;
    auto second = std::make_shared<ListNode<int>>(ListNode<int> {2, nullptr});
    second->next = list_head;
    list_head = second;
    auto third = std::make_shared<ListNode<int>>(ListNode<int> {3, nullptr});
    third->next = list_head;
    list_head = third;

    llist_exerciser->PrintInline("\tHasCycle original list: ", list_head);
    assert(llist_exerciser->HasCycle(list_head) == nullptr);
    std::cout << "\t list_head " << (llist_exerciser->HasCycle(list_head) ? "has" : "does not have")
              << " cycle." << std::endl;

    /// Make a Cycle (this causes shared_pointers to behave poorly)
    first->next = second;
    std::cout << "\t first(data= " << first->data
              << ").use_count() == " << first.use_count() << '\n';
    std::cout << "\t main:: first->next = "
              << (first->next ? std::to_string(first->next->data) : "nullptr") << std::endl;

    assert(llist_exerciser->HasCycle(list_head) != nullptr);
    assert(llist_exerciser->HasCycle(list_head)->data == second->data);
    auto temp = llist_exerciser->HasCycle(list_head);
    if (temp) {
        std::cout << "\t list_head has cycle, located at node value: " << temp->data << std::endl;
    } else {
        std::cout << "\t list_head does not have cycle" << std::endl;
    }

    /// Ugly but necessary cleanup of cyclic shared pointers
    first->next = nullptr;
    list_head->next = nullptr;
    second->next = nullptr;
    third->next = nullptr;
    list_head.reset(new ListNode<int>);
    first.reset(new ListNode<int>);
    second.reset(new ListNode<int>);
    third.reset(new ListNode<int>);
}

void ReverseSubList(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main::ReverseSubList <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> list = llist_exerciser->CreateIntLinkedList(5);
    llist_exerciser->PrintInline("\tReverseSubList List Pre Reverse: ", list);
    int start_pos = 0;
    int end_pos = 2;
    shared_ptr<ListNode<int>> reversed = llist_exerciser->ReverseSubList(start_pos, end_pos, list);
    llist_exerciser->PrintInline("\tReverseSubList Result: ", reversed);
    // TODO(jdevore): write basic test cases
}

void MergeSortedLists(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main::MergeSortedLists <<---<<--- " << std::endl;
    shared_ptr<ListNode<int>> L1 = llist_exerciser->CreateIntLinkedList(5);
    llist_exerciser->PrintInline("\tMergeSortedLists List 1: ", L1);
    shared_ptr<ListNode<int>> L2 = llist_exerciser->CreateIntLinkedList(5);
    llist_exerciser->PrintInline("\tMergeSortedLists List 2: ", L2);
    shared_ptr<ListNode<int>> merged_list = llist_exerciser->MergeTwoSortedLists(L1, L2);
    std::cout << "\tMergeSortedLists Merge Result: ";
    llist_exerciser->PrintInline(merged_list);
}

void RunTests(LinkedListExercises* llist_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    MergeSortedLists(llist_exerciser);
    ReverseSubList(llist_exerciser);
    HasCycle(llist_exerciser);
    CheckOverlap(llist_exerciser);
    RemoveKthLast(llist_exerciser);
    EvenOddMerge(llist_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch8_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<LinkedListExercises> llist_exerciser(new LinkedListExercises());
    RunTests(llist_exerciser.get());
    return 0;
}
