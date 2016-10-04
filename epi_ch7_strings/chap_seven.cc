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

void StringExercises::ReverseWords(std::string *input_str) {
    if (input_str->empty()) return;
    size_t left_word_start = 0;
    size_t left_word_end;

    std::cout << "--->>--->> ReverseWords(string *input_str = \"" << *input_str << "\")"
              << ": input_str length = " << input_str->length() << std::endl;

    std::reverse(input_str->begin(), input_str->end());

    std::cout << "ReverseWords -> Reverse Entire String = \"" << *input_str << "\"" << std::endl;

    while ((left_word_end = input_str->find(" ", left_word_start)) != std::string::npos) {
        std::reverse(input_str->begin() + left_word_start, input_str->begin() + left_word_end);
        left_word_start = left_word_end + 1;
        std::cout << "ReverseWords iteration:: " << *input_str << std::endl;
    }

    std::reverse(input_str->begin() + left_word_start, input_str->end());
    std::cout << "ReverseWords -> Reversed String Final = \"" << *input_str << "\"" << std::endl;
}

std::vector<std::string> StringExercises::PhoneMnemonics(const std::string &phone_number) {
    std::vector<std::string> result_mnemonics;
    std::string current_mnemonic(phone_number.length(), 0);
    int starting_digit = 0;

    /// mapping digit to character set
    const std::map<char, std::string> char_sets {
                                        {'0', "0"},
                                        {'1', "1"},
                                        {'2', "abc"},
                                        {'3', "def"},
                                        {'4', "ghi"},
                                        {'5', "jkl"},
                                        {'6', "mno"},
                                        {'7', "pqrs"},
                                        {'8', "tuv"},
                                        {'9', "wxyz"},
                                        {'*', "*"},
                                        {'#', "#"},
    };
    MnemonicHelper(starting_digit, phone_number, &current_mnemonic, &result_mnemonics, &char_sets);
    return result_mnemonics;
}

void StringExercises::MnemonicHelper(int digit, const std::string &phone_number,
                                     std::string *current_mnemonic,
                                     std::vector<std::string> *result_mnemonics,
                                     const std::map<char, std::string> *charset) {
    if (digit == phone_number.size()) {
        result_mnemonics->emplace_back(*current_mnemonic);
        return;
    }

    auto curr_charset = charset->find(phone_number.at(digit));
    if (curr_charset != charset->end()) {
        for (char c : curr_charset->second) {
            current_mnemonic->at(digit) = c;
            MnemonicHelper(digit + 1, phone_number, current_mnemonic, result_mnemonics, charset);
        }
    }
}
