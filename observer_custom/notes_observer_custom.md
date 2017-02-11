# Sorting Chapter 14 #

* 14.1, 14.2, 14.4, 14.6, 14.9

## Sorting Library Notes ##

*   Allocation & instantiating
    *   **algorithm header in c++11**: `#include <algorithm>`
        *   this includes `std::sort()`
        *   lists also include `list::sort()`
    *   Both `sort()` and `list::sort()` operate on arrays and lists of objects that implement `operator<()`

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

*  Design an algorithm that takes as input a set of intervals and outputs their union expressed as a set of disjoint intervals
*  **Input:** list of intervals (left point, right point). Points can be open or closed.
*  **Output:** List of disjoint intervals

`std::vector<Interval> ComputeIntervalUnions(std::vector<Interval> intervals);`


**14.9 Implement a Fast Sorting Algorithm for Lists**

*  Implement a routine which sorts lists efficiently. It should be a stable sort, i.e. the relative positions of equal elements must remain unchanged


`std::shared_ptr<ListNode<int>> StableSortList(std::shared_ptr<ListNode<int>> L);`

