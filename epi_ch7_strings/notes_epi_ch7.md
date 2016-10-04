# Strings #
Page 85 of Elements of Programming Interviews

*   **Exercises:** 7.1, 7.2, 7.4, 7.5, 7.6, 7.7*, 7.8*

**7.1: Inter-convert Strings and Integers**

`string IntToString(int x)`

`int StringToInt(string s)`

---

**7.2: Base Conversion**

_TODO_

---

**7.4: Replace and Remove**

*   Write a function which takes in an array of characters and an integer denoting the number of entries the operation applies to.
*   Replace all `a`'s with two `d`'s
*   remove all `b`'s

`int ReplaceAndRemove(char s[], int size)`

---

**7.5: Test Palindrome**

*   Implement a function which takes as input a string and returns true if it is a palindromic string

`bool IsPalindromic(std::string &in_str)`

---

**7.6: Reverse all words in a Sentence**

*   given a string containing a set of words separated by whitespace, we would like to transform it into a string in which the word appear in the reverse order
*   Ex). "I like Pizza"  Reversed: "Pizza like I "

`void ReverseWords(std::string *sentence)`

---

**7.7: Phone Mnemonics**

*   Write a program which takes as input a phone number, specified as a string of digits and returns all possible character sequences that correspons to the phone number
*   Each digit, apart from **0** and **1**, corresponds to one of three or four letters of the alphabet
*   IN: string phone number 
*   OUT: list of all possible character sequences for the number
*   example:  in(2276696), out(ACRONYM, ABPOMZN, ...)

`std::vector<std::string> PhoneMnemonics(const std::string &phone_number)`

---

**7.8: The Look-and-Say Problem**

*   x