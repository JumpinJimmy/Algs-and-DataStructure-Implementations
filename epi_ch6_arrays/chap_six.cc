#include "includes/chap_six.h"
#include <iostream>
#include <algorithm>

ArrayExercises::ArrayExercises() {
    std::cout << "--->>--->> chap_six::ArrayExercises construct " << std::endl;
}

ArrayExercises::~ArrayExercises() {}

void ArrayExercises::print_list(const std::vector<int> &v) {
    std::cout << "c6Printing List: \n [ ";
    for (auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
}

void ArrayExercises::print_list(const std::vector<double> &v) {
    std::cout << "c6Printing List: \n [ ";
    for (auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
}

void ArrayExercises::PrintGrid(const std::vector<std::vector<int>> &grid) {
    for (auto& y : grid) {
        std::cout << std::endl;
        for (auto &x : y) {
            std::cout << x << " ";
        }
    }
    std::cout << std::endl;
}

/// very crude printing of sudoku board. Will improve later
void ArrayExercises::PrintSudoku(const std::vector<std::vector<int>> &sudoku_board) {
    int column_ctr = 0;
    int row_ctr = 0;
    int boundary_location = std::sqrt(sudoku_board.size()) - 1;
    std::cout << "|- - - - - - - - -|" << std::endl;
    for (auto &row : sudoku_board) {
        std::cout << "|";
        for (auto &col : row) {
            if (column_ctr == boundary_location) {
               std::cout << col << "|";
               column_ctr = 0;
            } else {
                std::cout << col << " ";
                column_ctr++;
            }
        }
        std::cout << std::endl;
        if (row_ctr == boundary_location) {
            std::cout << "|- - - - - - - - -|" << std::endl;
            row_ctr = 0;
        } else {
            row_ctr++;
        }
    }
}

void ArrayExercises::SwapEvenOdd(std::vector<int>* int_list) {
    std::cout << "--->>--->> chap_six:: SwapEvenOdd" << std::endl;
    std::vector<int> &list = *int_list;
    int even_ptr = 0;
    int odd_ptr = list.size() - 1;
    while (even_ptr < odd_ptr) {
        if (list[even_ptr] % 2 == 0) {
            even_ptr++;
        } else {
            std::swap(list[even_ptr], list[odd_ptr--]);
        }
    }
}

std::vector<int> ArrayExercises::IncrementDecimal(std::vector<int> input_decimal) {
    std::cout << "--->>--->> chap_six::IncrementDecimal()";
    print_list(input_decimal);

    ++input_decimal.back();
    for (int i = input_decimal.size() - 1; i > 0 && input_decimal[i] == 10; --i) {
        input_decimal[i] = 0;
        input_decimal[i-1] = input_decimal[i-1] + 1;
    }

    if (input_decimal[0] == 10) {
        input_decimal[0] = 0;
        input_decimal.insert(input_decimal.begin(), 1);
    }
    return input_decimal;
}

int ArrayExercises::RemDups(std::vector<int> *arr_ptr) {
    if (arr_ptr->empty()) {
        std::cout << "--->>--->> chap_six::RemDups ERROR array is empty() "  << std::endl;
        return 0;
    } else if (!(std::is_sorted(arr_ptr->begin(), arr_ptr->end()))) {
        std::cout << "--->>--->> chap_six::RemDups ERROR array is not sorted " << std::endl;
        return 0;
    }
    std::vector<int> result_vec;
    result_vec.reserve(arr_ptr->size());
    for (auto value : *arr_ptr) {
        if (std::find(result_vec.begin(), result_vec.end(), value) == result_vec.end())
            result_vec.push_back(value);
    }
    return result_vec.size();
}

int ArrayExercises::RemDupsInplace(std::vector<int> *arr_ptr) {
    if (arr_ptr->empty()) {
        std::cout << "--->>--->> chap_six::RemDupsInplace ERROR array is empty() "  << std::endl;
        return 0;
    } else if (!(std::is_sorted(arr_ptr->begin(), arr_ptr->end()))) {
        std::cout << "--->>--->> chap_six::RemDupsInplace ERROR array not sorted" << std::endl;
        return 0;
    }

    std::vector<int> &array = *arr_ptr;
    print_list(array);
    int vacant_index = 1;
    for (int i = 1; i < array.size(); i++) {
        if (array[vacant_index - 1] != array[i]) {
            array[vacant_index++] = array[i];
        }
    }
    print_list(*arr_ptr);
    return vacant_index;
}

double ArrayExercises::MaxProfitSingleStock(const std::vector<double> &prices) {
    std::cout << "--->>--->> chap_six::MaxProfit for prices: ";
    print_list(prices);
    if (prices.empty() || prices.size() < 2) {
        return 0;
    }
    double max_profit = 0;
    double min_price_seen = std::numeric_limits<double>::max();
    for (auto &price : prices) {
        double maxprof_sell = price - min_price_seen;
        min_price_seen = std::min(min_price_seen, price);
        max_profit = std::max(maxprof_sell, max_profit);
    }
    return max_profit;
}


int ArrayExercises::LongestSubArrayEqual(const std::vector<int> &int_list) {
    std::cout << "--->>--->> chap_six::LongestSubArrayEqual for int_list: ";
    print_list(int_list);
    if (int_list.empty() || int_list.size() < 2) {
        return int_list.size();
    }
    int i = 0;
    int result_start, largest_seen, left_ptr, right_ptr, curr_val, curr_size = 0;
    while (i < int_list.size()) {
        if (int_list[i] == int_list[i + 1]) {
            curr_size = 1;
            left_ptr = i;
            right_ptr = left_ptr + 1;
            curr_val = int_list[left_ptr];
            while (right_ptr < int_list.size() && int_list[right_ptr] == curr_val) {
                curr_size++;
                right_ptr++;
            }
            if (curr_size > largest_seen) {
                largest_seen = curr_size;
                result_start = left_ptr;
            }
            i = right_ptr;
        } else {
            i++;
        }
    }

    /// Sub-Array Print is for Debug & Verification purposes only
    std::vector<int> result_arr(int_list.begin() + result_start, int_list.begin() + (result_start + largest_seen)); //NOLINT
    print_list(result_arr);
    return largest_seen;
}

std::vector<int> ArrayExercises::EnumeratePrimes(int n) {
    if (n < 2) {
        return {};  // empty list
    }
    if (n == 2) {
        return {2};
    }
    std::vector<int> primes;
    std::vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;  // 0 & 1 are not prime numbers

    for (int pval = 2; pval < n; pval++) {
        if (is_prime.at(pval)) {
            primes.push_back(pval);
            // set all multiples of current prime value to false
            for (int multiple = pval; multiple < n; multiple += pval) {
                is_prime.at(multiple) = false;
            }
        }
    }
    return primes;
}

std::vector<int> ArrayExercises::EnumeratePrimesOptimized(int n) {
    std::cout << "--->>--->> chap_six::EnumeratePrimesOptimized( " << n << " )" << std::endl;
    if (n < 2) {
        return {};  // empty list
    }
    const int num_possible_primes = floor(0.5 * (n - 3)) + 1;
    std::vector<bool> is_prime(num_possible_primes, true);
    std::vector<int> primes;
    primes.push_back(2);
    for (int i = 0; i < num_possible_primes; ++i) {
        if (is_prime.at(i)) {
            int pval = (i * 2) + 3;
            primes.push_back(pval);
            // clean this long statement up
            for (long mult_sq = ((static_cast<long>(i) * static_cast<long>(i)) * 2) + 6 * i + 3; mult_sq < num_possible_primes; mult_sq += pval) { //NOLINT
                is_prime.at(mult_sq) = false;
            }
        }
    }
    return primes;
}

/// TODO(jdevore): implement when we have time, not much to learn here at the moment
void ArrayExercises::RandomSampling(std::vector<int> *arr_ptr, int size) {
    return;
}

bool ArrayExercises::ValidSudoku(const std::vector<std::vector<int>> &sudoku_board) {
    PrintSudoku(sudoku_board);
    /// Check Each Row
    int row_ptr, col_ptr = 0;
    for (row_ptr = 0; row_ptr < sudoku_board.size(); ++row_ptr) {
        if (SudokuDups(sudoku_board, row_ptr, row_ptr + 1, col_ptr, sudoku_board.size())) {
            return false;
        }
    }
    /// Check Each Column
    row_ptr = 0;
    for (col_ptr = 0; col_ptr < sudoku_board.size(); ++col_ptr) {
        if (SudokuDups(sudoku_board, row_ptr, sudoku_board.size(), col_ptr, col_ptr + 1)) {
            return false;
        }
    }

    /// Check each Sub Section (3x3 board)
    int sub_start_row, sub_end_row, sub_start_col, sub_end_col = 0;
    int sub_regions = std::sqrt(sudoku_board.size());
    for (int subarr_row = 0; subarr_row < sub_regions; ++subarr_row) {
        for (int subarr_col = 0; subarr_col < sub_regions; ++subarr_col) {
            sub_start_row = subarr_row * sub_regions;
            sub_end_row = ((subarr_row + 1) * sub_regions);
            sub_start_col = subarr_col * sub_regions;
            sub_end_col = ((subarr_col + 1) * sub_regions);
            if (SudokuDups(sudoku_board, sub_start_row, sub_end_row, sub_start_col, sub_end_col)) {
                std::cout << "Duplicate Subarray value found in [["
                          << sub_start_row << "][" << sub_end_row << "] , ["
                          << sub_start_col << "][" << sub_end_col << "]] " << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool ArrayExercises::SudokuDups(const std::vector<std::vector<int>> &sudoku_board,
                                int row_start, int row_end, int col_start, int col_end) {
    std::vector<bool> has_value(sudoku_board.size() + 1, false);
    for (int row = row_start; row < row_end; ++row) {
        for (int col = col_start; col < col_end; ++col) {
            if (sudoku_board[row][col] != 0 && has_value[sudoku_board[row][col]]) {
                std::cout << "Duplicate value found at ["
                          << row << "][" << col << "] == " << sudoku_board[row][col] << std::endl;
                return true;
            }
            has_value[sudoku_board[row][col]] = true;
        }
    }
    return false;
}

std::vector<int> ArrayExercises::SpiralOrdering(std::vector<std::vector<int>> &matrix) {
    std::cout << "--->>--->> chap_six::Spiral Ordering for Matrix:\n ";
    PrintGrid(matrix);
    int total_size = matrix.size() * matrix.size();
    const std::vector<std::vector<int>> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int direction = 0, x = 0, y = 0;
    int next_x , next_y = 0;
    std::vector<int> spiral_result;
    spiral_result.reserve(total_size);
    for (int i = 0; i < total_size; ++i) {
        spiral_result.emplace_back(matrix[x][y]);
        matrix[x][y] = 0;
        next_x = x + directions[direction][0];
        next_y = y + directions[direction][1];
        if (next_x < 0 || next_x >= matrix.size() || next_y < 0 || next_y >= matrix.size() ||
            matrix[next_x][next_y] == 0) {
            direction = (direction + 1) % 4;
            next_x = x + directions[direction][0];
            next_y = y + directions[direction][1];
        }
        x = next_x;
        y = next_y;
    }
    return spiral_result;
}
