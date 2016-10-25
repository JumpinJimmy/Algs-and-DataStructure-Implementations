# Searching #
Page 169 of Elements of Programming Interviews

*   **Exercises:**12.1, 12.3, 12.4, 12.5, 12.8, 12.9, 12.10

---

## Searching Notes ##

*   Is the underlying collection static or dynamic (inserts and deletes are interleaved?)
*   Is it worth spending computational cost to pre-process the data so as to speed up the subsequent queries?
*   Do statistical properties exist that can be exploited?
*   Do we operate directly on the data or transform it?

**Generalized Search Problems**

*  Search problems that focus on the trade-offs between RAM and computation time
*  They avoid wasted comparisons when searching for the minimum and maximum simultaneously
*  Use Randomization to perform elimination efficiently
*  use bit level manipulations to identify missing elements etc.

---

**12.1: Search a sorted array for First occurrence of K**

*   Write a method that takes a sorted array and a key.
*   Return the index of the first occurrence of that key in the array
*   What happens when every entry equals k?
*   _hint:_ don't stop when you first see k
*   Example Input Array: -14,-10,2,108,108,243,285,285,401
*   Example Input Key: 108
*   Example Result: 3

`int SearchFirstOfK(const vector<int> &A, int k)`

---

**12.3: Search a Cyclically Sorted Array**

*   An array is said to be cyclically sorted if it is possible to cyclically shift its entries so that it becomes sorted.
*   Design and O(log n) algorithm for finding the position of the smallest element in a cyclically sorted array.
*   Assume all elements are distinct
*   Return the index of the smallest element

`int SearchSmallest(const vector<int> &A)`

---

**12.4: Compute the Integer Square Root**

*   Write a program which takes a nonnegative integer and returns the largest integer whose square is less than or equal to the given integer. 
*   E.g.) If the input is 16 return 4
*   E.g.) If input is 300, return 17

`int IntegerSquareRoot(int k)`

---

**12.5: Compute the Real Square Root**

*   x

`shared_ptr<ListNode<T>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)`

---

**12.8: Find the Kth Largest Element**

*   Compute the kth largest element in an array
*   Assume array elements are distinct
*   Example INput: `A[3,2,1,5,4]`
    *   `A[3]` is the first largest element
    *   `A[2]` is the fifth largest element
    *   `A[0]` is the third largest element

`int FindKth(int k, std::vector<int> *list_ptr)`

---

**12.9: Find the Missing IP address**

*   

``

---

**12.10: Find the Duplicate and Missing Elements**

*   Given an array of n integers each between 0 & n - 1 inclusive
*   Exactly one element appears twice.
*   This implies that exactly one number between 0 and n-1 is missing 
*   How would you compute the duplicate and missing numbers

``

---