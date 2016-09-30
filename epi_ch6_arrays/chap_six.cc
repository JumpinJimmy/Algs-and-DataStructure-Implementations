#include "includes/chap_six.h"
ArrayExercises::ArrayExercises() {
    std::cout << "--->>--->> chap_six::ArrayExercises construct " << std::endl;
}

ArrayExercises::~ArrayExercises() {
    std::cout << "--->>--->> chap_six::ArrayExercises destruct " << std::endl;
}

void ArrayExercises::print_list(std::vector<int> &v) {

    std::cout << "c6Printing List: \n [ ";
    for(auto &val : v){
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
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

std::vector<int> ArrayExercises::IncrementDecimal(std::vector<int> input_decimal){
    std::cout << "--->>--->> chap_six::IncrementDecimal( input[ ";
    for(auto &val : input_decimal){
        std::cout << val << " ";
    }
    std::cout << "]);" << std::endl;
    ////////////////////////////////////////////
    ++input_decimal.back();
    for (int i = input_decimal.size() - 1; i > 0 && input_decimal[i] == 10; --i) {
        input_decimal[i] = 0;
        input_decimal[i-1] = input_decimal[i-1] + 1;
    }

    if (input_decimal[0] == 10) {
        input_decimal[0] = 0;
        input_decimal.insert(input_decimal.begin(), 1);
    }
    return input_decimal;
}

int ArrayExercises::RemDups(std::vector<int> *arr_ptr) {
    if (arr_ptr->empty()) {
        std::cout << "--->>--->> chap_six::RemDups ERROR arr_ptr is empty() "  << std::endl;
        return 0;
    } else if (!(std::is_sorted(arr_ptr->begin(),arr_ptr->end()))) {
        std::cout << "--->>--->> chap_six::RemDups ERROR arr_ptr is not sorted "  << std::endl;
        return 0;
    }
    std::vector<int> result_vec;
    result_vec.reserve(arr_ptr->size());
    for (auto value : *arr_ptr) {
        if (std::find(result_vec.begin(), result_vec.end(), value) == result_vec.end())
            result_vec.push_back(value);
    }
    return result_vec.size();
}

int ArrayExercises::RemDupsInplace(std::vector<int> *arr_ptr) {
    if (arr_ptr->empty()) {
        std::cout << "--->>--->> chap_six::RemDupsInplace ERROR arr_ptr is empty() "  << std::endl;
        return 0;
    } else if (!(std::is_sorted(arr_ptr->begin(),arr_ptr->end()))) {
        std::cout << "--->>--->> chap_six::RemDupsInplace ERROR arr_ptr is not sorted "  << std::endl;
        return 0;
    }

    std::vector<int> &array = *arr_ptr;
    print_list(array);
    int vacant_index = 1;
    for (int i = 1; i < array.size(); i++) {
        if (array[vacant_index - 1] != array[i]) {
            array[vacant_index++] = array[i];
        }
    }
    print_list(*arr_ptr);
    return vacant_index;
}
    // Example: 84 == 1010100; Parity is 1. Number of 1's = 3 (odd)
    // Example: 85 == 1010101; Parity is 0. Number of 1's = 4 (even)

