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

bool SingleDevTest(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device = {}) {
    std::cout << "======= main:: SingleDevTest " << std::endl;
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

void usage(){
    std::cout<<"Usage:: \"./input_parse <dev> <test> \n";
}
// /////////////////////////
// args
// -device "/dev/sdb" or blank
// -devicelist "/dev/sdc, /dev/sdb"
// -test "A" (A or B or C or Blank)
// -blacklist "/dev/sdc, /dev/sdb"
// valgrind --leak-check=full --show-leak-kinds=all ./input_parse
// http://devdocs.io/cpp/language/main_function
// https://msdn.microsoft.com/en-us/library/17w5ykft.aspx
// http://courses.cms.caltech.edu/cs11/material/c/mike/misc/cmdline_args.html
// http://stackoverflow.com/questions/5272550/c-command-line-parameters
// http://stackoverflow.com/questions/15344714/convert-command-line-argument-to-string
// http://www.cplusplus.com/forum/articles/13355/
int main(int argc, char const *argv[]) {
    std::map<std::string, std::function<bool(std::unique_ptr<DummyClass> &, const std::set<std::string> &)>> function_map_;
    function_map_["A"] = TestSuiteOne;
    function_map_["B"] = TestSuiteTwo;
    function_map_["C"] = TestSuiteThree;
    function_map_["D"] = SingleDevTest;
    std::unique_ptr<DummyClass> dummy_class(new DummyClass());
    std::set<std::string> device_blacklist {};
    std::string target_device = "";

    if (argc < 2) {
        std::cout<<"INCORRECT AMOUNT OF ARGUMENTS"<<std::endl;
        usage();
        exit(EXIT_FAILURE);
    } else {
        std::vector<std::string> args;
        std::copy(argv + 1, argv + argc, std::back_inserter(args));
        int param_count = argc;
        std::cout << "======= main:: arg count " << param_count << std::endl;
        unsigned int param_flag_index = 0;
        unsigned int param_val_index = 1;

        // while ()
        // for (auto str : args) {
        //     std::cout << "======= main:: arg = " << str << std::endl;
        //     if (str.compare("-d")) {

        //     }
        // }
    // for (auto iter = args.begin(); iter != args.end(); ++iter) {
    //     std::cout << *iter << ' ';
    //     if (*iter.compare("-d")) {
    //         target_device = *std::next(iter,1);
    //         std::cout << "======= main:: target_device " << target_device << std::endl;
    //     }
    }
        // for (int i = 1; i < param_count; ++i) {
        //     if (strcmp(argv[i], "-d") == 0) {
        //         if (argv[i][0] == "")
        //     }
        //     // if (i + 1 != param_count) {
        //         std::cout << "======= main::argv[" << i << "] = " << argv[i] << std::endl;
        //     // }
        // }
    // }
        // if ( strcmp(argv[i], "-v") == 0 ) {

        //     zbc_set_log_level("debug");

        // } else if ( strcmp(argv[i], "-n") == 0 ) {

        //     num = 1;

        //  } else if ( strcmp(argv[i], "-nz") == 0 ) {

        //     if ( i >= (argc - 1) ) {
        //         goto usage;
        //     }
        //     i++;
    // std::vector<std::string> device_list {};

    // int device_path = std::stoi(argv[1]);

    // if (device_path == 1) {
    //     function_map_["A"] (dummy_class, device_blacklist);
    // } else if (device_path == 2) {
    //     function_map_["B"] (dummy_class, device_blacklist);
    // } else {
    //     std::cout << "======= nuffin"<< std::endl;
    // }

    return 0;
}