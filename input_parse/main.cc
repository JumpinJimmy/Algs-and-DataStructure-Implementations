#include "includes/dummy_class.h"
#include <iostream>
#include <map>
#include <sstream>
#include <memory>
#include <set>

bool TestOneSingle(std::unique_ptr<DummyClass> &dummy_class, const std::string &device_handle) {
    std::cout << "--->>--->> main::TestOneSingle" << std::endl;
    return true;
}

bool TestTwoSingle(std::unique_ptr<DummyClass> &dummy_class, const std::string &device_handle) {
    std::cout << "--->>--->> main::TestTwoSingle" << std::endl;
    return true;
}

bool TestThreeSingle(std::unique_ptr<DummyClass> &dummy_class, const std::string &device_handle) {
    std::cout << "--->>--->> main::TestThreeSingle" << std::endl;
    return true;
}

bool TestSuiteOne(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device_blacklist = {}) {
    std::cout << "--->>--->> main:: TestSuiteOne()" << std::endl;
    return true;
}

bool TestSuiteTwo(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device_blacklist = {}) {
    std::cout << "--->>--->> main:: TestSuiteTwo()" << std::endl;
    return true;
}

bool TestSuiteThree(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device_blacklist = {}) {
    std::cout << "--->>--->> main:: TestSuiteThree()" << std::endl;
    return true;
}

// valgrind --leak-check=full --show-leak-kinds=all ./input_parse
int main(int argc, char const *argv[]) {
    std::unique_ptr<DummyClass> dummy_class(new DummyClass());
    std::set<std::string> device_blacklist {"A"};

    /* code */
    return 0;
}