#include "includes/chap_six.h"
using namespace std; //NOLINT

void print_list(std::vector<int> &v) {

    std::cout << "Printing List: \n [ ";
    for(auto &val : v){
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
}
void run_tests(ArrayExercises *array_exerciser) {
    std::vector<int> int_list {3,5,4,2,9,7,4};


    for(auto &val : int_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    array_exerciser->SwapEvenOdd(&int_list);
    for(auto &val : int_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::vector<int> v = {1,2};
    std::vector<int> res = array_exerciser->IncrementDecimal(v);
    print_list(res);
    v = {1,9};
    res = array_exerciser->IncrementDecimal(v);
    print_list(res);
    v = {9,9};
    res = array_exerciser->IncrementDecimal(v);
    print_list(res);

}

int main(int argc, char const *argv[]) {
    std::shared_ptr<ArrayExercises> array_exerciser(new ArrayExercises());
    // ArrayExercises *array_exerciser = new ArrayExercises();
    run_tests(array_exerciser.get());
    return 0;
}