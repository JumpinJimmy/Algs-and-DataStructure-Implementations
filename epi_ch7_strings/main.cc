#include "includes/chap_seven.h"
#include <memory>
#include <utility>
using namespace std; //NOLINT

void ReplaceRemove(StringExercises* string_exerciser) {
    int init_size = 7;
    char arr[10] = {'a', 'c', 'd', 'b', 'b', 'c', 'a', '0', '0' ,'0'};
    std::cout << "\n Char Array pre ReplaceRemove: ";
    std::cout << "[ ";
    for (int j = 0; j < init_size; ++j) {
        std::cout << arr[j] << " ";
    }
    std::cout << "]" << std::endl;
    int res_size = string_exerciser->ReplaceAndRemove(arr, init_size);
    std::cout << "ReplaceAndRemove result size: " << res_size << std::endl;
}

void InterConversion(StringExercises* string_exerciser) {
    std::cout << "--->>--->> main::InterCoversion "  << std::endl;
    int starting_integer = -14;
    std::string res_str = string_exerciser->IntToString(starting_integer);
    std::cout << "IntToString(" << starting_integer << ") result: " << res_str << std::endl;
    int res_int = string_exerciser->StringToInt(res_str);
    std::cout << "StringToInt(" << res_str << ") result: " << res_int << std::endl;
}

void run_tests(StringExercises* string_exerciser) {
    // InterConversion(string_exerciser);
    ReplaceRemove(string_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch7_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<StringExercises> string_exerciser(new StringExercises());
    run_tests(string_exerciser.get());
    return 0;
}