# Day 45 — Same Tree 🌳

## 🧩 Problem

**LeetCode 100 — Same Tree**

Given the roots of two binary trees `p` and `q`, determine whether the two trees are the same.

Two binary trees are considered the same if:

* They have the same structure.
* Corresponding nodes contain the same values.

---

## 💡 Solution

I used **recursion with DFS (Depth-First Search)** to compare both trees.

### Cases handled:

1. If both nodes are `nullptr`, they match.
2. If only one node is `nullptr`, the structures are different.
3. If both nodes exist:

   * Compare their values.
   * Recursively compare their left subtrees.
   * Recursively compare their right subtrees.

The trees are the same only when **all three conditions** are true.

---

## ⏱️ Complexity

* **Time:** `O(n)` — Each corresponding node is visited at most once.
* **Space:** `O(h)` — Due to the recursive call stack, where `h` is the height of the tree.

For a balanced tree: `O(log n)`
For a skewed tree: `O(n)`

---

## 🧠 Concepts Learned

* Binary Trees
* Recursive DFS
* Base cases in recursion
* Comparing tree structure
* Comparing corresponding node values
* Recursive comparison of left and right subtrees

---

## 🔥 Key Takeaway

A useful pattern for recursive tree problems is:

> **Check the current nodes → recursively solve the left subtree → recursively solve the right subtree.**

This problem helped reinforce the recursive DFS concept learned while solving **Maximum Depth of Binary Tree** on Day 43.

---

**Day 45 Complete! ✅**
**Next → Day 46 🚀**