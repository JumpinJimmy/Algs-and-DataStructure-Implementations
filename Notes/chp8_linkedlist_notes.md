## Merge Two Sorted Linked lists ##

**Psuedo Approach**
*  maintain a temporary result list 
*  Maintain a Tail pointer starting at the beginning of the temporary result list
*  append the smaller of the two list nodes (from L1 & L2) to the temporary result list via the tail
*  return first node of the temporary list

---

## Reverse a Single Sublist ##

Reverse a sublisgt within a list
*   Write a program which takes a singly linked list L and two integers S and F as arguments
*   Reverse the order of the nodes from S to F Inclusive


**Psuedo Approach**

*   Maintain a temporary sublist with a Header pointer starting at the predecessor of Start (start index - 1)
*   Maintain a sublist iterator starting at the Header's next (aka at Start index)
*   While start count < finish value
*   Maintain a temp pointer to the sublist iterator's next 
*   update sublist iterator's next to temp's next
*   update temp's next to the Header's next
*   update Headers next to Temp

**more explanation**

*   Basically: Maintain a pointer to the node before the actual sublist and then to the start of the actual sublist
*   the temporary pointer will begin each iteration at actual sublist start's next
*   the actual sublist start's next will be updated to the temps next
*   the temporary's next will then be updated to the node before the actual sublists next
*   the node before the actual sublist will have its next field updated to the temporary pointer 
*   Sublist iter will always point to the beginning of the list, while the temporary node pointer will move around each iteration 

---

## Test for A Cycle ##

*  Given the head of a singly linked list
*  Return Null if no cycle exists
*  Return the node at the start of the cycle if a cycle exists
*  You do not know the lenght of the list in advance

---

*   slow and fast pointer
*   while fast is not null and fast .next is not null
*   advance slow by one, advance fast by two
*   if no cycle, fast.next will eventually be null (or fast itself)
*   if slow = fast there is a cycle
    -   advance fast by one around until it meets slow again
    -   maintain number of iterations
    -   create cycle finder node tmp from head, and move it forward the number of iterations found via fast reloop
    -   create new head iter 
    -   while head iter != cycle finder
        -   move forward by one for each
    -  return head iter

--- 

## Cycle Alternate ##

*   fast and slow node from head of list
*   advance slow by one and fast by two
*   if they equal:
    *   set slow back to head of list
    *   move both fast and slow by one until they meet
    *   they will meet at the beginning of the cycle






