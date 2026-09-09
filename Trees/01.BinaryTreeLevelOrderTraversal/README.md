# Day 42 – Binary Tree Level Order Traversal 🌳

## 🧩 Problem

**LeetCode #102 – Binary Tree Level Order Traversal**

Given the root of a binary tree, return the level-order traversal of its nodes' values.

Level-order traversal visits nodes **level by level from left to right**.

### Example

```text
        3
       / \
      9   20
         /  \
        15   7
```

Output:

```text
[[3], [9, 20], [15, 7]]
```

---

## 💡 Approach

I used **Breadth-First Search (BFS)** with a queue.

1. If the root is `nullptr`, return an empty result.
2. Push the root into a queue.
3. While the queue is not empty:

   * Store the current queue size in `levelSize`.
   * `levelSize` tells us exactly how many nodes belong to the current level.
   * Process those nodes one by one.
   * Store their values in `currentLevel`.
   * Add their left and right children to the queue.
4. Add `currentLevel` to the final result.
5. Repeat until all nodes are processed.

### Key Idea

```cpp
int levelSize = q.size();
```

Instead of assuming that every level contains `1, 2, 4, 8...` nodes, using the current queue size allows the algorithm to work with **any binary tree**, including incomplete and unbalanced trees.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
  Each node is visited exactly once.

* **Space Complexity:** `O(n)`
  The queue and result can require `O(n)` space in the worst case.

---

## 🧠 What I Learned

* Implemented **BFS on a binary tree**.
* Learned how a **queue** naturally supports level-order traversal.
* Learned to use `q.size()` to identify the boundary of each level.
* Understood why assuming `2^n` nodes per level does not work for arbitrary binary trees.
* Started the **Trees** section of my DSA journey. 🌳

---

## 🚀 Day 42 Status

**Problem Solved:** ✅
**LeetCode:** #102
**Topic:** Binary Trees / BFS
**Difficulty:** Medium
**Language:** C++

**Day 42 completed! 🔥**