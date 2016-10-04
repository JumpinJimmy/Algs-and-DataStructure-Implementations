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
    int write_position = 0;
    int num_of_a = 0;
    int rev_read_pos = 0;
    int final_size = 0;

    /// First sweep, copy in place, skipping 'b' chars
    for (int i = 0; i < size; ++i) {
        if (s[i] != 'b') {
            s[write_position++] = s[i];
        }
        if (s[i] == 'a') {
            ++num_of_a;
        }
    }

    /// Debug output
    std::cout << "write_position at finish: " << write_position
    << "\n Char Array after 1st delete sweep: ";
    std::cout << "[ ";
    for (int j = 0; j < size; ++j) {
        std::cout << s[j] << " ";
    }
    std::cout << "]" << std::endl;

    /// Second sweep from the back + number of A's encountered
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

    /// Debug output
    std::cout << "\n Char Array Reverse sweep: ";
    std::cout << "[ ";
    for (int j = 0; j < final_size; ++j) {
        std::cout << s[j] << " ";
    }
    std::cout << "]" << std::endl;

    return final_size;
}

bool StringExercises::IsPalindromic(std::string &in_str) {
    if (in_str.length() < 2) {
        return true;
    }

    int left_pos = 0;
    int right_pos = in_str.length();
    for (; left_pos < right_pos; ++left_pos, --right_pos) {
        // if not alphanumeric increment / decrement
        while (!std::isalnum(in_str[left_pos]) && left_pos < right_pos) {
            ++left_pos;
        }

        while (!std::isalnum(in_str[right_pos]) && right_pos > left_pos) {
            --right_pos;
        }

        if (std::tolower(in_str[left_pos]) != std::tolower(in_str[right_pos])) {
            return false;
        }
    }
    return true;
}

void StringExercises::ReverseWords(std::string *sentence) {
    // still working on an inplace solution
    if (sentence->empty()) return;
    int left_wstart, left_wend = 0;
    int right_wstart = sentence->length() - 1;
    int right_wend = sentence->length() - 1;
    std::cout << "--->>--->> chap_seven:: sentance length " << sentence->length()  << std::endl;

    while (!std::isalnum(sentence->at(left_wstart)) && left_wstart < sentence->length()) {
        ++left_wstart;
    }
    std::cout << "left_wstart(" << left_wstart << ") char: " << sentence->at(left_wstart) << std::endl;
    left_wend = left_wstart;
    while (std::isalnum(sentence->at(left_wend + 1)) && left_wend < sentence->length()) {
        ++left_wend;
    }
    std::cout << "left_wend(" << left_wend << ") char: " << sentence->at(left_wend) << std::endl;
    while (!std::isalnum(sentence->at(right_wend)) && right_wend > 0) {
        --right_wend;
    }
    std::cout << "right_wend(" << right_wend << ") char: " << sentence->at(right_wend) << std::endl;
    right_wstart = right_wend;
    while (std::isalnum(sentence->at(right_wstart-1)) && right_wstart > 0) {
        --right_wstart;
    }
    std::cout << "right_wstart(" << right_wstart << ") char: " << sentence->at(right_wstart) << std::endl;

    char c = sentence->at(left_wstart);
    sentence->at(left_wstart) = sentence->at(right_wstart);
    sentence->at(right_wstart) = c;
}