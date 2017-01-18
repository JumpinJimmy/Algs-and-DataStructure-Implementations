#include <utility>
#include <iostream>
#include <unordered_map>
#include <limits>
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

/////////////////////////////////////////////////////////
/// ConstructibleLetter(const std::string &, const std::string &)
/// -------------------------------------------
/// Takes text from an anonymous letter and text from a magazine.
/// Determines if the anonymous letter can be rebuilt using the magazine text
/// -------------------------------------------
/// @param[in] subject_letter - letter string to recreate
/// @param[in] magazine_text  - magazine text used to recreate letter
/// @return[out] boolean      - whether or not the letter can be reconstructed
bool HashTableExercises::ConstructibleLetter(const std::string &subject_letter, const std::string &magazine_text) {
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

/////////////////////////////////////////////////////////
/// ShortestEqualValueDistance(const std::vector<std::string> &)
/// -------------------------------------------
/// Find shortest distance between pair of equal strings
/// -------------------------------------------
/// @param[in] str_list - list of strings to evaluate
/// @return[out] int      - shortest distance beteen repeated words |  -1 if no repeated words
int HashTableExercises::ShortestEqualValueDistance(const std::vector<std::string> &str_list) {
    std::unordered_map<std::string, int> word_index_table;
    unsigned int index = 0;
    unsigned int shortest_distance_seen = std::numeric_limits<unsigned int>::max();
    for (const auto &curr_string : str_list) {
        auto table_iter = word_index_table.find(curr_string);
        if (table_iter == word_index_table.end()) {
            word_index_table[curr_string] = index;
        } else {
            shortest_distance_seen = std::min(shortest_distance_seen, index - table_iter->second);
            word_index_table[curr_string] = index;
        }
        index++;
    }
    return (shortest_distance_seen < std::numeric_limits<unsigned int>::max()) ? shortest_distance_seen : -1;
}

// Looking for Smallest Subarray from @content_arr that contains all elements from @search_keys
// Search Keys are all unique
// variables:
// -smallest_encountered ...
// -matching keywords & their indexes (map)
// -walking window (left ptr and right pointer)
// -size of search_key set
// TODO(jdevore): implement solution from book and understand differences / approach
// TODO(jdevore): clean up debug cout statements and organize this function
std::pair<int,int> HashTableExercises::RetreiveCoveringSubarraryIndex(const std::vector<std::string> &content_arr,
                                                                      const std::unordered_set<std::string> &search_keys) {
    std::cout << "--->>--->> chap_thirteen::RetreiveCoveringSubarraryIndex() " << std::endl;
    PrintCollection(content_arr);
    PrintSet(search_keys);
    std::pair<int, int> resultp(-1, -1);
    int left_ptr = 0;
    int right_ptr = 0;
    unsigned int smallest_subarr_seen = std::numeric_limits<unsigned int>::max();
    unsigned int curr_subarray_size = std::numeric_limits<unsigned int>::max();
    std::unordered_map<std::string, int> key_count_table;
    unsigned int set_size = search_keys.size();
    unsigned int content_size = content_arr.size();
    for (;right_ptr < content_size; ++right_ptr) {
        std::cout << "for (;right_ptr: " << right_ptr << " LT content_size: " << content_size <<"; ++right_ptr) {" << std::endl;
        auto search = search_keys.find(content_arr.at(right_ptr));
        if (search != search_keys.end()) {
            std::cout << "Add: " << *search << " to map" << std::endl;
            // add to map
            ++key_count_table[*search];
            if (key_count_table.size() >= set_size) {
                std::cout << "if (key_count_table.size() >= set_size).. \n SubarrayFind: key_count_table.size() = " << key_count_table.size() << std::endl;
                auto left_search = search_keys.find(content_arr.at(left_ptr));
                while (left_search == search_keys.end()) {
                    std::cout << "SubarrayFind:  while (left_search == search_keys.end()) {  (left_ptr: " << left_ptr << ", right_ptr: " << right_ptr << ") " << std::endl;
                    ++left_ptr;
                    left_search = search_keys.find(content_arr.at(left_ptr));
                }
                curr_subarray_size = right_ptr - left_ptr;
                std::cout << "---- ! curr_subarray_size: " << curr_subarray_size << ", smallest_seen: " << smallest_subarr_seen << std::endl;
                if (curr_subarray_size < smallest_subarr_seen) {
                    std::cout << "--->>--->> Current Sub array is Smaller than previous findings!"  << std::endl;
                    std::cout << "--->>--->> Updating Result Pair to left_ptr: " << left_ptr << ", right_ptr: " << right_ptr << std::endl;
                    resultp = std::make_pair(left_ptr, right_ptr);
                }
                // resultp = (curr_subarray_size <= smallest_subarr_seen) ? std::make_pair(left_ptr, right_ptr) : resultp;
                smallest_subarr_seen = std::min(curr_subarray_size, smallest_subarr_seen);
                while (key_count_table.size() >= set_size) {
                    std::cout << "while (key_count_table.size(" << key_count_table.size() << ") >= set_size(" << set_size <<")) {: left_ptr: " << left_ptr << ", right_ptr: " << right_ptr << std::endl;
                    std::cout << "  \\___>> data_arr.at(left_ptr) = " << content_arr.at(left_ptr) <<  std::endl;
                    std::cout << "  \\___>> data_arr.at(right_ptr) = " << content_arr.at(right_ptr) <<  std::endl;
                    std::string left_str = content_arr.at(left_ptr);
                    int count = key_count_table.find(left_str)->second;
                    if (count == 1) {
                        std::cout << "ERASING Keycount Table Erase (" << left_str << ")" << std::endl;
                        key_count_table.erase(left_str);
                        curr_subarray_size = right_ptr - left_ptr;
                        std::cout << "Erase Condition: ---- ! curr_subarray_size: " << curr_subarray_size << ", smallest_seen: " << smallest_subarr_seen << std::endl;
                        if (curr_subarray_size < smallest_subarr_seen) {
                            std::cout << "Erase Condition: -->>--->> Current Sub array is Smaller than previous findings!"  << std::endl;
                            std::cout << "Erase Condition: --->>--->> Updating Result Pair to left_ptr: " << left_ptr << ", right_ptr: " << right_ptr << std::endl;
                            resultp = std::make_pair(left_ptr, right_ptr);
                            smallest_subarr_seen = std::min(curr_subarray_size, smallest_subarr_seen);
                        }
                    } else {
                        std::cout << "Keycount Table decrement (" << left_str << ")" << std::endl;
                        --key_count_table[left_str];

                    }
                    ++left_ptr;
                }
            }
        }
    }
    std::cout << "--->>--->> chap_thirteen:: End of Subarray Search. left_ptr: " << left_ptr << ", right_ptr: " << right_ptr << std::endl;
    std::cout << "     \\----> Index Left: " << resultp.first << ", Index Right: " << resultp.second << std::endl;
    return resultp;
}
