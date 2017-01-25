#ifndef CHAP_SIXTEEN_H
#define CHAP_SIXTEEN_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "../../epi_ch8_linkedlists/includes/linked_list_prototype.h"

class SortingExercises {
 public:
    SortingExercises();
    ~SortingExercises();
    std::vector<int> ComputeListIntersection(const std::vector<int>& A1, const std::vector<int>& A2);
    std::vector<int> ComputeListIntersectionAlt(const std::vector<int>& A1, const std::vector<int>& A2);
    void MergeTwoSortedArrays(int A1[], int size_one, int A2[], int size_two);
    int FindMaxSimultaneousEvents(std::vector<Event> event_list);
    std::vector<Interval> ComputeIntervalUnions(std::vector<Interval> intervals);
    std::shared_ptr<ListNode<int>> StableSortList(std::shared_ptr<ListNode<int>> L);

    // Helper Print / Output Functions
    template <typename T>
    void PrintCollection(const std::vector<T> &v, const std::string &extra_detail = "list: ") {
        std::cout << extra_detail << " size: " << std::dec << v.size() << "\n [ ";
        for (auto &val : v) {
            std::cout << val << " ";
        }
        std::cout << "];" << std::endl;
    }

    template <typename T>
    void PrintList(std::shared_ptr<ListNode<T>> head, const std::string &extra_detail = "") {
      if (!extra_detail.empty()) {
        std::cout << extra_detail << " ";
      }
      if (head) {
        std::cout << "(" << head->data << ")";
        if (head->next) {
          std::cout << " -> ";
        } else {
            std::cout << std::endl;
        }
        PrintList(head->next);
      }
    }

 private:
    // Helper for @StableSortList()
    std::shared_ptr<ListNode<int>> MergeTwoSortedLists(std::shared_ptr<ListNode<int>> L1,
                                                       std::shared_ptr<ListNode<int>> L2);
    // Helper for @MergeTwoSortedLists()
    void AppendSingleNode(std::shared_ptr<ListNode<int>> *candidate_node,
                          std::shared_ptr<ListNode<int>> *tail_node);
};

#endif  // CHAP_SIXTEEN_H
