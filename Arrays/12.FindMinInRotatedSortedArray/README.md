# 🚀 Day 22 — Find Minimum in Rotated Sorted Array

## 🧩 Problem

Given a sorted array of **unique integers** that has been rotated an unknown number of times, find the minimum element.

### Example

```text
Input:  [3,4,5,1,2]
Output: 1
```

---

## 💡 Approach — Binary Search

The array is originally sorted, but after rotation it consists of two sorted portions.

We use binary search and compare `nums[mid]` with `nums[r]`:

- If `nums[mid] > nums[r]`, the minimum must be **to the right of `mid`**.
- Otherwise, the minimum is at `mid` or somewhere to its left.

### Key Logic

```cpp
if (nums[mid] > nums[r])
    l = mid + 1;
else
    r = mid;
```

When `l == r`, that index contains the minimum element.

---

## 💻 Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        return nums[l];
    }
};
```

---

## ⏱️ Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

---

# ⭐ Bonus — Find Minimum in Rotated Sorted Array II

Also practiced **LeetCode 154 — Find Minimum in Rotated Sorted Array II**, where duplicate values are allowed.

The main difference is handling the case:

```cpp
nums[mid] == nums[r]
```

In that situation, we cannot determine which side contains the minimum, so we safely reduce the search space:

```cpp
r--;
```

### Key Logic

```cpp
if (nums[mid] > nums[r])
    l = mid + 1;
else if (nums[mid] < nums[r])
    r = mid;
else
    r--;
```

### Complexity

- **Average:** `O(log n)`
- **Worst case:** `O(n)` due to duplicates
- **Space:** `O(1)`

---

## 🧠 What I Learned

- How binary search can be adapted to rotated sorted arrays.
- Why comparing `nums[mid]` with `nums[r]` is useful.
- Why `l = mid + 1` is necessary when `mid` cannot be the answer.
- Why `r = mid` is used when `mid` can still be the minimum.
- How duplicate values change the binary-search strategy.
- Why `nums[l] == nums[r]` does **not** always mean the left value is the minimum.

---

## 🏆 Day 22 Progress

-  Find Minimum in Rotated Sorted Array
-  Find Minimum in Rotated Sorted Array II
-  Binary Search on rotated arrays
-  Handle duplicate values
-  Understand `O(log n)` vs worst-case `O(n)`

**Day 22 complete. 🔥**

> Another day. Another pattern understood.  
> The DSA grind continues. 🗿🚀
