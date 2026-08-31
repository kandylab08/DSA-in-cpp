# 🚀 Day 36 — DSA Challenge

## 🧩 Problem Solved

**LeetCode 268 — Missing Number**

### 📌 Problem Statement

Given an array `nums` containing `n` distinct numbers taken from the range `[0, n]`, return the **only number missing** from the range.

### 💡 Approach

I used the **mathematical sum formula**:

$$
\text{Sum} = \frac{n(n+1)}{2}
$$

The array should contain every number from `0` to `n`, so I first calculated the expected sum of all numbers.

Then, I subtracted every number present in the array from that sum.

The remaining value is the **missing number**.

### 🔍 Example

```text
Input:  [3, 0, 1]

Expected numbers: 0, 1, 2, 3
Expected sum = 6

Actual sum = 3 + 0 + 1 = 4

Missing number = 6 - 4 = 2
```

### ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

### 🧠 Key Takeaway

The problem can be solved without sorting or using extra data structures by comparing the **expected sum** of `0` to `n` with the values actually present in the array.

### 🏆 Day 36 Status

* [x] Problem solved
* [x] First attempt accepted
* [x] O(n) time complexity
* [x] O(1) extra space
* [x] DSA streak continues 🔥

> **Day 36 complete! One more step forward. 🚀**
