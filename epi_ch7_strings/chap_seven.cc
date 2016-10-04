#include "includes/chap_seven.h"
StringExercises::StringExercises() {}

StringExercises::~StringExercises() {}

std::string StringExercises::IntToString(int in_int) {
    std::string result;
    bool negative = false;
    if (in_int < 0) {
        negative = true;
        in_int = -in_int; /// negate so @in_int is positive
    }

    do {
        result += '0' + in_int % 10;
        in_int /= 10;
    } while (in_int);

    if (negative) {
        result += '-';
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int StringExercises::StringToInt(std::string &in_str) {
    int result = 0;
    bool negative = in_str[0] == '-';
    int i = negative ? 1 : 0;

    for (; i < in_str.size(); ++i) {
        int digit = in_str[i] - '0';
        result = result * 10 + digit;
    }

    return negative ? -result : result;
}
