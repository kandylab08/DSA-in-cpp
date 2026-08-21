# 🚀 Day 27 — Kth Smallest Element in a Sorted Matrix

## 🧩 Problem

Given an `n x n` matrix where each row and each column is sorted in ascending order, return the **kth smallest element** in the matrix.

### Example

```text
Input:
matrix =
[
  [ 1,  5,  9],
  [10, 11, 13],
  [12, 13, 15]
]

k = 8

Output:
13
```

---

## 💡 Approach 1 — Multimap

My first approach was to insert every matrix element into a `multimap`.

Since `multimap` keeps its elements sorted, I could repeatedly remove the largest elements until the kth smallest element remained.

### Complexity

* **Time:** `O(n² log n)`
* **Space:** `O(n²)`

Although this approach works, it does not take advantage of the fact that the matrix is already sorted by rows and columns.

---

## 🚀 Approach 2 — Binary Search on Answer

The optimized approach uses **Binary Search on the Answer**.

The smallest possible answer is:

```cpp
matrix[0][0]
```

The largest possible answer is:

```cpp
matrix[n - 1][n - 1]
```

For every `mid`, we count how many elements in the matrix are less than or equal to `mid`.

### Decision

If:

```text
count >= k
```

then the kth smallest element can be `mid` or smaller.

So we search the left half.

Otherwise, we search the right half.

---

## 🔍 Counting Elements ≤ Target

To count efficiently, start from the **bottom-left corner**.

```text
      columns →
    1   5   9
   10  11  13
   12  13  15
   ↑
 start here
```

If the current element is `<= target`:

* Everything above it in that column is also `<= target`.
* Add `r + 1` elements.
* Move right.

If the current element is `> target`:

* Everything to its right in that row is also `> target`.
* Move upward.

This allows the entire matrix to be counted in `O(n)` time.

---

## 🧠 Algorithm

1. Set `low = matrix[0][0]`.
2. Set `high = matrix[n-1][n-1]`.
3. Binary search between `low` and `high`.
4. Calculate `mid`.
5. Count elements `<= mid` using the bottom-left traversal.
6. If the count is at least `k`, search the left half.
7. Otherwise, search the right half.
8. Return `low`.

---


## ⏱️ Complexity Analysis

For an `m x n` matrix:

### Time Complexity

Binary search over the value range:

```text
O(log(maxValue - minValue))
```

Counting elements for each `mid`:

```text
O(m + n)
```

Therefore:

```text
O((m + n) log(maxValue - minValue))
```

For an `n x n` matrix:

```text
O(n log(maxValue - minValue))
```

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## 🎯 Key Takeaways

* A sorted matrix does **not** always require flattening or storing all elements.
* Binary Search can be performed over the **answer/value range**, not just array indices.
* The bottom-left corner provides an efficient way to count elements `<= target`.
* If `count >= k`, move left.
* If `count < k`, move right.
* Always look for ways to exploit the structure of the input instead of immediately reaching for a data structure.

---

## 🏆 Day 27 Status

**Problem:** Kth Smallest Element in a Sorted Matrix
**LeetCode:** 378
**Topic:** Binary Search on Answer
**Difficulty:** Medium
**Status:** ✅ Solved

### 🔥 Progress

```text
Initial Approach
      ↓
Multimap
O(n² log n)
      ↓
Recognized Sorted Matrix Property
      ↓
Binary Search on Answer
      ↓
Bottom-Left Matrix Traversal
      ↓
O(n log V), O(1)
```

**Day 27 completed. Another one in the books. 🚀**
