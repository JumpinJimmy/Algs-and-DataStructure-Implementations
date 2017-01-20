# Sorting Chapter 14 #

* 14.1, 14.2, 14.4, 14.6, 14.9

*   z

## Array & Vector Libraries of Note ##

*   Allocation & instantiating
    *   **array in c++11**: `array<int, 3> my_array = {1,2,3};`
    *   **vector in c++11**: `vector<int> v = {1,2,3};`
    *   **Sub Array from existing (A[i:j-1]):** `std::vector<int> subarr_a(A.begin() + i, A.begin() + j)`
    *   **2-D array or vector**
        *   `array<array<int,2>,3> 2d_array = {{1,2}, {3,4}, {5,6}}`
        *   `vector<vector<int>> 2d_vector = {{1,2}, {3,4}, {5,6}}`

---


**14.1 Compute the Intersection of Two Sorted Arrays**

*  Write a program which takes as input two sorted arrays, and returns a new array containing elements that are present in both of the input arrays. The input arrays may have duplicates, but the resulting array should have no duplicates.
*  **Input:** Two _sorted_ arrays/lists e.g. `ComputeIntersection(std::vector<int>& A1, std::vector<int>& A2)` 
*  **Output:** A single list of elements that are present in both of the input arrays
*  _example:_  `[2,3,3,5,5,6,7,7,8,12]` and `[5,5,6,8,8,9,10,10]` should return: `[5,6,8]`

`std::vector<int> ComputeListIntersection(std::vector<int>& A1, std::vector<int>& A2)`


**14.2 Merge Two Sorted Arrays**

*  Write a program which takes as input two sorted arrays of integers, and updates the first to the combined entries of the two arrays in sorted order.
*  Assume the first array has enough empty entries at its end to hold the result
*  **Input:** Two Arrays and two size values int A1[], int size_one, int A2[], int size_two
*  **Output:** void / edit first list in place 
*  _example:_ `(5,13, 17, _ _ _ _ )` and `(3, 7, 11, 19)`, where `_`
denotes an empty entry. Then the combined sorted entries can be stored in the first array as `(3, 5, 7, 11, 13,17, 19, _)`

`void MergeTwoSortedArrays(int A1[], int size_one, int A2[], int size_two)`


**14.4 Render A Calendar**

*  Write a program that takes a set of events, and determines the maximum number of events that take place concurrently
*  Suppose each day consists of a number of events, where an event is specified as a **start time** and a **finish time**. 

*  **Input:** list `std::vector<event> events` of pairs `event<int start, int finish>`
*  **Output:** Integer indicating the maximum number of events that take place concurrently
*  _example:_   `vector<Event> A = {{1, 5},  {2, 7},   {4, 5},   {6, 10}, {8, 9}, {9, 17}, {11, 13}, {12, 15}, {14, 15}};`
    *  `assert(FindMaxSimultaneousEvents(A) == 3);`

`int FindMaxSimultaneousEvents(std::vector<event> events)`


**14.6 Compute Union of Intervals**

*  details
*  **Input:**
*  **Output:**
*  _example:_ x

`return function_name(type arg, type arg)`


**14.9 Implement a Fast Sorting Algorithm for Lists**

*  details
*  **Input:**
*  **Output:**
*  _example:_ x

`return function_name(type arg, type arg)`

