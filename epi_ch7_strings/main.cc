#include "includes/chap_seven.h"
#include <memory>
#include <utility>

using namespace std; //NOLINT

void InterConversion(StringExercises* string_exerciser) {
    std::cout << "--->>--->> main::InterCoversion "  << std::endl;
    int starting_integer = 14;
    std::string res_str = string_exerciser->IntToString(starting_integer);
    int res_int = string_exerciser->StringToInt(res_str);
}

void run_tests(StringExercises* string_exerciser) {
    InterConversion(string_exerciser);
}

int main(int argc, char const *argv[]) {
    std::shared_ptr<StringExercises> string_exerciser(new StringExercises());
    run_tests(string_exerciser.get());
    return 0;
}