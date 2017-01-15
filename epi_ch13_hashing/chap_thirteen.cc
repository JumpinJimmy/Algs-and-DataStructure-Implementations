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

    int odd_char_count = 0;
    std::unordered_map<char, int> char_freq_map;
    for (const char &c : subject_string) {
        ++char_freq_map[c];
    }

    for (const auto &map_iter : char_freq_map) {
        if ((map_iter.second % 2) && (++odd_char_count > 1)) {
            return false;
        }
    }
    return true;
}
