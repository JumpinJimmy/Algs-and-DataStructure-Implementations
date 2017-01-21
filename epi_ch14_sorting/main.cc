#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include "includes/chap_fourteen.h"

// Exercise 14.1
void ComputeListIntersection(SortingExercises *sorting_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::ComputeListIntersection() " << std::endl;
    std::vector<int> list_one = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    std::vector<int> list_two = {5, 5, 6, 8, 8, 9, 10, 10};
    std::vector<int> intersection_result = sorting_exerciser->ComputeListIntersection(list_one, list_two);
    sorting_exerciser->PrintCollection(intersection_result, "Intersection Result: ");
    intersection_result = sorting_exerciser->ComputeListIntersectionAlt(list_one, list_two);
    sorting_exerciser->PrintCollection(intersection_result, "Alt Intersection Result: ");
}

// Exercise 14.2
void MergeTwoSortedArrays(SortingExercises *sorting_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::MergeTwoSortedArrays() " << std::endl;
    int size_one = 3;
    std::vector<int> B = {3, 7, 11, 19};
    std::vector<int> A(size_one + B.size());
    A[0] = 5;
    A[1] = 13;
    A[2] = 17;

    sorting_exerciser->PrintCollection(A, "A1 List MergeTwoArrays: ");
    sorting_exerciser->PrintCollection(B, "A2 List MergeTwoArrays: ");
    sorting_exerciser->MergeTwoSortedArrays(A.data(), size_one, B.data(), B.size());
    sorting_exerciser->PrintCollection(A, "A1 Result for MergeTwoArrays: ");

    // Verify result
    for (size_t i = 1; i < A.size(); ++i) {
        assert(A[i - 1] <= A[i]);
    }
}

// Exercise 14.4
void FindMaxOverlappingEvents(SortingExercises *sorting_exerciser) {
    std::cout << "--->>--->> ch14-Sorting::FindMaxOverlappingEvents() " << std::endl;
    std::vector<Event> A = {{1, 5}, {2, 7}, {4, 5}, {6, 10}, {8, 9},
                            {9, 17}, {11, 13}, {12, 15}, {14, 15}};
    int expected_answer = 3;

    int result = sorting_exerciser->FindMaxSimultaneousEvents(A);
    std::cout << "\t\\--->> ch14-Sorting::FindMaxSimultaneousEvents Result:" << result << std::endl;
    assert(result == expected_answer);
}

// Exercise 14.6
void ComputeIntervalUnions(SortingExercises *sorting_exerciser, int test_collection_size = 0) {
    std::cout << "--->>--->> ch14-Sorting::ComputeIntervalUnions() - Randomized Input" << std::endl;
    std::default_random_engine gen((std::random_device())());
    for (int times = 0; times < 10; ++times) {
        int n;
        if (test_collection_size == 0) {
            std::uniform_int_distribution<int> dis(1, 10000);
            n = dis(gen);
        } else {
            n = test_collection_size;
        }

        std::vector<Interval> interval_list;
        for (int i = 0; i < n; ++i) {
            Interval temp;
            std::uniform_int_distribution<int> zero_or_one(0, 1);
            std::uniform_int_distribution<int> dis1(0, 9999);
            temp.leftp.closed = zero_or_one(gen), temp.leftp.val = dis1(gen);
            std::uniform_int_distribution<int> dis2(temp.leftp.val + 1,
                                                    temp.leftp.val + 100);
            temp.rightp.closed = zero_or_one(gen), temp.rightp.val = dis2(gen);
            interval_list.emplace_back(temp);
        }
        // sorting_exerciser->PrintCollection(interval_list, "Intervals: ");
        std::vector<Interval> ret = sorting_exerciser->ComputeIntervalUnions(interval_list);
        // sorting_exerciser->PrintCollection(ret, "Interval Union Result: ");
        for (size_t i = 1; i < ret.size(); ++i) {
            assert(ret[i - 1].rightp.val < ret[i].leftp.val ||
                  (ret[i - 1].rightp.val == ret[i].leftp.val && !ret[i - 1].rightp.closed &&
                    !ret[i].leftp.closed));
        }
    }
}

// Exercise 14.9
void SortingAlgoLists(SortingExercises *sorting_exerciser, unsigned int list_size = 5, int tests = 5) {
    std::cout << "--->>--->> ch14-Sorting::SortingAlgoLists(listlength: "
              << list_size << ", test_count: " << tests << ")" << std::endl;
    std::default_random_engine gen((std::random_device())());
    for (int times = 0; times < tests; ++times) {
        std::shared_ptr<ListNode<int>> L = nullptr;
        std::uniform_int_distribution<int> dis(0, 99);

        for (unsigned int i = list_size; i > 0; --i) {
            std::shared_ptr<ListNode<int>> temp =
                std::make_shared<ListNode<int>>(ListNode<int>{dis(gen), nullptr});
            temp->next = L;
            L = temp;
        }
        sorting_exerciser->PrintList(L, "\t\\--->SortingAlgoLists() Original List: ");
        auto sorted_list = sorting_exerciser->StableSortList(L);
        sorting_exerciser->PrintList(sorted_list, "\t\\--->SortingAlgoLists() Resulting List: ");
        unsigned int node_counter = 0;
        int pre = std::numeric_limits<int>::min();
        while (sorted_list) {
            assert(pre <= sorted_list->data);
            pre = sorted_list->data;
            sorted_list = sorted_list->next;
            ++node_counter;
        }
        assert(node_counter == list_size);
    }
}

void run_tests(std::shared_ptr<SortingExercises> sorting_exerciser) {
    ComputeListIntersection(sorting_exerciser.get());
    MergeTwoSortedArrays(sorting_exerciser.get());
    FindMaxOverlappingEvents(sorting_exerciser.get());
    ComputeIntervalUnions(sorting_exerciser.get(), 20);
    SortingAlgoLists(sorting_exerciser.get(), 5, 3);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch14_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<SortingExercises> sorting_exerciser(new SortingExercises());
    run_tests(sorting_exerciser);
    return 0;
}
