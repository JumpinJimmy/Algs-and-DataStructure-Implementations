# Stacks & Queues #
Page 117 of Elements of Programming Interviews

*   **Exercises:** 9.1, 9.2, 9.3*, 9.7, 9.8, 9.9*

## Stack Notes ##

*   A Stack supports two basic operations: `push` & `pop`
*   Elements are added(pushed) and removed(popped) in last-in, first-out order (LIFO)
*   When a stack is implemented using a linked list, these operations have 0(1) time complexity
*   If it is implemented using an array, there is a maximum number of entries it can have. 
*   If the array is dynamically resized, the amortized time for both push and pop is still 0(1).
*   A stack can support additional operations such as peek, which returns the top of the stack without popping it


---

### Stacks ###

**9.1: Implement a Stack with Max API**

*   Design a stack that includes a max operation, in addition to push and pop. The max method should return the maximum value stored in the stack


---

**9.2: Evaluate RPN Expressions**

*   a string is said to be an arithmetical expression in reverse polish notation (RPN) if:
*   it is a single digit or a sequence of digits, prefixed with an option 
    *   e.g. `"6"`, `"123"`, `"-42"`

*   it is of the form "`A`, `B`, `o`" where `A` and `B` are RPN expressions and `o` is one of the `+,-, x, /`

*   **The Following Strings Satisfy these rules:** `"1729"`, `"3,4,+,2,x,1+"`, `"1,1,+,-2,x"` , `"-641, 6, /, 28,/"`
*   Write a program that takes an arithmetical expression in RPN and returns the number that the expression evaluates to
    *   **Example Input:** `"3,4,+,2,x,1,+"`
    *   **Example Ouput:** `15`

`int EvaluateRPN(const string& RPN_expressi1on)`

---

**9.3: Test weather a String of bracket characters "{,},(,),[,]" is well-formed / balanced**

*   A string over the characters  "{,},(,),[,]" is said to be well-formed if if each open bracket has a corresponding closing bracket in the correct order

*   **Examples:**
    *   `"([]){()}"` is _well-formed_
    *   `"[()[]{()()}]"` is _well-formed_
    *   `"{)}"` is _malformed_
    *   `"[()[]{()()"` is _malformed_

*   Write a program that tests whether or not a string made-up of the characters `(`, `)`, `[`, `]`, `{`, `}` is well-formed

`bool IsWellFormedBrackets(const string& s)`

---

### Queues ###

**9.7: Compute Binary Tree Nodes in Order of Increasing Depth**

*   If each node in a binary tree has a depth indicating its distance from the root
*   Given a binary tree, return an array consisting of the keys at the same level
*   Keys should appear in the order of the corresponding nodes' depths, breaking ties from left to right

`vector<vector<int>> BSTDepthOrder(const unique_ptr<BinaryTreeNode<int>>& tree)`

---

**9.8: Implement a Circular Queue**

*   A queue can be implemented using an array and two additional fields. The beginning and the end indices.
*   This is usually referred to as a circular queue
*   Both enqueue and enqueue have 0(1) time complexity
*   If the array is fixed, there is a maximum number of entries that can be stored
*   If the array is dynamically resized, the total time for m combined enqueue and dequeue operations is O(m)

*   **Task:** Implement a queue API using an array for storing elements. The constructor should take in as an argument the initial capacity of the queue.
*   Include enqueue and dequeue functions and a function which returns the number of elements stored. 
*   Implement Dynamic resizing to support storing an arbitrarily large number of elements. 


---

**9.9: Implement a Queue Using Stacks**

*   How would you implement a queue given a library implementing stacks

