#include <iostream>
#include <utility>
#include "includes/chapter_five.h"
using namespace std; //NOLINT

void run_tests() {
    uint64_t test_in = 84;
    PrimitiveTypesExerciser *ptypes = new PrimitiveTypesExerciser();
    int16_t result_a = ptypes->Parity(test_in);
    int16_t result_b = ptypes->Parity(++test_in);
    std::cout << "--->>--->>main::result_a: " << result_a << " result_b: " << result_b << std::endl;
    delete ptypes;
}

int main(int argc, char const *argv[]) {
    run_tests();
    return 0;
}
