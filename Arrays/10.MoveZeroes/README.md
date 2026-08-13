# 🚀 Day 19 — Move Zeroes

## 🧩 Problem

Given an integer array `nums`, move all `0`s to the end of the array while maintaining the relative order of the non-zero elements.

The solution must modify the array **in-place**.

### Example

```text
Input:  [0,1,0,3,12]
Output: [1,3,12,0,0]
```

---

## 💡 Approach

I explored multiple approaches before arriving at the optimal solution.

### 1. Brute Force — Swapping

Initially, I tried finding zeroes and swapping them with elements on the right.

* Works in many cases.
* Uses constant extra space.
* But requires nested loops.
* Time Complexity: **O(n²)**

### 2. Erase + Push

I also tried removing each zero using `erase()` and pushing it to the end.

* Conceptually simple.
* Maintains the relative order.
* However, `vector::erase()` shifts subsequent elements.
* Time Complexity: **O(n²)** in the worst case.

### 3. Optimal — Two Pointer / Compaction

The final solution uses two indices:

* `i` scans the entire array.
* `j` keeps track of where the next non-zero element should be placed.
* After placing all non-zero elements, the remaining positions are filled with `0`.

This avoids unnecessary shifting and achieves linear time.

---

## 🔍 Key Insight

Instead of physically moving every zero to the end, we can:

1. Copy every non-zero element toward the front.
2. Keep track of the next available position using `j`.
3. Fill the remaining positions with zeroes.

The important idea is:

> **`i` searches for non-zero elements, while `j` places them.**

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`
* **In-place:** Yes
* **Relative order preserved:** Yes

---

## 🧠 What I Learned

* How to use two pointers for array manipulation.
* Why `vector::erase()` can make an approach inefficient.
* How to separate searching from placement.
* How an `O(n²)` idea can be improved to `O(n)`.
* Most importantly: **keep showing up, even on tired days.** 🔥

---

## 💻 Final Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }

        for (int i = j; i < n; i++)
        {
            nums[i] = 0;
        }
    }
};
```

---

## 🏁 Day 19 Status

**Problem:** Move Zeroes
**Difficulty:** Easy
**Pattern:** Two Pointers / Array Manipulation
**Time:** `O(n)`
**Space:** `O(1)`
**Status:** ✅ Completed

> **19 days. Still going. 🔥**
