# Recursion Chapter 16 #

* 16.1, 16.2, 16.3, 16.4, 16.9

## Recursion Notes ##


---

## Recursion Exercises ##


**16.1: Towers of Hanoi**




**16.2: Generate all NonAttacking Placements of n-Queens**

*   A non-attacking placement of queens is one in which no two queens are in the same row, column, or diagonal
*   Write a program which returns all distinct non attacking placements of `n` queens on an `n x n` chessboard, where `n` is an input to the program
*   _Hint:_ If the first queen is placed a (i,j), where can the remaining queens definitely not be placed?

`std::vector<std::vector<int>> NQueens(int n)`


**16.3: Generate Permutations**

*   Write a program which takes as input an array of distinct integers and generates all permutations of that array. No permutation of the array may appear more than once




**16.4: Generate the Power Set**

*   The power set S is the set of all subsets of S, including both the empty set 0 and S itself. The power set of {0,1,2} is {Empty, {0}, } ... `to be continued`
*   Write a program that takes as input a set and returns its power set


**16.9: Implement a Sudoku Solver**

*   see chapter 6 sudoku problem 16
