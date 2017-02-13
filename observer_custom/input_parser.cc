#include <fstream>
#include "includes/input_parser.h"

InputParser::InputParser() {}

InputParser::~InputParser() {}

void InputParser::ReadFile(const std::string& input_file) {
    std::string line;
    std::ifstream file_stream; //(input_file.c_str(), ios::in | ios::binary);
    file_stream.open(input_file);
    if (!file_stream.is_open()) {
        std::cout << "--->>--->> input_parser:: Failed to Open File: " << input_file  << std::endl;
        file_stream.close();
        return;
    }

    unsigned int curr_line = 0;
    while(getline(file_stream, line)) {
        curr_line++;
        std::cout << "Line: " << line << std::endl;
        // if (line.find(search, 0) != string::npos) {
        //     ///return to "root" directory
        //     chdir("../");
        //     return true;
        //     break;
        // }
    }
}
