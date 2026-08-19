# 🚀 Day 25 — Split Array Largest Sum

## 🧩 Problem

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty contiguous subarrays.

The goal is to **minimize the largest sum among the `k` subarrays**.

Return the minimized largest sum.

### Example

```text
nums = [7, 2, 5, 10, 8]
k = 2
```

A possible optimal split is:

```text
[7, 2, 5] | [10, 8]
    14          18
```

The largest subarray sum is `18`.

Therefore, the answer is:

```text
18
```

---

## 💡 Approach

This problem can be solved using **Binary Search on Answer**.

Instead of directly finding the optimal split, we binary search for the smallest possible value of the **maximum allowed subarray sum**.

---

## 🔹 Step 1 — Determine the Search Range

The minimum possible answer must be at least the **largest element** in the array.

```cpp
low = max(nums)
```

The maximum possible answer is the **sum of all elements**, which corresponds to putting the entire array into one subarray.

```cpp
high = sum(nums)
```

Therefore:

```text
low  = maximum element
high = total sum
```

---

## 🔹 Step 2 — Feasibility Check

For a given `mid`, we ask:

> Can the array be split into at most `k` subarrays such that no subarray has a sum greater than `mid`?

We greedily add elements to the current subarray.

If adding the next element would make the sum exceed `mid`, we start a new subarray.

```cpp
bool canSplit(vector<int> &nums, int k, int mid)
{
    int subarrayCount = 1;
    int currentSum = 0;

    for (int num : nums)
    {
        if (currentSum + num > mid)
        {
            subarrayCount++;
            currentSum = num;

            if (subarrayCount > k)
                return false;
        }
        else
        {
            currentSum += num;
        }
    }

    return true;
}
```

If more than `k` subarrays are required, then `mid` is too small.

If `k` or fewer subarrays are sufficient, then `mid` is a valid candidate.

---

## 🔹 Step 3 — Binary Search

If `mid` is valid:

```cpp
high = mid - 1;
```

We try to find an even smaller valid answer.

If `mid` is invalid:

```cpp
low = mid + 1;
```

We need a larger maximum allowed sum.

Eventually, `low` becomes the minimum valid answer.

---

## 🧠 Key Insight

The important observation is that the problem has a monotonic structure:

```text
Maximum Allowed Sum

Too Small                         Valid
   ❌   ❌   ❌   ❌   |   ✅   ✅   ✅   ✅
                       ↑
                Minimum Valid Answer
```

If a maximum sum `X` is feasible, then every value greater than `X` is also feasible.

Therefore, we can use **Binary Search on Answer**.

---

## 🔄 Pattern Connection

This problem uses the same fundamental pattern as previous problems:

### Day 23 — Koko Eating Bananas

Find the minimum eating speed.

### Day 24 — Capacity To Ship Packages Within D Days

Find the minimum ship capacity.

### Day 25 — Split Array Largest Sum

Find the minimum possible largest subarray sum.

The stories are different, but the underlying pattern is the same:

```text
Search for an answer
        ↓
Check whether the answer is feasible
        ↓
Use monotonicity
        ↓
Binary Search
```

---

## ⏱️ Complexity

Let:

* `n` = number of elements
* `S` = sum of all elements

### Time Complexity

```text
O(n log S)
```

Each binary-search iteration performs a linear feasibility check.

### Space Complexity

```text
O(1)
```

Only constant extra space is used.

---

## 🎯 What I Learned

* How to correctly interpret **splitting an array into `k` subarrays**.
* Difference between a fixed-size window and splitting an entire array.
* How to identify **Binary Search on Answer** problems.
* How to create a greedy feasibility function.
* Why the maximum element is the lower bound.
* Why the total sum is the upper bound.
* How to find the **minimum valid answer** using binary search.
* How multiple seemingly different problems can use the same algorithmic pattern.

---

## 🏆 Day 25 Complete!

Another problem conquered. 🔥

Three problems, one powerful pattern:

**Koko → Ship Packages → Split Array**

The Binary Search on Answer pattern is starting to click. 🧠⚡

**25 Days of DSA — Let's keep going. 🚀**
