#ifndef CHAP_SEVEN_H
#define CHAP_SEVEN_H
#include <iostream>
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

class StringExercises {
    public:
        StringExercises();
        ~StringExercises();
        std::string IntToString(int x);
        int StringToInt(std::string &in_str);
        int ReplaceAndRemove(char s[], int size);
        bool IsPalindromic(std::string &in_str);
};

#endif // CHAP_SEVEN_H
