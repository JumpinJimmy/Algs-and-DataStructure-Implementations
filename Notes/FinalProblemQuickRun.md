

# 9.7: Compute Binary Tree Nodes in Order of Increasing Depth#

*   If each node in a binary tree has a depth indicating its distance from the root
*   Given a binary tree, return an array consisting of the keys at the same level
*   Keys should appear in the order of the corresponding nodes' depths, breaking ties from left to right

`vector<vector<int>> BSTDepthOrder(const unique_ptr<TreeNode<int>>& tree)`

### Code Here ###

```
// Result vector<vector<in>> results;
// level vector<int> curr_level
// Preorder traversal using Queue 
// maintain number of nodes to print per level

BSTDepthOrder(const unique_ptr<TreeNode<int>>& tree) {
    if (!tree) {
        return {};
    }
    std::vector<vector<int>> result_list;
    std::vector<int> curr_level;
    std::queue<TreeNode> traversal_q;
    int num_nodes_print = 1;
    traversal_q.emplace(tree);
    while (!traversal_queue.empty()) {
        TreeNode curr = traversal_q.front();
        traversal_q.pop();
        num_nodes_print--;
        if (curr) {
            curr_level.emplace_back(curr.data);
            traversal_q.emplace(curr.left);
            traversal_q.emplace(curr.right);
        }
        if (!num_nodes_print) {
            result_list.emplace_back(move(curr_level));
            num_nodes_print = traversal_q.size();
        }
    }
    return result_list;
}


```

---



# 10.1 Test if a Binary Tree is Height Blanaced #

*   Given the root of a binary tree
*   check whether or not the tree is height balanced
*   a tree is height balanced if the difference in the height of its left and right subtrees is at most one

`boolean IsHeightBalanced(unique_ptr<TreeNode<int>>& tree)`

### Code Here ###
```
//Helper Struct

struct BalanceData {
    bool balanced
    int height
}
boolean IsHeightBalanced(unique_ptr<TreeNode<int>>& tree) {
    return BalanceHelper(tree).balanced
}

BalanceData BalanceHelper(Tree Node) {
    if (node == null) { return true, -1}
    BalanceData LeftRes = BalanceHelper(Node.left) 
    if (!leftRes.balanced) return false 0

    BalanceData RightRes = BalanceHelper(Node.right)
    if (!RightRes.balanced) return false 0

    bool balanced = abs(leftRes.height - rightRes.height) <= 1
    int height = max(leftRes.height, rightRes.height) + 1
    return balanced,height
    }
}
// Hi

```

# 12.4 Compute The integer Square Root #

*  Given a none negative integer
*  return the largest integer whose square is less than or equal to the given Integer
*  ex) if the input is 16, return 4. If the input is 300, return 17. Because 17 squared == 289 and 18 squared is 324 (too large)

`int LargestSquare(int value)`

### Code Here ###

```

int LargestSquare(int value) {
    SquareRoot(0,value,value);
}

int SquareRoot(left, right, target) {
    if (left == right) return left;
    int mid = left + ((right - left) / 2);
    int midsquare = mid * mid;
    if(midsquare > targ) {
        SquareRoot(left, mid-1, target);
    } else if (midsquare < target) {
        SquareRoot(mid +1, target, target )
    } 
}

```

---

# 13.2 Is an Anonymous Letter Constructable #

*  **Input:** text for an anonymous letter
*  **Input:** text for a magazine
*  **Return:** Boolean - can the anonymous letter be written using only magazine text

*   TRUE: if # of appearances for each char in anonymous letter <= # of appearances that char appears in the magazine
*   Hint: count the number of distinct characters appearing in the letter

`bool CanConstruct(string letter, string magazine)`

### Code Here ###

```

std::unordered_map<char, int> anon_char_map;
for(char c : anon_letter) {
    auto char_val = anon_char_map.find(c);
    if (char_val != anon_char_map.end()) {
        char_val.second ++
    } else {
        anon_char_map.emplace(c, 1);
    }
}
for(char c: magazine) {
    auto char_val = anon_char_map.find(c);
    if (char_val != anon_char_map.end()) {
        char_val.second--;
        if (char_val.second <= 1) {
            anon_char_map.erase(c)
        }
    }
    if (anon_char_map.empty()) {
        return true
    }
}
return anon_char_map.empty();

```

---


# 7.6 Reverse All Words in the Sentence #


*   given a string containing a set of words separated by whitespace, we would like to transform it into a string in which the word appear in the reverse order
*   Ex). "I like Pizza"  Reversed: "Pizza like I "

`void ReverseWords(std::string *sentence)`


```



```

---