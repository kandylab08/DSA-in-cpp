# 🚀 Day 36 — DSA Challenge

## 🧩 Problem Solved

**LeetCode 136 — Single Number**

### 📌 Problem Statement

Given a non-empty array of integers `nums`, every element appears **twice** except for one element that appears exactly once.

Return the element that appears only once.

### 💡 Approach

I used the **XOR (Bitwise Exclusive OR)** operation.

The key properties of XOR are:

```text
x ^ x = 0
x ^ 0 = x
```

Since every number except one appears exactly twice, XORing all elements causes the duplicate numbers to cancel each other out.

For example:

```text
Input: [4, 1, 2, 1, 2]

0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2

= 4 ^ (1 ^ 1) ^ (2 ^ 2)

= 4 ^ 0 ^ 0

= 4
```

Therefore, the remaining value is the number that appears only once.

### ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

### 🧠 Key Takeaway

XOR is extremely useful when dealing with numbers that occur in pairs.

Instead of using a hash map or sorting the array, XOR allows us to find the unique element in **one pass with constant extra space**.

### 🏆 Day 36 Status

* [x] Problem solved
* [x] XOR approach implemented
* [x] Optimal `O(n)` solution
* [x] `O(1)` extra space
* [x] DSA streak continues 🔥

> **Day 36 — Two problems, two different techniques, and still moving forward. 🚀**
