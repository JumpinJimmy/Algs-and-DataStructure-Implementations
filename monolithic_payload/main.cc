#include <cassert> //NOLINT
#include <iostream>
#include "includes/file_handler.h"
using namespace std; //NOLINT

void EncodeIntoFile(FileHandler* file_handler, std::string &payload, int type) {
    std::cout << "\n--->>--->> main::EncodeIntoFile <<---<<--- " << std::endl;
    file_handler->MarshalValue(payload, type);
}

void RunTests(FileHandler* file_handler) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    std::string expression("JamesRobertDeVore");
    int type = 4;
    EncodeIntoFile(file_handler, expression, type);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch9_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<FileHandler> file_handler(new FileHandler());
    RunTests(file_handler.get());
    return 0;
}
