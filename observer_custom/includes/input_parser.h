#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H
#include <string>
#include "./user_service.h"
#include "./user.h"
#include <unordered_map>


class InputParser {
 public:
    InputParser();
    InputParser(const InputParser& rhs) = delete;
    virtual ~InputParser();
    const InputParser & operator=(const InputParser & rhs) = delete;
    void ReadFile(const std::string& input_file);
 private:
    std::unordered_map<std::string, std::unique_ptr<UserService>> services_;
    std::unordered_map<std::string, User> users_;
};

#endif  // INPUT_PARSER_H
