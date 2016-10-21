# Heaps #
Page 158 of Elements of Programming Interviews

*   **Exercises:** 11.1  11.3  11.4  11.5

## Heap Notes ##

---

11.1 Merge Sorted Files

Write a program that takes as input a set of sorted sequences and computes the union of these sequences as a sorted sequence.

For Example, if the input is `<3,5,7>` `<0,6>`and `<0,6,28>`. Then the outpu is `<0,0,3,5,6,6,7,28>`

foreach (sublist : sortedlists) {
    if (!sublist.empty()) {
        put first element of sublist into minheap
    }
}

Once the Minheap has the smallest(first) element of each sublist
start building output sequence while adding next items of the sublists to the heap

while (heap not empty) {
    auto smallest = heap.top
    if (smallest != end of the list) {
        result->emplace(smallest-curr)
        heap.emplace (smallest -> next  )
    }
}
return result


---

11.3   Sort and Almost Sorted Array

Write a program which takes as input a very long sequence of numbers and prints the numbers in sorted order. 

Input: stream of numbers and int k

void SortPartiallySortedData(istringstream* sequence, int k)

---

11.4 Compute the K CLosest Stars

---

11.5 Compute the median of Online Data