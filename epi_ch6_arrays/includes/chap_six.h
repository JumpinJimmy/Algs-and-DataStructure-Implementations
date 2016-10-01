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
#include <numeric>

class ArrayExercises {
    public:
        ArrayExercises();
        virtual ~ArrayExercises();
        void SwapEvenOdd(std::vector<int>* int_list);
        std::vector<int> IncrementDecimal(std::vector<int> input_decimal);
        int RemDups(std::vector<int> *arr_ptr);
        int RemDupsInplace(std::vector<int> *arr_ptr);
        double MaxProfitSingleStock(std::vector<double> &prices);
        int LongestSubArrayEqual(std::vector<int> &int_list);
        std::vector<int> EnumeratePrimes(int n);

    private:
        void print_list(std::vector<int> &v);
        void print_list(std::vector<double> &v);
        //
};


#endif // CHAP_SIX_H
