# 🧱 Min Stack — LeetCode 155

## 📌 Problem

Design a stack that supports the following operations in **O(1)** time:

* `push(val)` — Push an element onto the stack.
* `pop()` — Remove the element on top of the stack.
* `top()` — Get the element on top of the stack.
* `getMin()` — Retrieve the minimum element in the stack.

---

## 💡 Approach

Use **two stacks**:

1. `stck` → stores all the elements normally.
2. `min_stck` → stores the minimum value at every position.

Whenever a new value is pushed:

* Push it into `stck`.
* Compare it with the current minimum.
* Store the smaller value in `min_stck`.

For example:

```text
Operation:     push(5) push(3) push(7) push(2)

stck:             5     5 3     5 3 7     5 3 7 2
min_stck:         5     5 3     5 3 3     5 3 3 2
```

Therefore, the current minimum is always available at:

```cpp
min_stck.back()
```

When an element is popped, both stacks are popped so that their positions remain synchronized.

---

## 🔍 Algorithm

### `push(value)`

1. Push `value` into `stck`.
2. If `min_stck` is empty, push `value`.
3. Otherwise, push the minimum of:

   * `value`
   * current minimum `min_stck.back()`

### `pop()`

1. Check whether the stack is empty.
2. Remove the top element from both stacks.

### `top()`

Return the last element of `stck`.

### `getMin()`

Return the last element of `min_stck`.

---

## ⏱️ Complexity Analysis

| Operation  | Time Complexity |
| ---------- | --------------: |
| `push()`   |            O(1) |
| `pop()`    |            O(1) |
| `top()`    |            O(1) |
| `getMin()` |            O(1) |

### Space Complexity

**O(n)** — Two stacks are maintained, each potentially containing `n` elements.

---

## 🧠 Key Takeaway

The main idea is to **store additional information alongside the original data** so that expensive operations become constant time.

Instead of searching the entire stack whenever `getMin()` is called, the minimum value is maintained continuously in `min_stck`.

### Pattern Learned

> **Auxiliary Data Structure / Maintaining State**

This pattern is useful when we need additional information about a data structure without repeatedly scanning it.

---

## 🏆 LeetCode

**Problem:** [155. Min Stack](https://leetcode.com/problems/min-stack/)

**Difficulty:** Medium

**Topic:** Stack

**Day:** 16
