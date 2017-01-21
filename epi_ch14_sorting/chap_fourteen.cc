#include <algorithm>
#include "includes/chap_fourteen.h"

SortingExercises::SortingExercises() {}

SortingExercises::~SortingExercises() {}

std::vector<int> SortingExercises::ComputeListIntersection(const std::vector<int>& A1, const std::vector<int>& A2) {
    PrintCollection(A1, "ComputeIntersection List1: ");
    PrintCollection(A2, "ComputeIntersection List2: ");
    std::vector<int> result = {};
    int index = 0;
    for (auto &val : A1) {
        if (((index == 0) || (val != A1.at(index-1))) && (std::binary_search(A2.begin(), A2.end(), val))) {
            result.emplace_back(val);
        }
        ++index;
    }
    return result;
}

std::vector<int> SortingExercises::ComputeListIntersectionAlt(const std::vector<int>& A1, const std::vector<int>& A2) {
    PrintCollection(A1, "ComputeListIntersectionAlt List1: ");
    PrintCollection(A2, "ComputeListIntersectionAlt List2: ");
    std::vector<int> result = {};
    unsigned int list_ptr_one = 0;
    unsigned int list_ptr_two = 0;
    while (list_ptr_one < A1.size() && list_ptr_two < A2.size()) {
        if (A1.at(list_ptr_one) == A2.at(list_ptr_two) && (list_ptr_one == 0 || A1.at(list_ptr_one) != A1.at(list_ptr_one - 1))) {
            result.emplace_back(A1.at(list_ptr_one));
            ++list_ptr_two;
            ++list_ptr_one;
        } else if (A1.at(list_ptr_one) > A2.at(list_ptr_two)) {
            ++list_ptr_two;
        } else {
            ++list_ptr_one;
        }
    }
    return result;
}

void SortingExercises::MergeTwoSortedArrays(int A1[], int size_one, int A2[], int size_two) {
    int pos_one = size_one - 1;
    int pos_two = size_two - 1;
    int write_pos = size_one + size_two - 1;

    while (pos_one >= 0 && pos_two >= 0) {
        A1[write_pos--] = A1[pos_one] > A2[pos_two] ? A1[pos_one--] : A2[pos_two--];
    }
    while (pos_two >= 0) {
       A1[write_pos--] = A2[pos_two--];
    }
}

int SortingExercises::FindMaxSimultaneousEvents(std::vector<Event> event_list) {
    // EventPoint (single time point and boolean indicating is a start time)
    std::vector<EventPoint> sorted_times;
    for (const Event &e : event_list) {
        sorted_times.emplace_back(EventPoint{e.start, true});
        sorted_times.emplace_back(EventPoint{e.finish, false});
    }
    // Sort all individual time points for each event into a single collection
    // -uses EventPoint's operator< definiion
    std::sort(sorted_times.begin(), sorted_times.end());
    int highest_simultaneous = 0;
    int current_simultaneous = 0;
    for (const EventPoint &ep : sorted_times) {
        if (ep.event_start) {
            ++current_simultaneous;
            highest_simultaneous = std::max(highest_simultaneous, current_simultaneous);
        } else {
            --current_simultaneous;
        }
    }

    return highest_simultaneous;
}

// TODO(jdevore): clean up if statements and find generic way to approach
std::vector<Interval> SortingExercises::ComputeIntervalUnions(std::vector<Interval> intervals) {
    if (intervals.empty()) return {};

    // Sort intervals by their left endpoint
    std::sort(intervals.begin(), intervals.end());
    std::vector<Interval> union_results;
    Interval current(intervals.front());
    // for each interval @int in @intervals:
    // if (int.left < curr.right) OR (int.left == curr.right && either is closed) {
    //     if (int.right > curr.right) OR (int.right == curr.right && int.right is closed) {
    //          curr.right = int.right
    //     }
    // } else {  // end of current dijoint interval
    //        union_results.emplace_back(curr)
    //        curr = int
    // }
    for (unsigned int i = 1; i < intervals.size(); ++i) {
        if (intervals.at(i).leftp.val < current.rightp.val || (intervals.at(i).leftp.val == current.rightp.val && (current.rightp.closed || intervals.at(i).leftp.closed))) { // NOLINT
            if (intervals.at(i).rightp.val > current.rightp.val || (intervals.at(i).rightp.val == current.rightp.val && intervals.at(i).rightp.closed)) { // NOLINT
                current.rightp = intervals.at(i).rightp;
            }
        } else {
            union_results.emplace_back(current);
            current = intervals.at(i);
        }
    }
    union_results.emplace_back(current);
    return union_results;
}
