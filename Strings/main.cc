#include <ios>
#include <iomanip>
#include <utility>
#include <stdlib.h>
#include "includes/string_probs.h"
using namespace std; //NOLINT

void remove_chars(StringExerciser *StrTester, std::string teststr, std::string blacklist) {
    std::string testcharstr = teststr;
    StrTester->RemoveChars(teststr, blacklist);
    StrTester->RemoveChars(testcharstr.c_str(), blacklist.c_str());
}

void run_string_tests(std::vector<std::pair<std::string, std::string>> &src_filter_list) {
    StringExerciser* StrTester = new StringExerciser();
    for (auto &x: src_filter_list) {
        remove_chars(StrTester, x.first, x.second);
    }
    delete StrTester;
}

// valgrind --leak-check=full --show-leak-kinds=all ./string_test
int main(int argc, char const *argv[]) {
    std::vector<std::string> source_str_list {"Hello James", "Goodbye Jon", "Nurburgring", "Hockenheim", "James", "staythesame", "AEIOUaeiou"};
    std::vector<std::string> filter_list {"lls", "o", "ur", "kn", "James", "", "AEIOU"};
    std::vector<std::pair<std::string, std::string>> src_filter_list;
    src_filter_list.reserve(source_str_list.size());

    std::transform(source_str_list.begin(), source_str_list.end(), filter_list.begin(), std::back_inserter(src_filter_list),
               [](std::string a, std::string b) { return std::make_pair(a, b); });

    run_string_tests(src_filter_list);
    return 0;
}