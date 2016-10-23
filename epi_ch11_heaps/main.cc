#include <cassert> //NOLINT
#include <iostream>
#include "includes/chap_eleven.h"
using namespace std; //NOLINT

void OnlineMedian(HeapExercises* heap_exerciser) {
    std::cout << "\n--->>--->> main::OnlineMedian <<---<<--- " << std::endl;
    std::vector<int> sequence{1, 0, 3, 5, 2, 0, 1};
    std::stringstream int_stream;
    for (int x : sequence) {
      int_stream << x << ' ';
    }
    istringstream int_sequence(int_stream.str());
    std::vector<double> result = heap_exerciser->OnlineMedian(&int_sequence);
    std::cout << "\n[  ";
    for (auto &v : result) {
      std::cout << v << "  ";
    }std::cout << "]" <<std::endl;
}

void ComputeClosestStars(HeapExercises* heap_exerciser) {
    std::cout << "\n--->>--->> main::ComputeClosestStars <<---<<--- " << std::endl;
    std::vector<int> starmap{5, 30, 900, 1000, 300, 50};
    int k = 2;
    std::stringstream starss;
    for (int x : starmap) {
      starss << x << ' ';
    }
    istringstream star_sequence(starss.str());
    std::vector<int> result = heap_exerciser->ComputeClosestStars(&star_sequence, k);
    std::cout << "\n[ ";
    for (auto &v : result) {
      std::cout << v << " ";
    }std::cout << "]" <<std::endl;
}

void SortKSortedList(HeapExercises* heap_exerciser) {
    std::cout << "\n--->>--->> main::SortKSortedList <<---<<--- " << std::endl;
    std::vector<int> int_list {3,-1,2,6,4,5,8};
    int k = 2;
    std::stringstream ss;
    for (int x : int_list) {
      ss << x << ' ';
    }
    istringstream sequence(ss.str());
    std::vector<int> result = heap_exerciser->SortKSortedList(&sequence, k);
    std::cout << "\n[ ";
    for (auto &v : result) {
      std::cout << v << " ";
    }std::cout << "]" <<std::endl;
}

void RunTests(HeapExercises* heap_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    SortKSortedList(heap_exerciser);
    ComputeClosestStars(heap_exerciser);
    OnlineMedian(heap_exerciser);
    // BinaryTreeLevelOrder(heap_exerciser);
    // TestCircularQueue(heap_exerciser);
    // TestQueueStacks(heap_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch11_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HeapExercises> heap_exerciser(new HeapExercises());
    RunTests(heap_exerciser.get());
    return 0;
}
