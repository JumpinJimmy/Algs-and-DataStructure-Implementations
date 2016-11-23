Pg 187 EPI

# Hash Tables #

*   **bootcamp exercises:** 13.2, 13.3, 13.6

---

## Notes on Hashtables ##

*   Store objects according to their key field in an array via hash code
*   **If** the **hash function is chosen well**, the **objects are distributed uniformly**
*   **Dealing with collisions**:  Standard pratice is to maintain a linked list of objects at each array location
*   **Average Lookup, Insertion and Deletion:** have `O(1+n/m)` time complexity
*   **Rehashing is Expensive** (O(n+m) time)
    *   if done infrequently the amortized cost is low
*   Hash tables are more efficient thatn BSTs on average
*   **Hash Function MUST** produce the same hash for equal keys
*   Hash codes should be uniformly distributed
*   Hash function should be efficient to compute
*   **Updating a Key**:
    *   Remove it,
    *   Update it
    *   Add it back
*   Avoid using mutable objects as keys

<!-- hash<string>() ()? -->

---