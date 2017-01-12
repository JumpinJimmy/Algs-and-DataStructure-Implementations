#include "includes/dummy_class.h"
#include <iostream>
#include <map>
#include <sstream>
#include <functional>

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

bool functionptr_test(int a, std::string x) {
    std::cout << "======= main::bool functionptr_test(a: " << a << ", string: " << x << ") CALLED! " << std::endl;
    return true;
}

bool functionptr_test_two(int a, std::string x) {
    std::cout << "======= main::bool functionptr_test_two(a: " << a << ", string: " << x << ") CALLED! " << std::endl;
    return true;
}

// valgrind --leak-check=full --show-leak-kinds=all ./input_parse
int main(int argc, char const *argv[]) {
    // std::map<std::string, bool (std::unique_ptr<DummyClass> &, const std::set<std::string> &)> function_map_;
    // std::map<std::string, std::function<bool(int, std::string)>> function_map_;
    std::map<std::string, std::function<bool(std::unique_ptr<DummyClass> &, const std::set<std::string> &)>> function_map_;
    function_map_["TestSuiteOne"] = TestSuiteOne;
    function_map_["TestSuiteTwo"] = TestSuiteTwo;

    // std::function<bool(int)> f_display = functionptr_test;
    // function_map_["functionptr_test"] = functionptr_test;
    // function_map_["functionptr_test_two"] = functionptr_test_two;
    std::unique_ptr<DummyClass> dummy_class(new DummyClass());
    std::set<std::string> device_blacklist {"A"};
    int device_path = std::stoi(argv[1]);

    // if (device_path == 1) {
    //     function_map_["functionptr_test"] (1, "call one");
    // } else if (device_path == 2) {
    //     function_map_["functionptr_test_two"] (2, "call two");
    // } else {
    //     std::cout << "======= nuffin"<< std::endl;
    // }
    if (device_path == 1) {
        function_map_["TestSuiteOne"] (dummy_class, device_blacklist);
    } else if (device_path == 2) {
        function_map_["TestSuiteTwo"] (dummy_class, device_blacklist);
    } else {
        std::cout << "======= nuffin"<< std::endl;
    }
    // f_display(12);

    /* code */
    return 0;
}