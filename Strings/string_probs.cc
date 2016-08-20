#include "includes/string_probs.h"

// struct SetCaseCompare {  IGNORE FOR NOW
//     bool operator() (const std::string& a, const std::string& b) const {
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
        std::cout << "--->>--->> string_probs:: RemoveChars(string string) empty source or filter: " << source_str << std::endl;
        return;
    }
    if (source_str.compare(remove_chars) == 0) {
        source_str.assign("");
        std::cout << "--->>--->> string_probs:: RemoveChars(string string) source and remove are equal! empty result: " << source_str << std::endl;
        return;
    }

    std::set<char> blacklist;
    for (char c : remove_chars) {
        blacklist.insert(c);
    }

    std::set<char>::iterator set_iter;
    for (char src_char : source_str) {
        set_iter = blacklist.find(src_char);
        if (set_iter == blacklist.end()) {
            ss_ << src_char;
        }
    }

    source_str = ss_.str();
    clear_sstream();
    std::cout << "--->>--->> string_probs:: RemoveChars(string string) result: " << source_str << std::endl;
}

void StringExerciser::RemoveChars(const char source_str[], const char remove_chars[], bool case_sensitive) {
    std::cout << "--->>--->> string_probs::RemoveChars(const char " << source_str << ", const char " << remove_chars << ")" << std::endl;
    //TODO
}

void StringExerciser::clear_sstream() {
    ss_.clear();
    ss_.str("");
}