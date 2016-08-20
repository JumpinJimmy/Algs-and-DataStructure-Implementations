#include "includes/string_probs.h"

StringProblem::StringProblem() {
    std::cout << "--->>--->> string_probs::StringProblem " << std::endl;
    clear_sstream();
}

// StringProblem(const StringProblem &rhs);
StringProblem::~StringProblem() {
    std::cout << "--->>--->> string_probs::~StringProblem " << std::endl;
    clear_sstream();
}

// const StringProblem & operator=(const StringProblem & rhs);
void StringProblem::RemoveChars(std::string &source_str, std::string &remove_chars) {
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

void StringProblem::RemoveChars(const char source_str[], const char remove_chars[]) {
    std::cout << "--->>--->> string_probs::RemoveChars(const char " << source_str << ", const char " << remove_chars << ")" << std::endl;

}

void StringProblem::clear_sstream() {
    ss_.clear();
    ss_.str("");
}