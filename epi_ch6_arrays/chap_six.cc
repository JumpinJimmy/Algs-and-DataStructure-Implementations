#include "includes/chap_six.h"
ArrayExercises::ArrayExercises() {
    std::cout << "--->>--->> chap_six::ArrayExercises construct " << std::endl;
}

ArrayExercises::~ArrayExercises() {}

void ArrayExercises::print_list(std::vector<int> &v) {
    std::cout << "c6Printing List: \n [ ";
    for (auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
}

void ArrayExercises::print_list(std::vector<double> &v) {
    std::cout << "c6Printing List: \n [ ";
    for (auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << "];" << std::endl;
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

double ArrayExercises::MaxProfitSingleStock(std::vector<double> &prices) {
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


int ArrayExercises::LongestSubArrayEqual(std::vector<int> &int_list) {
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
        return {}; //empty list
    }
    if (n == 2) {
        return {2};
    }
    std::vector<int> primes;
    std::vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false; // 0 & 1 are not prime numbers

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
        return {}; //empty list
    }
    const int num_possible_primes = floor(0.5 * (n - 3)) + 1;
    std::vector<bool> is_prime(num_possible_primes, true);
    std::vector<int> primes;
    primes.push_back(2);
    for (int i = 0; i < num_possible_primes; ++i) {
        if (is_prime.at(i)) {
            int pval = (i * 2) + 3;
            primes.push_back(pval);
            //clean this long statement up
            for (long mult_sq = ((static_cast<long>(i) * static_cast<long>(i)) * 2) + 6 * i + 3; mult_sq < num_possible_primes; mult_sq += pval) {
                is_prime.at(mult_sq) = false;
            }
        }
    }
    return primes;
}

void RandomSampling(std::vector<int> *arr_ptr, int size) {
    return;
}
