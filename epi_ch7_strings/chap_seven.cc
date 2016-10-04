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

int StringExercises::ReplaceAndRemove(char s[], int size) {
    // Brute force Solution
    int write_position = 0;
    int final_size = 0;
    char result[size+1] = " ";  //this wont work if all a's
    for (int i = 0; i < size; ++i) {
        if (s[i] == 'b') {
            continue;
        } else if (s[i] == 'a') {
            result[write_position++] = 'd';
            result[write_position++] = 'd';
            final_size += 2;
        } else {
            result[write_position++] = s[i];
            final_size++;
        }
    }
    std::cout << "[ ";
    for (int j = 0; j < final_size; ++j) {
        std::cout << result[j] << " ";
    }
    std::cout << "]" << std::endl;
    return final_size;
}
