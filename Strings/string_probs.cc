#include "includes/string_probs.h"

// struct SetCaseCompare {  IGNORE FOR NOW
//     bool operator() (const char& a, const char& b, bool ci) const {
//         if (ci) {
//             strcmp(s1, s2) < 0tolower(c)
//             return
//         }
//         return stricmp(a.c_str(), b.c_str()) < 0;
//     }
// };

StringExerciser::StringExerciser() {
    std::cout << "--->>--->> string_probs::StringExerciser " << std::endl;
    clear_sstream();
}

StringExerciser::~StringExerciser() {
    std::cout << "--->>--->> string_probs::~StringExerciser " << std::endl;
    clear_sstream();
}

// TODO(jdevore): case insensitive comparator? Want to avoid having to write functionality that decides which type of set to build, the comparator should handle case insensitivity set to either TRUE or FALSE.
void StringExerciser::RemoveChars(std::string &source_str, std::string &remove_chars, bool case_sensitive) {
    std::cout << "--->>--->> string_probs:: RemoveChars(string " << source_str << ", string " << remove_chars << ")" << std::endl;
    if (source_str.empty() || remove_chars.empty()) {
        std::cout << "\t--->> string_probs:: RemoveChars(string string) empty source or filter: " << source_str << std::endl;
        return;
    }
    clear_sstream();

    std::set<char> blacklist;
    for (char c : remove_chars) {
        if (!case_sensitive) {
            blacklist.insert(tolower(c));
        } else {
            blacklist.insert(c);
        }
    }

    std::set<char>::iterator set_iter;
    for (char src_char : source_str) {
        set_iter = (!case_sensitive) ? (blacklist.find(tolower(src_char))) : (blacklist.find(src_char));

        if (set_iter == blacklist.end()) {
            ss_ << src_char;
        }
    }

    source_str = ss_.str();
    clear_sstream();
    std::cout << "\t--->> string_probs:: RemoveChars(string string) result: " << source_str << std::endl;
}

void StringExerciser::RemoveChars(const char source_str[], const char remove_chars[], bool case_sensitive) {
    std::cout << "--->>--->> string_probs::RemoveChars(const char " << source_str << ", const char " << remove_chars << ")" << std::endl;
    //TODO
}

// char* StringExerciser::FirstNonRepeat(std::string &source_str) {

// }
//
//////////////////////////////////////////
//Keep Track of
// -Longest Seen
// -Current Lenght
// -Distinct Seen
// ----------
// Create These
// -Lookup Table
//
// THIS CODE WILL NOT WORK........ NEED TO IMPLEMENT A WALKING WINDOW
int StringExerciser::LongestSubstrDistinct(std::string &source_str, int n_distinct) {
// char lookup_table[256];
//set lookup table values to all zero
//longest_str = 0;
//distinct_seen = 0;
//curr_length = 0;
    // foreach(char c in source_str) {
    //     if (lookup_table[c] == 1) {
    //         curr_length++
    //     } else if (lookup_table[c] == 0 && distinct_seen+1 <= n_distinct) {
    //         lookup_table[c] = 1
    //         distinct_seen++
    //         curr_length++
    //     } else {
    //         if (curr_length > longest_str) { longest_str = curr_length;}
    //         clear lookup_table
    //         curr_length = 0
    //         distinct_seen = 0
    //     }
    // }
    // return longest_str;
    return 0;
}

int StringExerciser::LongestSubstrDistinct(std::string &source_str, int n_distinct) {
    // map<char,int> charmap;

    //longest_str = 0;
    //left_ptr = 0;
    // for(int i = 0; i < source_str.length(); i++) {
    //     char c = source_str.at(i);
    //     if (charmap.find(c)) {
    //         charmap.put(c,charmap.get(c)+1);
    //     } else {
    //         charmap.put(c,1);
    //     }

    //     if (charmap.size() > n_distinct) {
    //         longest_str = max(longest_str, i);

    //         while(charmap.size() > n_distinct) {
    //             char t = source_str.at(left_ptr);
    //             int count = charmap.get(t);
    //             if (count == 1) {
    //                 charmap.delete(t);
    //             } else {
    //                 charmap.put(c,count - 1);
    //             }
    //             left_ptr++;
    //         }
    //     }
    // }

    // longest_str = max(longest_str, sources_str.length() - left_ptr);
    // return longest_str;
    return 0;
}

void StringExerciser::clear_sstream() {
    ss_.clear();
    ss_.str("");
}