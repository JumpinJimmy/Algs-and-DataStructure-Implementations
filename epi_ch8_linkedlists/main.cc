#include "includes/chap_eight.h"
using namespace std; //NOLINT

void run_tests(StringExercises* string_exerciser) {
    std::cout << "--->>--->> main::RunTests <<---<<--- " << std::endl;
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch7_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<LinkedListExercises> llist_exerciser(new LinkedListExercises());
    run_tests(llist_exerciser.get());
    return 0;
}
