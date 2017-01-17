# Hashing & Hash Tables#
Page 187 of Elements of Programming Interviews

*   **Exercises:** 13.1 13.2 13.3 13.4* 13.6 13.7*

---

**13.1: Test for Palindromic Permutations**

*   Test whether the letters forming a string can be permuted to form a palindrome
    *   **e.g.** "edified" can be changed to "deified"

`bool PermuteToPalindrome(const std::string &subject_string);`

---

**13.2: Is an Anonymous Letter Constructible?**

*   Write a program that takes text fro an anonymous letter and text for a magazine. Determine if it is possible to write the anonymous letter using the magazine. 

---

**13.3: Implement an ISBN Cache**

*   Create a cache for looking up prices of books identified by their ISBN
*   **Support**: `Lookup`, `Insert`, and `Remove` methods
*   Use the **Least Recently Used (LRU) policy** for cache eviction
*   **Insertion If an ISBN is already present:**
    *   insert should not change the price
    *   should update it to be the most recently used
*   **Lookup:**
    *   should also update that entry to the most recently used.
*   _Hint:_ amortize the cost of deletion. Alternatively, use an auxiliary data structure

*   **ISBN:** string of length 10
    *   first 9 characters are digits
    *   the last character is a check character
    *   **Check Character:** sum of first nine digits, mod 11
    *   Value of 10 is represented with an X


---

**13.4: x**

---

**13.6: Find Nearest Repeated Entries**

*   Given an array of strings, find the distance between the closest pair of equal entries. 
*   Return the distance 

*   **Examples:**
    *   `All work and no play makes for no work no fun and no results` - the second and third `no` strings are the closest

`int ShortestEqualValueDistance(const std::vector<std::string> &str_list)`

---

**13.7: Find Shortest Sub-Array**

*   Write a program which takes an array of strings and a set of strings.
*   Return the indices for the starting index and ending index indicating the shortest sub array that contains all elements within the set  

`std::pair<int,int> RetreiveContainingSubarraryIndex(std::vector<std::string> content_array, std::set<std::string> search_keys)`


