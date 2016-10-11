# Linked Lists #
Page 100 of Elements of Programming Interviews

*   **Exercises:** 8.1, 8.2, 8.3, 8.4, 8.7, 8.10*

---

**8.1: Merge Two Sorted Lists**

*   Consider two singly linked lists in which each node holds a number. Assume the lists are sorted in ascending order. 
*   Write a function that takes the two sorted lists and returns their merge. The only data the function can change in the list structures is the "next" field

`shared_ptr<ListNode<T>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)`

_Rough Pseudo Code of my solution_

```
    // auto iter_1 = l1
    // auto iter_2 = l2
    // if (iter_1 == nullptr || iter_2 == nullptr) {
    //     // result_head->next = ()
    // }
    // while (iter_1 != nullptr && iter_2 != nullptr) {
    //     if (iter_1->data <= iter_2->data) {
    //         append(iter_1)
    //         if (iter_1 -> next != null) iter_1 = iter_1->next
    //         else iter_1=null
    //     } else {
    //         append(iter_2)
    //         if (iter_2 -> next != null) iter_2 = iter_2->next
    //         else iter_2=null
    //     }
    // }
    // iter_1 = (iter_2 == null) ? iter_1:iter_2
    // while (iter_1) {
    //     append(iter_1)
    //     iter_1 = iter_1->next
    // }
    // append(new node, tail)
    //    if (node)
    //      tail->next = node
    //      tail = tail->next
```

---

**8.2: Reverse a Single Sublist**

*   Write a program which takes a singly linked list **L** and two integers **start** & **finish** as arguments.
*   Reverse the order of the nodes from the start node to the finish node **inclusive**
*   Do not allocate additional nodes

`shared_ptr<ListNode<int>> ReverseSubList(int start, int finish,
                                         shared_ptr<ListNode<int>> orig_list);`

---

**8.3: Test for Cycles**

*   Write a function that takes the head of a singly linked list and returns null if no cycle exists. If a cycle exists, return the node at the start of the cycle.
*   You do not know the length of the list in advanced


`shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head);`

---

**8.4: Test for Overlapping Lists**

*   Write a program that takes two cycle free singly linked lists and determines if there exists a node that is common to both lists _(note: exercise 8.5 should be tried as well)_

`shared_ptr<ListNode<int>> CheckOverlapNoCycle(shared_ptr<ListNode<int>> list_a, shared_ptr<ListNode<int>> list_b)`

---

**8.7: Remove the Kth Last Element from a List**

*   Without knowing the length of a linked list, it is not trivial to delete the Kth to last element in a singly linked list.
*   Given a singly linked list and an integer k, write a program to remove the Kth last element from the list. Your algorithm cannot use more than a few words of storage regardless of list length. Basically, you cannot assume the length of the list can be recorded

`shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>> &L, int k)`

---

**8.10: Implement Even-Odd Merge**

*   Consider a singly linked list who nodes are numbered starting at 0
*   Define the even odd merge of the list to be the lists conisting of the ven numbered nodes followed by the odd numbered nodes. 
*   Compute the even-odd merge

`shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>> &L)`

