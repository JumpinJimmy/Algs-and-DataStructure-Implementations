#ifndef CHAP_SEVEN_H
#define CHAP_SEVEN_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cctype>
#include <cmath>
#include <map>

class StringExercises {
    public:
        StringExercises();
        ~StringExercises();
        std::string IntToString(int x);
        int StringToInt(std::string &in_str);
        int ReplaceAndRemove(char s[], int size);
        bool IsPalindromic(std::string &in_str);
        void ReverseWords(std::string *input_str);
        std::vector<std::string> PhoneMnemonics(const std::string &phone_number);
    private:
        void MnemonicHelper(const std::string &phone_number, std::vector<std::string> *result_mnemonics, std::string *current_mnemonic, int digit, const std::map<char, std::string> *charset);
};

#endif // CHAP_SEVEN_H
