# Day 37 — Linked List Cycle

**LeetCode 141 — Linked List Cycle**

## 🧩 Problem

Given the head of a singly linked list, determine whether the linked list contains a cycle.

Return `true` if a cycle exists, otherwise return `false`.

## 💡 Approach

Used **Floyd's Cycle Detection Algorithm (Tortoise and Hare)**.

* `slow` moves one node at a time.
* `fast` moves two nodes at a time.
* If a cycle exists, `fast` will eventually meet `slow`.
* If `fast` reaches `nullptr`, there is no cycle.

## 🧠 Key Insight

When two pointers move at different speeds through a cyclic structure, the faster pointer will eventually catch up to the slower pointer.

This is also known as the **Tortoise and Hare algorithm**.

## ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

## 🛠️ Concepts Practiced

* Linked Lists
* Two Pointers
* Fast & Slow Pointers
* Floyd's Cycle Detection Algorithm

## ✅ Result

Solved successfully on the **first attempt** with optimal time and space complexity.

**Day 37 completed! 🔥**