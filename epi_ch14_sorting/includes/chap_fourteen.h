#ifndef CHAP_FOURTEEN_H
#define CHAP_FOURTEEN_H
#include <vector>
#include <string>
#include <iostream>

struct Event {
  int start, finish;
};

class SortingExercises {
 public:
    SortingExercises();
    ~SortingExercises();
    std::vector<int> ComputeListIntersection(const std::vector<int>& A1, const std::vector<int>& A2);
    std::vector<int> ComputeListIntersectionAlt(const std::vector<int>& A1, const std::vector<int>& A2);
    void MergeTwoSortedArrays(int A1[], int size_one, int A2[], int size_two);
    int FindMaxSimultaneousEvents(std::vector<Event> event_list);
    template <typename T>
    void PrintCollection(const std::vector<T> &v, const std::string &extra_detail = "list: ") {
        std::cout << extra_detail << " size: " << std::dec << v.size() << "\n [ ";
        for (auto &val : v) {
            std::cout << val << " ";
        }
        std::cout << "];" << std::endl;
    }
};

#endif  // CHAP_FOURTEEN_H
