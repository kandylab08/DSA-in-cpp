# Day 46 — Symmetric Tree 🌳

## Problem

**LeetCode #101 — Symmetric Tree**

Given the root of a binary tree, determine whether the tree is symmetric around its center.

A binary tree is symmetric if its left and right subtrees are **mirror images** of each other.

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(h)`

Where:

* `n` = number of nodes
* `h` = height of the tree due to the recursive call stack

---

## Concepts Learned

* Binary Trees
* Recursion
* Mirror Trees
* Tree Traversal
* Comparing opposite subtrees
* Base cases with `nullptr`
* Recursive problem decomposition

---

## Key Learning

The main difference between **Same Tree** and **Symmetric Tree** is how the child nodes are compared.

**Same Tree:**

```text
left  ↔ left
right ↔ right
```

**Symmetric Tree:**

```text
left  ↔ right
right ↔ left
```

This helped me understand how recursion can be adapted to solve variations of the same tree-comparison problem.

---

**Day 46 — Completed ✅**