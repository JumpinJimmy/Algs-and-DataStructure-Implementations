# Arrays #

*  6.1, 6.6, 6.11,6.17,6.2,6.16,6.5,6.8

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






