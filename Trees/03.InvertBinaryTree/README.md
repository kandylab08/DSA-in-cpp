# Day 44 — Invert Binary Tree 🌳

## Problem

Given the root of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping the left and right child of every node.

### Example

**Input:**

```text
       4
      / \
     2   7
    / \ / \
   1  3 6  9
```

**Output:**

```text
       4
      / \
     7   2
    / \ / \
   9  6 3  1
```

## Solution

I solved this problem using **Breadth-First Search (BFS)** with a queue.

For every node:

1. Remove the node from the queue.
2. Swap its left and right children.
3. Add the updated children to the queue.
4. Continue until all nodes have been processed.

## Complexity

* **Time Complexity:** `O(n)` — every node is visited once.
* **Space Complexity:** `O(n)` — the queue can contain up to `O(n)` nodes in the worst case.

## Concepts Learned

* Binary Trees
* Breadth-First Search (BFS)
* Queue-based tree traversal
* Swapping left and right child nodes
* Modifying a tree in-place
* Comparing BFS and DFS approaches

## Key Learning

A binary tree can be inverted simply by swapping the left and right child of **every node**.

This problem also reinforced the difference between **BFS and DFS**. The same problem can be solved using either traversal technique.