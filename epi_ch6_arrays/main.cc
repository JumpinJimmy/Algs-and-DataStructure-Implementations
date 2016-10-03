#include "includes/chap_six.h"
#include <cassert>
using namespace std; //NOLINT

void print_list(std::vector<int> &v) {
    std::cout << "Printing List: \n [ ";
    for (auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
}

void sudoku_checker(ArrayExercises *array_exerciser) {
    std::vector<std::vector<int>> sudoku_board(9, vector<int>(9, 0));
    /// valid sudoku
    sudoku_board[0] = {0, 2, 6, 0, 0, 0, 8, 1, 0};
    sudoku_board[1] = {3, 0, 0, 7, 0, 8, 0, 0, 6};
    sudoku_board[2] = {4, 0, 0, 0, 5, 0, 0, 0, 7};
    sudoku_board[3] = {0, 5, 0, 1, 0, 7, 0, 9, 0};
    sudoku_board[4] = {0, 0, 3, 9, 0, 5, 1, 0, 0};
    sudoku_board[5] = {0, 4, 0, 3, 0, 2, 0, 5, 0};
    sudoku_board[6] = {1, 0, 0, 0, 3, 0, 0, 0, 2};
    sudoku_board[7] = {5, 0, 0, 2, 0, 4, 0, 0, 9};
    sudoku_board[8] = {0, 3, 8, 0, 0, 0, 4, 6, 0};
    array_exerciser->ValidSudoku(sudoku_board);
    /// duplicate value within first row
    sudoku_board[0] = {2, 2, 6, 0, 0, 0, 8, 1, 0};
    sudoku_board[1] = {3, 0, 0, 7, 0, 8, 0, 0, 6};
    sudoku_board[2] = {4, 0, 0, 0, 5, 0, 0, 0, 7};
    sudoku_board[3] = {0, 5, 0, 1, 0, 7, 0, 9, 0};
    sudoku_board[4] = {0, 0, 3, 9, 0, 5, 1, 0, 0};
    sudoku_board[5] = {0, 4, 0, 3, 0, 2, 0, 5, 0};
    sudoku_board[6] = {1, 0, 0, 0, 3, 0, 0, 0, 2};
    sudoku_board[7] = {5, 0, 0, 2, 0, 4, 0, 0, 9};
    sudoku_board[8] = {0, 3, 8, 0, 0, 0, 4, 6, 0};
    array_exerciser->ValidSudoku(sudoku_board);
}

void enumerate_primes(ArrayExercises *array_exerciser) {
    int prime_ceiling = 18;
    vector<int> prime_result = array_exerciser->EnumeratePrimes(prime_ceiling);
    print_list(prime_result);
    prime_result = array_exerciser->EnumeratePrimesOptimized(prime_ceiling);
    print_list(prime_result);
}

void longest_subarray(ArrayExercises *array_exerciser) {
    int result = 0;
    std::vector<int> int_list {1, 2, 2, 2, 3, 1, 1, 1};
    result = array_exerciser->LongestSubArrayEqual(int_list);
    std::cout << "--->>--->> main::Longest Subarray: " << result  << std::endl;
    int_list = {1, 2, 2, 2, 2, 3, 3, 1, 1, 1};
    result = array_exerciser->LongestSubArrayEqual(int_list);
    std::cout << "--->>--->> main::Longest Subarray: " << result  << std::endl;
    int_list = {1, 2, 3, 4, 4};
    result = array_exerciser->LongestSubArrayEqual(int_list);
    std::cout << "--->>--->> main::Longest Subarray: " << result  << std::endl;
}

void maxprofit_stock(ArrayExercises *array_exerciser) {
    std::vector<double> stockprices {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    double max_profit = array_exerciser->MaxProfitSingleStock(stockprices);
    std::cout << "--->>--->> main::Max Profit " << max_profit  << std::endl;
    stockprices = {100};
    max_profit = array_exerciser->MaxProfitSingleStock(stockprices);
    std::cout << "--->>--->> main::Max Profit " << max_profit  << std::endl;
}

void remove_duplicates(ArrayExercises *array_exerciser) {
    std::cout << "--->>--->> main::Remove Duplicates " << std::endl;
    int result, result2 = 0;
    std::vector<int> int_list {1, 1, 2, 3, 4, 5, 5, 6, 7};
    result = array_exerciser->RemDups(&int_list);
    result2 = array_exerciser->RemDupsInplace(&int_list);
    std::cout << "Result of Remove Dups1: " << result
              << "\n Result of RemoveDupsInplace: " << result2 << std::endl;
    int_list.clear();
    int_list = {1, 1, 1, 1, 2, 3, 4, 5, 5, 6, 7, 7};
    result = array_exerciser->RemDups(&int_list);
    result2 = array_exerciser->RemDupsInplace(&int_list);
    std::cout << "Result of Remove Dups1: " << result
              << "\n Result of RemoveDupsInplace: " << result2 << std::endl;
}

void run_tests(ArrayExercises *array_exerciser) {
    std::vector<int> int_list {3, 5, 4, 2, 9, 7, 4};
    print_list(int_list);
    array_exerciser->SwapEvenOdd(&int_list);
    print_list(int_list);
    std::vector<int> v = {1, 2};
    std::vector<int> res = array_exerciser->IncrementDecimal(v);
    print_list(res);
    v = {1, 9};
    res = array_exerciser->IncrementDecimal(v);
    print_list(res);
    v = {9, 9};
    res = array_exerciser->IncrementDecimal(v);
    print_list(res);
    remove_duplicates(array_exerciser);
    maxprofit_stock(array_exerciser);
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch6_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<ArrayExercises> array_exerciser(new ArrayExercises());
    // longest_subarray(array_exerciser.get());
    // enumerate_primes(array_exerciser.get());
    sudoku_checker(array_exerciser.get());
    // run_tests(array_exerciser.get());
    return 0;
}
