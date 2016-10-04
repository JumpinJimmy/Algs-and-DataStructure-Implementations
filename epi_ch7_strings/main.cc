#include "includes/chap_seven.h"
#include <memory>
#include <utility>
using namespace std; //NOLINT

void PrintVector(std::vector<std::string> &v) {
    std::cout << "PrintVector \n [ ";
    for (auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
}

void PhoneMnemonics(StringExercises* string_exerciser) {
    const std::string phone_number_one("2276696");
    const std::string phone_number_two("23");
    const std::string phone_number_three("9");
    std::vector<std::string> results = string_exerciser->PhoneMnemonics(phone_number_one);
    // PrintVector(results);
    results.clear();
    results = string_exerciser->PhoneMnemonics(phone_number_two);
    PrintVector(results);
    results.clear();
    results = string_exerciser->PhoneMnemonics(phone_number_three);
    PrintVector(results);
}

void ReverseWords(StringExercises* string_exerciser) {
    std::string test("I Like Pizza");
    string_exerciser->ReverseWords(&test);
    std::cout << test << std::endl;
    test.assign("Hello my name is Bastian, I enjoy fussball");
    string_exerciser->ReverseWords(&test);
}

void IsPalindromic(StringExercises* string_exerciser) {
    std::string test_str("A man, a plan, a canal, Panama.");
    std::cout << "IsPalindromic() for string: \"" << test_str << "\" result: "
              << std::boolalpha << string_exerciser->IsPalindromic(test_str) << std::endl;
    test_str.assign("Ray a Ray");
    std::cout << "IsPalindromic() for string: \"" << test_str << "\" result: "
              << std::boolalpha << string_exerciser->IsPalindromic(test_str) << std::endl;
}

void ReplaceRemove(StringExercises* string_exerciser) {
    int init_size = 7;
    char arr[10] = {'a', 'c', 'd', 'b', 'b', 'c', 'a', '0', '0', '0'};
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
    InterConversion(string_exerciser);
    ReplaceRemove(string_exerciser);
    IsPalindromic(string_exerciser);
    ReverseWords(string_exerciser);
    PhoneMnemonics(string_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch7_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<StringExercises> string_exerciser(new StringExercises());
    run_tests(string_exerciser.get());
    return 0;
}
