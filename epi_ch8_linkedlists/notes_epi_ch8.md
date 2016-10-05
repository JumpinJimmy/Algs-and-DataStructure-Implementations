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

*   x

---

**8.3: Test for Cycles**

*   x

`int ReplaceAndRemove(char s[], int size)`

---

**8.4: Test for Overlapping Lists**

*   x

`bool IsPalindromic(std::string &in_str)`

---

**8.7: Remove the Kth Last Element from a List**

*   x

`void ReverseWords(std::string *sentence)`

---

**8.10: Implement Even-Odd Merge**

*   x

`std::vector<std::string> PhoneMnemonics(const std::string &phone_number)`

