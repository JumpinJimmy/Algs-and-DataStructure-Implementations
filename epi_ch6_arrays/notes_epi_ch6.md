# Arrays #

*  6.1,6.2,6.5,6.6,6.8,6.11,6.16,6.17

*   Array problems usually have simple brute force solutions that use O(n) space, but subtler solutions exist which use the array itself to reduce space complexity to O(1)
*   consider overwriting an array entry rather than delete it

## Array & Vector Libraries of Note ##

*   Allocation & instantiating
    *   **array in c++11**: `array<int, 3> my_array = {1,2,3};`
    *   **vector in c++11**: `vector<int> v = {1,2,3};`
    *   **Sub Array from existing (A[i:j-1]):** `std::vector<int> subarr_a(A.begin() + i, A.begin() + j)`
    *   **2-D array or vector**
        *   `array<array<int,2>,3> 2d_array = {{1,2}, {3,4}, {5,6}}`
        *   `vector<vector<int>> 2d_vector = {{1,2}, {3,4}, {5,6}}`


**6.2:** Increment an arbitrary precision integer

`vector<int> IncrementInteger(vector<int> in_arr)`

*   Take in an array of digits encoding a decimal number **D**
*   Return / update the array to represent the number **D+1**
*   _example_:
    *   **IN**:  array[1,2,9]
    *   **OUT**: array[1,3,0]

**6.5:** Delete Duplicates from Sorted Array (supposed to be pseudo)

*   take in a sorted array and update it so all duplicates have been removed and remaining elements have been shifted left to fill the emptied indices.
*   Return the number of valid elements.

`int DeleteDups(vector<int> *arr_ptr)`

*   Take in an array of digits encoding a decimal number **D**
*   Return / update the array to represent the number **D+1**
*   _example_:
    *   **IN**:  array[1,1,1,2,3,4,4]
    *   **OUT**: array[1,2,3,4,0,0,0]


**6.6:** Buy and Sell a Stock Once

`double MaxProfitSingleStock(std::vector<double> &prices)`

**6.6 Variant**: Find length of a sub-array all of whose entries are equal

`int LongestSubArrayEqual(std::vector<int> &int_list)`

**6.8:** Enumerate All Primes to N (Pseudo Code Only)
`vector<int> EnumeratePrimes(int n)`


**6.11:** Sample Off-line Data (random sampling)

*   Take as input an array of distinct elements and size. Return a subset of the given size of array elements. All subsets should be equally likely. Return the result in the input array itself
    *   IN: Array of distinct elements
    *   IN: size
    *   Return: subset of size (input size) containing array elements


**6.16:** Sudoku Checker Problem

*   check whether a **9x9** 2D array representing  partially completed Sudoku is valid. 
*   **Namely:** check that no row, column, or **3x3** 2D sub-array contains duplicates
*   A value of '0' in the 2D array indicates that the entry is blank, every other entry is in [1,9]


**6.17:** Compute the Spiral ordering of a 2D Array

Write a 2D array in spiral order

![Spiral Array Illustration](../misc/SpiralArray.png "Optional title")
