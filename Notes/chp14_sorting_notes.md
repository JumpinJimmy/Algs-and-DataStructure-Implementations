## Sorting Notes ##
_Chapter 14 Pages 211 - 212_

---

*   xxxx

---

### Merge Two Sorted Arrays ###


*   Input:  Two Arrays, Array 1 is large enough to hold the merge result
*   Both arrays are already sorted
*   You are given the length of both arrays (length == number of valid contents , not empty indexes)


```

MergeSorted(std::array<in> A1, int size_1, std::array<int> A2, int size_2) {
    int write_pos = size_1 + size_2 - 1;
    int read_1 = size_1 - 1;
    int read_2 = size_2 - 1;

    while (read_1 >= 0 && read_2 >= 0) {
        A1[write_pos] = A1[read_1] >= A2[read_2] ? A1[read_1--] : A2[read_2--];
        write_pos++;
    }
    while (read_2 >= 0) {
        A1[write_pos] = A2[read_2--];
    }
}

```
*   time complexity is O(m+n) and uses O(1) additional space

