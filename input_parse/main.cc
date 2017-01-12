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
    std::cout<<"Usage:: \"./FileMetrics <rootDirectoryName> <#directories> <#files> <SizeOfFiles> <ReadPercentage>\" \n";
    std::cout<<"Usage:: \"SizeOfFile: <0,4,32,64,128,256,512,1024> (0kb -> 1MB)\" \n";
    std::cout<<"Usage:: \"ReadPercentage: Percentage of Directories you want to Read (i.e. 30 == Read 30\% of the directories)\" \n"<<std::endl;
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
int main(int argc, char const *argv[]) {
    std::map<std::string, std::function<bool(std::unique_ptr<DummyClass> &, const std::set<std::string> &)>> function_map_;
    function_map_["A"] = TestSuiteOne;
    function_map_["B"] = TestSuiteTwo;
    function_map_["C"] = TestSuiteThree;
    function_map_["D"] = SingleDevTest;
    std::unique_ptr<DummyClass> dummy_class(new DummyClass());
    std::set<std::string> device_blacklist {};
    std::string target_device = "";
    // std::vector<std::string> device_list {};

    int device_path = std::stoi(argv[1]);

    if (device_path == 1) {
        function_map_["A"] (dummy_class, device_blacklist);
    } else if (device_path == 2) {
        function_map_["B"] (dummy_class, device_blacklist);
    } else {
        std::cout << "======= nuffin"<< std::endl;
    }

    return 0;
}