# 🚀 Day 30 — Minimum Size Subarray Sum

## 🧩 Problem

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length of a subarray** whose sum is greater than or equal to `target`.

If no such subarray exists, return `0`.

**LeetCode:** 209 — Minimum Size Subarray Sum

---

## 💡 Approach

For this problem, I used the **Sliding Window** technique.

The idea is to maintain a window using two pointers:

```text
[left ........ right]
```

* Move `right` forward to expand the window.
* Keep adding elements to `cur_sum`.
* Once `cur_sum >= target`, the current window is valid.
* Move `left` forward to shrink the window and try to find a smaller valid subarray.
* Keep track of the minimum window length.

The important observation is that all elements are **positive**, so removing an element from the left always decreases the sum.

---

## 🧠 Algorithm

1. Initialize:

   * `left = 0`
   * `cur_sum = 0`
   * `res = INT_MAX`

2. Move `right` from `0` to `n - 1`.

3. Add `nums[right]` to `cur_sum`.

4. While `cur_sum >= target`:

   * Update the minimum length.
   * Remove `nums[left]`.
   * Move `left` forward.

5. If `res` was never updated, return `0`; otherwise return `res`.

---

## 📊 Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

Although there is a `while` loop inside the `for` loop, the `left` pointer only moves forward. Therefore, every element is added and removed at most once.

---

## 📝 Example

```text
target = 7
nums = [2,3,1,2,4,3]
```

A valid window can be:

```text
[4,3]
```

Its sum is:

```text
4 + 3 = 7
```

and its length is:

```text
2
```

Therefore:

```text
Answer = 2
```

---

## 🔥 What I Learned Today

Today was an important step in my DSA journey.

Yesterday, while solving **Longest Substring Without Repeating Characters**, I independently came up with the idea of maintaining a moving range, even though I didn't know the formal name **Sliding Window**.

Today, I intentionally applied the same idea to a completely different problem and solved it correctly **on my first try**.

This helped me understand that Sliding Window is not just a memorized technique. It is a way of thinking:

> **Expand the window until the condition is satisfied, then shrink it to find the best valid window.**

The biggest lesson today:

**I'm slowly starting to recognize problem-solving patterns on my own instead of just memorizing solutions.** 🧠🔥

---

## 📈 Day 30 Progress

* ✅ Solved LeetCode 209
* ✅ Identified and implemented Sliding Window
* ✅ First-try correct solution
* ✅ `O(n)` optimized solution
* ✅ Strengthened two-pointer thinking
* ✅ Better understanding of maintaining a dynamic range

---

## 🏆 Day 30 Status

**SOLVED ✅**

> 30 days of consistency.
> The goal is no longer just solving problems — it's learning how to *think* about them. 🚀
