#ifndef CHAP_TWELVE_H
#define CHAP_TWELVE_H
#include <vector>
#include <random>
#include <string>
#include <utility>
#include <functional>
#include <fstream>
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// SearchExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class SearchExercises {
 public:
    SearchExercises();
    ~SearchExercises();
    int bsearch(int t, const std::vector<int> &A);
    ////////////////////////////////////////////////////////////////////////////////////
    /// SearchFirstOfK(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    int SearchFirstOfK(const std::vector<int> &A, int k);

    int SearchSmallest(const std::vector<int> &A);

    int IntegerSquareRoot(int k);

    int FindKthLargest(int k, std::vector<int> *list_ptr);

    int FindMissingElement8(std::ifstream* ifs);

    template <typename T>
    void PrintListInline(const std::vector<T> &list, std::string details = "") {
        if (!details.empty()) {
            std::cout << details << " ";
        }
        if (!list.empty()) {
            std::cout << " [ ";
            for (auto &val : list) {
                std::cout << val << " ";
            }
            std::cout << "];" << std::endl;
        }
    }

 private:
    template <typename Compare>
    int FindKth(int k, Compare comp, std::vector<int>* list_ptr) {
        std::vector<int>& list = *list_ptr;
        int left = 0;
        int right = list.size() - 1;
        std::default_random_engine gen((std::random_device())());
        while (left <= right) {
            // Generates a random integer in [left, right].
            int pivot_idx = std::uniform_int_distribution<int>{left, right}(gen);
            std::cout << "======= chap_twelve::FindKth PivotIdx " << pivot_idx << std::endl;
            int new_pivot_idx =
                PartitionAroundPivot(left, right, pivot_idx, comp, &list);
            if (new_pivot_idx == k - 1) {
                std::cout << "IF: new_pivot_idx(" << new_pivot_idx <<") == k("
                          << k << ") - 1; Return list[new_pivot_idx:" << new_pivot_idx
                          << "] = " << list.at(new_pivot_idx) << std::endl;
                return list[new_pivot_idx];
            } else if (new_pivot_idx > k - 1) {
                std::cout << "ELIF: new_pivot_idx(" << new_pivot_idx <<") > k("
                          << k << ") - 1; right(" << right << ") = new_pivot_idx - 1 ("
                          << new_pivot_idx - 1 << ");" << std::endl;
                right = new_pivot_idx - 1;
            } else {  // new_pivot_idx < k - 1.
                std::cout << "ELSE: new_pivot_idx(" << new_pivot_idx <<") < k("
                          << k << ") - 1; left(" << left << ") = new_pivot_idx + 1 ("
                          << new_pivot_idx + 1 << ");" << std::endl;
                left = new_pivot_idx + 1;
            }
        }
        std::cout << "--->>--->> chap_twelve:: FindKth not found " << std::endl;
        return -1;  // not found
    }

    template <typename Compare>
    int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp,
                             std::vector<int>* list_ptr) {
        std::cout << "\t======= chap_twelve::PartitionAroundPivot"
                  <<"(left:" << left << ", right:" << right << ", pivotidx:" << pivot_idx << ")" << std::endl;
        std::vector<int>& list = *list_ptr;
        int pivot_value = list[pivot_idx];
        std::cout << "\t======= PartitionAroundPivot pivot_value:" << pivot_value << std::endl;
        int new_pivot_idx = left;
        std::cout << "\t======= PartitionAroundPivot new_pivot_idx = left(" << left << ")" << std::endl;
        std::cout << "\t=======  std::swap(list[pivot: " << pivot_idx << "]=" << list.at(pivot_idx)
                  << ", list[right: " << right << "]=" << list.at(right) << ")" << std::endl;
        std::swap(list[pivot_idx], list[right]);

        PrintListInline(list, "\tPost Swap");
        for (int i = left; i < right; ++i) {
            std::cout << "\t=======for (int i(" << i << "); i < right(" << right << "); ++i)"  << std::endl;
            if (comp(list[i], pivot_value)) {
                std::cout << "\t     LOOP std::swap(list[i: " << i << "]=" << list.at(i)
                          << ", list[new_pivot_idx: " << new_pivot_idx << "]=" << list.at(new_pivot_idx) << ")" << std::endl;

                std::swap(list[i], list[new_pivot_idx++]);
                PrintListInline(list, "\t    LOOP Post Swap");
            }
        }
        PrintListInline(list, "\tPost For Loop");
        std::cout << "\t=======  std::swap(list[right: " << right << "]=" << list.at(right)
                  << ", list[new_pivot_idx: " << new_pivot_idx << "]=" << list.at(new_pivot_idx) << ")" << std::endl;

        std::swap(list[right], list[new_pivot_idx]);
        PrintListInline(list, "\tPost Final Swap");
        std::cout << "\tReturn new_pivot_idx: " << new_pivot_idx << std::endl;
        return new_pivot_idx;
    }
};

#endif  // CHAP_TWELVE_H
