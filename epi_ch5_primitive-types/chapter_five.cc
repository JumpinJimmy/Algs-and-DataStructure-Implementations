#include <iostream>
#include "includes/chapter_five.h"

PrimitiveTypesExerciser::PrimitiveTypesExerciser() {
    std::cout << "--->>--->> chapter_five::PrimitiveTypesExerciser construct " << std::endl;
}

PrimitiveTypesExerciser::~PrimitiveTypesExerciser() {
    std::cout << "--->>--->> chapter_five::PrimitiveTypesExerciser destruct " << std::endl;
}

int16_t PrimitiveTypesExerciser::Parity(uint64_t x) {
    // Example: 84 == 1010100; Parity is 1. Number of 1's = 3 (odd)
    // Example: 85 == 1010101; Parity is 0. Number of 1's = 4 (even)
    std::cout << "--->>--->> chapter_five:: Parity( " << x << " )" << std::endl;
    int16_t result = 0;
    while (x) {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}
