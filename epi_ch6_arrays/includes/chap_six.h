#ifndef CHAP_SIX_H
#define CHAP_SIX_H
#include <iostream>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <memory>
class ArrayExercises{

    public:
        ArrayExercises();
        virtual ~ArrayExercises();
        void SwapEvenOdd(std::vector<int>* int_list);
        std::vector<int> IncrementDecimal(std::vector<int> input_decimal);
};


#endif // CHAP_SIX_H