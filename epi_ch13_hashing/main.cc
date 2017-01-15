#include <cassert> //NOLINT
#include <iostream>
#include <memory>
#include "includes/chap_thirteen.h"
// using namespace std; //NOLINT

void PermuteToPalindrome(HashTableExercises* ht_exerciser) {
    std::string test_str = "ala";
    std::cout << "--->>--->> main:: PermuteToPalindrome(\"" << test_str << "\"): " << std::boolalpha << ht_exerciser->PermuteToPalindrome(test_str) << std::endl;
}

void RunTests(HashTableExercises* ht_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
    PermuteToPalindrome(ht_exerciser);

}

// valgrind --leak-check=full --show-leak-kinds=all ./ch13_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HashTableExercises> ht_exerciser(new HashTableExercises());
    RunTests(ht_exerciser.get());
    return 0;
}
