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

`ret x(type in)`


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

**9.3: Test a string over "{,},(,),[,]" for Well-Formedness**

*   A string over the characters  "{,},(,),[,]" is said to be well-formed if the different types of brackets match in the correct order


`ret x(type in)`

---

### Queues ###

**9.7: Compute Binary Tree Nodes in Order of Increasing Depth**

*   x

`ret x(type in)`

---

**9.8: Implement a Circular Queue**

*   x

`ret x(type in)`

---

**9.9: Implement a Queue Using Stacks**

*   x

`ret x(type in)`

s