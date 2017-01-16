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

bool HashTableExercises::ConstructibleLetter(const std::string &subject_letter, const std::string &magazine_text) {
    // foreach char in the letter; count frequency
    // loop over magazine and decrement frequency foreach letter encountered
    // if all frequencies are 0, success, if not , the letter cannot be rebuilt
    if (magazine_text.empty()) return false;
    if (subject_letter.empty()) return true;
    std::unordered_map<char, int> letter_char_freq;
    for (const char &c : subject_letter) {
        ++letter_char_freq[c];
    }

    for (const char &search_c : magazine_text) {
        auto char_iter = letter_char_freq.find(search_c);
        if (char_iter != letter_char_freq.end()) {
            --char_iter->second;
            if (char_iter->second == 0) {
                letter_char_freq.erase(search_c);
            }
        }
        if (letter_char_freq.empty()) break;
    }
    return letter_char_freq.empty();
}

int HashTableExercises::ShortestEqualValueDistance(const std::vector<std::string> &str_list) {
    return 0;
}
