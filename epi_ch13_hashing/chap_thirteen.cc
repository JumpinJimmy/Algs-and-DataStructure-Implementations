#include <utility>
#include <iostream>
#include <unordered_map>
#include "includes/chap_thirteen.h"

HashTableExercises::HashTableExercises() {}

HashTableExercises::~HashTableExercises() {}

/////////////////////////////////////////////////////////
/// PermuteToPalindrome(const std::string &)
/// -------------------------------------------
/// if Length even: every letter must appear an even amount of times
/// if Length odd: every letter except one must appear an even amount of times
/// if Empty return false, if Length 1 return true
/// -------------------------------------------
/// @param[in] subject_string - string to evalute
/// @return[out] boolean
bool HashTableExercises::PermuteToPalindrome(const std::string &subject_string) {
    if (subject_string.empty()) return false;
    const int str_length = subject_string.length();
    bool even_length = (subject_string.length() % 2 == 0) ? true : false;
    std::unordered_map<char, int> char_freq_map;
    for (const char &c : subject_string) {
        std::cout << "char: " << c << " ";
        ++char_freq_map[c];
    } std::cout << std::endl;


    /// think about how to cycle over the string .

    return true;
}
