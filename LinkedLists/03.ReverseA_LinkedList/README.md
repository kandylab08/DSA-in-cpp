# 🚀 Day 39 — Reverse Linked List

**LeetCode #206 — Easy**

## 🧩 Problem

Given the head of a singly linked list, reverse the list and return the new head.

### Example

```text
Input:
1 → 2 → 3 → 4 → 5

Output:
5 → 4 → 3 → 2 → 1
```

## 💡 Approach

I used an **iterative three-pointer approach**:

* `prev` — stores the previous node.
* `cur` — points to the current node being processed.
* `temp` — temporarily stores the next node so the rest of the list isn't lost.

For every node:

1. Store the next node.
2. Reverse the current node's pointer.
3. Move `prev` forward.
4. Move `cur` forward.

At the end, `prev` points to the new head of the reversed list.

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

Each node is visited exactly once, and only a constant number of pointers are used.

## 🧠 Key Takeaway

The important idea is to **reverse each pointer one node at a time while keeping track of the next node**.

> Never lose the rest of the linked list when changing `cur->next`.

## 🏆 Day 39 Status

**Completed ✅**

Another day, another problem solved. 🔥

**DSA Streak: 39 Days 🚀**