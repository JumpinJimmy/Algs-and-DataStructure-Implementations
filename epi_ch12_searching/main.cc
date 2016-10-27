#include <iostream>
#include <numeric>
#include <vector>
#include <memory>
#include <fstream>
#include <cassert> //NOLINT
#include "includes/chap_twelve.h"
using namespace std; //NOLINT

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

void FindMissingElement8(SearchExercises* search_exerciser) {
    std::vector<int> A(256);
    std::iota(A.begin(), A.end(), 0);
    std::ofstream ofs("testmissing.txt");
    for (int i = 0; i < A.size(); ++i) {
            ofs << A[i] << endl;
    }
    // PrintListInline(A, "FindMissingElement8Pre:");
    A.clear();
    ofs.close();
    std::ifstream ifs("testmissing.txt");
    int result = search_exerciser->FindMissingElement8(&ifs);
    std::cout << "======= main:: FindMissingElement8 Result: " << result << std::endl;
    remove("testmissing.txt");
}

void FindKthLargest(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::FindKthLargest <<---<<--- " << std::endl;
    std::vector<int> int_list {2, 1, 3, 0};
    int k = 2;
    PrintListInline(int_list, "FindKthLargest:");
    int result_index = search_exerciser->FindKthLargest(k, &int_list);
    std::cout << "\t FindKthLargest(" << k << ") Result: " << result_index << std::endl;
}

void IntegerSquareRoot(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::IntegerSquareRoot <<---<<--- " << std::endl;
    int k = 16;
    int sqroot_result = search_exerciser->IntegerSquareRoot(k);
    std::cout << "\t IntegerSquareRoot(" << k << ") Result: " << sqroot_result << std::endl;
}

void SearchSmallest(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::SearchSmallest <<---<<--- " << std::endl;
    std::vector<int> int_list {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    PrintListInline(int_list, "Search Smallest Array:");
    int result_index = search_exerciser->SearchSmallest(int_list);
    std::cout << "\t SearchSmallest Index Result: " << result_index
              << ". Which is value array[" << result_index << "] = "
              << int_list.at(result_index) << std::endl;
}

void SearchFirstOfK(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::SearchFirstOfK <<---<<--- " << std::endl;
    std::vector<int> int_list {-14, -10, 2, 108, 108, 243, 285, 285, 401};
    PrintListInline(int_list, "SearchFirstOfK Array:");
    int k = 108;
    int result_index = search_exerciser->SearchFirstOfK(int_list, k);
    std::cout << "\t SearchFirstOfK Index Result: " << result_index << std::endl;
}

void RunTests(SearchExercises* search_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    SearchFirstOfK(search_exerciser);
    SearchSmallest(search_exerciser);
    IntegerSquareRoot(search_exerciser);
    FindKthLargest(search_exerciser);
    FindMissingElement8(search_exerciser);
    // EvenOddMerge(search_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch12_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<SearchExercises> search_exerciser(new SearchExercises());
    RunTests(search_exerciser.get());
    return 0;
}
