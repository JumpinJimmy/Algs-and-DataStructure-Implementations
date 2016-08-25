#ifndef STRING_PROBS_H
#define STRING_PROBS_H
#include <iostream>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
class StringExerciser{

    public:
        StringExerciser();
        // StringExerciser(const StringExerciser &rhs);
        virtual ~StringExerciser();
        // const StringExerciser & operator=(const StringExerciser & rhs);
        void RemoveChars(std::string &source_str, std::string &remove_chars, bool case_sensitive = true);
        void RemoveChars(const char source_str[], const char remove_chars[], bool case_sensitive = true);
        char* FirstNonRepeat(std::string &source_str);
        int LongestSubstrDistinct(std::string &source_str, int n_distinct);

    private:
        void clear_sstream();
        std::stringstream ss_; //(std::ios_base::out | std::ios_base::ate);
};
#endif // STRING_PROBS_H
