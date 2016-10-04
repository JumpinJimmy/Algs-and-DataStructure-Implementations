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
    // In place Solution (O(n) space)
    int write_position = 0;
    int num_of_a = 0;
    int rev_read_pos = 0;
    int final_size = 0;
    // char result[size+1] = " ";  //this wont work if all a's
    for (int i = 0; i < size; ++i) {
        if (s[i] != 'b') {
            s[write_position++] = s[i];
        }
        if (s[i] == 'a') {
            ++num_of_a;
        }
    }
    std::cout << "write_position at finish: " << write_position
    << "\n Char Array after 1st delete sweep: ";
    std::cout << "[ ";
    for (int j = 0; j < size; ++j) {
        std::cout << s[j] << " ";
    }
    std::cout << "]" << std::endl;
    rev_read_pos = write_position - 1;
    write_position = write_position + num_of_a - 1;
    final_size = write_position + 1;

    while (rev_read_pos >= 0) {
        if (s[rev_read_pos] == 'a') {
            s[write_position--] = 'd';
            s[write_position--] = 'd';
        } else {
            s[write_position--] = s[rev_read_pos];
        }
        --rev_read_pos;
    }
    std::cout << "\n Char Array Reverse sweep: ";
    std::cout << "[ ";
    for (int j = 0; j < final_size; ++j) {
        std::cout << s[j] << " ";
    }
    std::cout << "]" << std::endl;
    return final_size;
}
