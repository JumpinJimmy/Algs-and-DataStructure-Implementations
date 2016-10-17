#ifndef CHAP_SEVEN_H
#define CHAP_SEVEN_H
#include <string>
#include <vector>
#include <map>

class StringExercises {
 public:
    StringExercises();
    ~StringExercises();
    std::string IntToString(int x);
    int StringToInt(const std::string &in_str);
    int ReplaceAndRemove(char s[], int size);
    bool IsPalindromic(const std::string &in_str);
    void ReverseWords(std::string *input_str);
    std::vector<std::string> PhoneMnemonics(const std::string &phone_number);
    std::string LookAndSay(int n);

 private:
    void MnemonicHelper(int digit, const std::string &phone_number,
                        std::string *current_mnemonic,
                        std::vector<std::string> *result_mnemonics,
                        const std::map<char, std::string> *charset);
    std::string GetNextSequenceStr(const std::string &curr_seq);
};

#endif  // CHAP_SEVEN_H
