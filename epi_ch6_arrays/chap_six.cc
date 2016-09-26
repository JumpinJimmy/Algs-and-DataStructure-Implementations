#include "includes/chap_six.h"
ArrayExercises::ArrayExercises() {
    std::cout << "--->>--->> chap_six::ArrayExercises construct " << std::endl;
}

ArrayExercises::~ArrayExercises() {
    std::cout << "--->>--->> chap_six::ArrayExercises destruct " << std::endl;
}

void ArrayExercises::SwapEvenOdd(std::vector<int>* int_list) {
    std::cout << "--->>--->> chap_six:: SwapEvenOdd" << std::endl;
    std::vector<int> &list = *int_list;
    int even_ptr = 0;
    int odd_ptr = list.size() - 1;
    while(even_ptr < odd_ptr) {
        if (list[even_ptr] % 2 == 0) {
            even_ptr++;
        } else {
            std::swap(list[even_ptr], list[odd_ptr--]);
        }
    }
}

    // Example: 84 == 1010100; Parity is 1. Number of 1's = 3 (odd)
    // Example: 85 == 1010101; Parity is 0. Number of 1's = 4 (even)

