#ifndef CHAP_TWELVE_H
#define CHAP_TWELVE_H
#include <vector>
#include <random>
#include <functional>
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
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
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
                return list[new_pivot_idx];
            } else if (new_pivot_idx > k - 1) {
                right = new_pivot_idx - 1;
            } else {  // new_pivot_idx < k - 1.
                left = new_pivot_idx + 1;
            }
        }
        return -1; // not found
    }

    template <typename Compare>
    int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp,
                             std::vector<int>* list_ptr) {
        std::cout << "======= chap_twelve::PartitionAroundPivot"
                  <<"(left:" << left << ", right:" << right << ", pivotidx:" << pivot_idx << ")" << std::endl;
        std::vector<int>& list = *list_ptr;
        PrintListInline(list, "PartitionAroundPivot");
        int pivot_value = list[pivot_idx];
        std::cout << "======= PartitionAroundPivot pivot_value:" << pivot_value << std::endl;
        int new_pivot_idx = left;
        std::cout << "=======  std::swap(list[pivot: " << pivot_idx << "]=" << list.at(pivot_idx) << ", list[right: " << right << "]=" << list.at(right) << ")" << std::endl;
        std::swap(list[pivot_idx], list[right]);
        PrintListInline(list, "Post Swap");
        for (int i = left; i < right; ++i) {
            if (comp(list[i], pivot_value)) {
                std::cout << "=======  std::swap(list[i: " << i << "]=" << list.at(i) << ", list[new_pivot_idx: " << new_pivot_idx << "]=" << list.at(new_pivot_idx) << ")" << std::endl;
                std::swap(list[i], list[new_pivot_idx++]);
                PrintListInline(list, "Post Swap");
            }
        }
        std::cout << "=======  std::swap(list[right: " << right << "]=" << list.at(right) << ", list[new_pivot_idx: " << new_pivot_idx << "]=" << list.at(new_pivot_idx) << ")" << std::endl;
        PrintListInline(list, "Post For Loop");
        std::swap(list[right], list[new_pivot_idx]);
        PrintListInline(list, "Post Final Swap");
        return new_pivot_idx;
    }
};

#endif  // CHAP_TWELVE_H
