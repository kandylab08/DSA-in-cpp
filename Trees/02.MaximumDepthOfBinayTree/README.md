# Day 43 — Maximum Depth of Binary Tree

**LeetCode:** 104 — Maximum Depth of Binary Tree
**Difficulty:** Easy
**Topic:** Binary Tree, BFS, DFS, Recursion

## Problem

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

---

## Approach 1 — BFS (Level Order Traversal)

Since each level of the tree represents one unit of depth, we can perform a level-order traversal using a queue.

For every level:

1. Store the current queue size.
2. Process all nodes in that level.
3. Add their children to the queue.
4. Increment the depth count.

The final number of levels is the maximum depth.

### Important Lesson

The current level size must be stored before processing:

```cpp
int levelSize = q.size();
```

Using `q.size()` directly as the loop condition can be incorrect because the queue changes when children are added.

### Complexity

* **Time:** O(n)
* **Space:** O(n)

---

## Approach 2 — DFS (Recursion)

For every node, calculate the maximum depth of its left and right subtrees.

The depth of the current node is:

```text
1 + max(left subtree depth, right subtree depth)
```

If the node is `nullptr`, its depth is `0`.

### Complexity

* **Time:** O(n)
* **Space:** O(h), where h is the height of the tree due to recursion.

---

## Concepts Learned

* Binary Tree traversal
* BFS (Breadth-First Search)
* DFS (Depth-First Search)
* Level Order Traversal
* Recursion
* Queue
* Recursive tree decomposition
* Relationship between tree height and maximum depth

## Key Takeaway

A tree can often be approached in two major ways:

* **BFS → Queue → Level by level**
* **DFS → Recursion/Stack → Go deep**

For this problem, BFS counts the number of levels, while DFS calculates the maximum depth of the left and right subtrees recursively.

## Mistake & Learning

Initially, `q.size()` was used directly in the `for` loop condition while also adding children to the queue.

This can cause nodes from the next level to be processed accidentally because the queue size changes during the loop.

**Lesson:** When processing a tree level with BFS, always store the initial queue size in a separate variable.