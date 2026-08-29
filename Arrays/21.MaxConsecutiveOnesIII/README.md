# Day 34 — Max Consecutive Ones III

## 🧩 Problem

**LeetCode 1004 — Max Consecutive Ones III**

Given a binary array `nums` and an integer `k`, find the maximum number of consecutive `1`s that can be obtained by flipping at most `k` zeros.

---

## 💡 Approach

I used the **Sliding Window** technique.

The idea is to maintain a window `[left ... right]` containing at most `k` zeros.

* Expand the window by moving `right`.
* Whenever `nums[right]` is `0`, increment `zeroCount`.
* If `zeroCount > k`, the window becomes invalid.
* Shrink the window from the left until the number of zeros is at most `k`.
* For every valid window, calculate its length and update `maxLen`.

### Key Observation

The only information that matters is the **number of zeros** in the current window.

There is no need to maintain a frequency array for both `0` and `1`.

---

## 🔑 Algorithm

1. Initialize:

   * `left = 0`
   * `zeroCount = 0`
   * `maxLen = 0`
2. Iterate through the array using `right`.
3. If `nums[right] == 0`, increment `zeroCount`.
4. While `zeroCount > k`:

   * If `nums[left] == 0`, decrement `zeroCount`.
   * Move `left` forward.
5. Update:

   ```cpp
   maxLen = max(maxLen, right - left + 1);
   ```
6. Return `maxLen`.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

Although there is a nested `while` loop, both `left` and `right` move only forward, so every element is processed a constant number of times.

---

## 🧠 What I Learned

* Recognized another application of the **Sliding Window** pattern.
* Learned to identify an **invalid window** using `zeroCount > k`.
* Practiced shrinking the window until it becomes valid again.
* Realized that maintaining only the information relevant to the constraint can simplify the solution.
* Optimized the initial frequency-array approach by tracking only the number of zeros.

### 🔥 Key Takeaway

> **Expand the window → detect when it becomes invalid → shrink it → record the maximum valid window.**

---

## 🏆 Day 34 Status

**Problem Solved:** ✅
**Approach:** Sliding Window
**Difficulty:** Medium
**Time:** `O(n)`
**Space:** `O(1)`

**Another day. Another pattern becoming clearer. 🚀**