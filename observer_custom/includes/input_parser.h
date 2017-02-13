#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H
#include <string>
#include "./user_service.h"
#include "./user.h"

class InputParser {
 public:
    InputParser();
    InputParser(const InputParser& rhs) = delete;
    virtual ~InputParser();
    const InputParser & operator=(const InputParser & rhs) = delete;
    void ReadFile(const std::string& input_file);
};

#endif  // INPUT_PARSER_H
