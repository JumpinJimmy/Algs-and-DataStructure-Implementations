#include <iostream>
#include <utility>
#include "includes/chapter_five.h"
using namespace std; //NOLINT

void run_tests() {
    unsigned long test_in = 84;
    PrimitiveTypesExerciser *ptypes = new PrimitiveTypesExerciser();
    short result_a = ptypes->Parity(test_in);
    short result_b = ptypes->Parity(++test_in);
    std::cout << "--->>--->>main::result_a: " << result_a << " result_b: " << result_b << std::endl;
    delete ptypes;
}

int main(int argc, char const *argv[]) {
    run_tests();
    return 0;
}
