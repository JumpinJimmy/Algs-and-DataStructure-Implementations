#ifndef CHAP_SIX_H
#define CHAP_SIX_H
#include <vector>

class ArrayExercises {
 public:
    ArrayExercises();
    virtual ~ArrayExercises();
    void SwapEvenOdd(std::vector<int>* int_list);
    std::vector<int> IncrementDecimal(std::vector<int> input_decimal);
    int RemDups(std::vector<int> *arr_ptr);
    int RemDupsInplace(std::vector<int> *arr_ptr);
    double MaxProfitSingleStock(const std::vector<double> &prices);
    int LongestSubArrayEqual(const std::vector<int> &int_list);
    std::vector<int> EnumeratePrimes(int n);
    std::vector<int> EnumeratePrimesOptimized(int n);
    void RandomSampling(std::vector<int> *arr_ptr, int size);
    bool ValidSudoku(const std::vector<std::vector<int>> &sudoku_board);
    std::vector<int> SpiralOrdering(std::vector<std::vector<int>> &matrix); // NOLINT

 private:
    bool SudokuDups(const std::vector<std::vector<int>> &sudoku_board,
                    int row_start, int row_end, int col_start, int col_end);
    void PrintGrid(const std::vector<std::vector<int>> &grid);
    void PrintSudoku(const std::vector<std::vector<int>> &sudoku_board);
    void print_list(const std::vector<int> &v);
    void print_list(const std::vector<double> &v);
};

#endif  // CHAP_SIX_H
