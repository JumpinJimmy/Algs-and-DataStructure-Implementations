#include "includes/chap_eight.h"
LinkedListExercises::LinkedListExercises() {}

LinkedListExercises::~LinkedListExercises() {}

shared_ptr<ListNode<int>> LinkedListExercises::MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                                                   shared_ptr<ListNode<int>> L2) {
    shared_ptr<ListNode<int>> result_head(new ListNode<int>);
    auto tail_node = result_head;
    while (L1 && L2) {
        if (L1->data <= L2->data) {
            AppendSingleNode(&L1, &tail_node);
        } else {
            AppendSingleNode(&L2, &tail_node);
        }
    }
    tail_node->next = L1 ? L1 : L2;
    return result_head->next;
}

shared_ptr<ListNode<int>> LinkedListExercises::ReverseSubList(int start, int finish,
                                                              shared_ptr<ListNode<int>> orig_list) {
    std::cout << "\t -->ReverseSubList(original_list, int start = \""
              << start << "\", int finish = \"" << finish << "\")" << std::endl;

    if (start >= finish) {
        return orig_list;
    }
    // shared_ptr<ListNode<int>> pseudo_head(new ListNode<int>(0,orig_list));
    auto pseudo_head = std::make_shared<ListNode<int>>(ListNode<int> {0, orig_list});
    auto sublist_header = pseudo_head;
    int k = 1;
    while (k++ < start) {
        sublist_header = sublist_header->next;
    }

    auto sublist_iter = sublist_header->next;
    while (start++ < finish) {
        auto temp = sublist_iter->next;
        sublist_iter->next = temp->next;
        temp->next = sublist_header->next;
        sublist_header->next = temp;
    }
    return pseudo_head->next;
}

shared_ptr<ListNode<int>> LinkedListExercises::HasCycle(const shared_ptr<ListNode<int>>& head) {
    // Search the list for a cycle
    // If Cycle exists, return the first node of the cycle
    // If No Cycle exists, return null
    if (!head || (head && !head->next)) {
        return nullptr;
    }

    auto slow_iter = head;
    auto fast_iter = head;
    while (fast_iter && fast_iter->next) {
        slow_iter = slow_iter->next;
        fast_iter = fast_iter->next->next;
        if (slow_iter == fast_iter) {
            // we have a cycle
            int length_of_cycle = 0;

            do {
               ++length_of_cycle;
               fast_iter = fast_iter->next;
            } while (slow_iter != fast_iter);

            auto cycle_iter = head;
            while (length_of_cycle--) {
                cycle_iter = cycle_iter->next;
            }
            auto head_result = head;
            while (head_result != cycle_iter) {
                head_result = head_result->next;
                cycle_iter = cycle_iter->next;
            }
            return head_result;
        }
    }

    return nullptr;
}

shared_ptr<ListNode<int>> LinkedListExercises::CheckOverlap(shared_ptr<ListNode<int>> list_a,
                                                            shared_ptr<ListNode<int>> list_b) {
    /// if list_a == list_b then return true
    /// if list_a's last node == list_b's last node return true
    /// if list_b's last node == list_a
    /// If same length, iterate to last node and check equality
    /// If Differing Length:
    ///     set iterate longest list ptr diff(longestlength - shortest length) times;
    ///     then iterate both until end, checking for equality
    if (list_a == list_b) {
        return list_a;
    }

    int a_length = 0;
    int b_length = 0;

    auto list_iter = list_a;
    while (list_iter) {
        ++a_length;
        list_iter = list_iter->next;
    }

    auto list_iter2= list_b;
    while (list_iter2) {
        ++b_length;
        list_iter2 = list_iter2->next;
    }

    std::cout << "list_a(data= " << list_a->data << ").use_count() == " << list_a.use_count();
    std::cout << "\nlist_a->next = "
              << (list_a->next ? std::to_string(list_a->next->data) : "nullptr") << std::endl;
    std::cout << "list_b(data=" << list_b->data << ").use_count() == " << list_b.use_count();
    std::cout << "\nlist_b->next = "
              << (list_b->next ? std::to_string(list_b->next->data) : "nullptr") << std::endl;
    std::cout << "a_length: " << a_length <<", b_length: " << b_length << std::endl;
    AdvanceListNodeK(abs(a_length - b_length), a_length > b_length ? &list_a : &list_b);

    while (list_a && list_b && list_a != list_b) {
        list_a = list_a->next;
        list_b = list_b->next;
    }
    return list_a;
}

/// TODO(jdevore): Create another method to build list w/ custom data field vs. 0 - N
shared_ptr<ListNode<int>> LinkedListExercises::CreateIntLinkedList(int n) {
    shared_ptr<ListNode<int>> head = nullptr;
    for (int i = n - 1; i >= 0; --i) {
        auto curr = std::make_shared<ListNode<int>>(ListNode<int> {i, nullptr});
        curr->next = head;
        head = curr;
    }
    return head;
}

/// MergeTwoSortedLists Helper Method
void LinkedListExercises::AppendSingleNode(shared_ptr<ListNode<int>> *candidate_node,
                                           shared_ptr<ListNode<int>> *tail_node) {
    (*tail_node)->next = *candidate_node;
    *tail_node = *candidate_node;
    *candidate_node = (*candidate_node)->next;
}

void LinkedListExercises::AdvanceListNodeK(int k, shared_ptr<ListNode<int>> *ListNode) {
    while (k--) {
        *ListNode = (*ListNode)->next;
    }
}
