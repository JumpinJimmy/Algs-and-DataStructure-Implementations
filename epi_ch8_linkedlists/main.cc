#include "includes/chap_eight.h"
#include <cassert> //NOLINT
using namespace std; //NOLINT

void HasCycle(LinkedListExercises* llist_exerciser) {
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

    llist_exerciser->PrintInline(list_head);
    assert(llist_exerciser->HasCycle(list_head) == nullptr);
    std::cout << "list_head " << (llist_exerciser->HasCycle(list_head) ? "has" : "does not have")
              << " cycle." << std::endl;

    /// Make a Cycle (this causes shared_pointers to behave poorly)
    first->next = second;
    std::cout << "first(data= " << first->data << ").use_count() == " << first.use_count() << '\n';
    std::cout << "main:: first->next = " << (first->next ? std::to_string(first->next->data) : "nullptr") << std::endl;
    assert(llist_exerciser->HasCycle(list_head) != nullptr);
    assert(llist_exerciser->HasCycle(list_head)->data == second->data);
    auto temp = llist_exerciser->HasCycle(list_head);
    if (temp) {
        std::cout << "list_head has cycle, located at node value: " << temp->data << std::endl;
    } else {
        std::cout << "list_head does not have cycle" << std::endl;
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
    llist_exerciser->Print(list);
    int start_pos = 0;
    int end_pos = 2;
    shared_ptr<ListNode<int>> reversed = llist_exerciser->ReverseSubList(start_pos, end_pos, list);
    llist_exerciser->Print(reversed);
    // TODO(jdevore): write basic test cases
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
    // MergeSortedLists(llist_exerciser);
    // ReverseSubList(llist_exerciser);
    HasCycle(llist_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch8_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<LinkedListExercises> llist_exerciser(new LinkedListExercises());
    RunTests(llist_exerciser.get());
    return 0;
}
