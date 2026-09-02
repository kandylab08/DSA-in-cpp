# Day 38 — Majority Element

## 🧩 Problem

**LeetCode 169 — Majority Element**

Given an integer array `nums`, find the element that appears **more than `n / 2` times**.

The problem guarantees that a majority element always exists.

---

## 💡 Approach

Used the **Boyer–Moore Voting Algorithm**.

The idea is to maintain:

* `candidate` → current possible majority element
* `count` → its voting balance

For every element:

1. If `count` becomes `0`, select the current element as the new candidate.
2. If the current element matches the candidate, increase `count`.
3. Otherwise, decrease `count`.

Since the majority element appears more than half of the array, it cannot be completely cancelled out by the other elements.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## 🧠 Key Takeaway

The **Boyer–Moore Voting Algorithm** is an efficient technique for finding a majority element without using extra memory.

Instead of storing frequencies, elements are allowed to **cancel each other out**, leaving the majority element as the final candidate.

---

## 🚀 Day 38 Status

**Completed ✅**

**Algorithm Learned:** Boyer–Moore Voting Algorithm

**Difficulty:** Easy 🟢