#include <fstream>
#include <sstream>

#include "includes/input_parser.h"

InputParser::InputParser() {}

InputParser::~InputParser() {}

/// Need To Store UserServices upon line reads
/// Need to create and Add Users to Users Services
/// TODO(jdevore) : figure out clean way to parse each line without a bunch of if(...) statements
void InputParser::ReadFile(const std::string& input_file) {
    std::string line;
    std::ifstream file_stream;  // (input_file.c_str(), ios::in | ios::binary);
    unsigned int line_quota = 0;
    int max_tokens = 4;
    file_stream.open(input_file);
    if (!file_stream.is_open()) {
        std::cerr << "--->>--->> input_parser:: Failed to Open File: " << input_file  << std::endl;
        file_stream.close();
        return;
    }
    file_stream >> line_quota;
    std::cout << "--->>--->> input_parser:: line_quota: " << line_quota  << std::endl;

    unsigned int curr_line = 0;
    while (getline(file_stream, line)) {
        curr_line++;
        if (curr_line <= 1) {
            continue;
        }
        std::cout << "Line(" << curr_line << "): " << line << std::endl;
        std::istringstream sstr(line);
        std::string token;
        std::string curr_token;
        int token_count = 0;
        while (sstr >> token && token_count < max_tokens) {
            std::cout << "Token: " << token << ", ";

            if (token == "service") {
                curr_token = token;
            }
        }
        if (curr_token == "service") {
            std::cout << "Currtoken: Service with Name of " << token << std::endl;
            auto new_service(std::make_unique<UserService>(token));
            services_[token] = std::move(new_service);
        }
        std::cout << std::endl;

    }
}
