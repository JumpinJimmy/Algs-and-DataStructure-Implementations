#include <ios>
#include <iomanip>
#include <utility>
#include <stdlib.h>
#include "includes/chap_six.h"
using namespace std; //NOLINT

void run_tests() {
    std::vector<int> int_list {3,5,4,2,9,7,4};
    ArrayExercises *array_exerciser = new ArrayExercises();

    for(auto &val : int_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    array_exerciser->SwapEvenOdd(&int_list);
    for(auto &val : int_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    delete array_exerciser;
}

int main(int argc, char const *argv[]) {
    run_tests();
    return 0;
}