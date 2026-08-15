# 🚀 Day 21 — Search in Rotated Sorted Array

## 🧩 Problem

You are given an integer array `nums` sorted in ascending order with distinct values.

Before being passed to the function, `nums` is rotated at an unknown index.

Given the rotated array and an integer `target`, return the index of `target`.

If `target` does not exist in the array, return `-1`.

### Example

```text
Input:
nums = [4,5,6,7,0,1,2]
target = 0

Output:
4
```

---

## 💡 Approach 1 — Brute Force

### Idea

The simplest approach is to search for the target by checking elements from both ends of the array.

We maintain two pointers:

* `l` → left pointer
* `r` → right pointer

At every step:

1. Check whether `nums[l]` is the target.
2. Check whether `nums[r]` is the target.
3. Move `l` forward.
4. Move `r` backward.

If the target is found, return its index.

If the pointers meet without finding the target, return `-1`.

### Code

```cpp
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size() - 1;
        int l = 0;
        int r = n;

        if (n == 0 && nums[n] == target)
            return 0;

        if (nums[n / 2] == target)
            return n / 2;

        while (l < r)
        {
            if (nums[l] == target)
                return l;
            else
                ++l;

            if (nums[r] == target)
                return r;
            else
                --r;
        }

        return -1;
    }
};
```

### Complexity

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

### Result

✅ Accepted by LeetCode

Although this approach works, it does not satisfy the optimal `O(log n)` requirement.

---

# 🚀 Approach 2 — Binary Search

## 💡 Idea

The important observation is that even though the array is rotated, **at least one half of the array is always sorted**.

For every iteration:

1. Find the middle element.
2. Check if `nums[mid]` is the target.
3. Determine which half is sorted.
4. Check whether the target lies inside that sorted half.
5. Search only the relevant half.

This allows us to eliminate approximately half of the remaining elements at every iteration.

---

## 🔍 Step-by-Step Logic

Suppose:

```text
[4, 5, 6, 7, 0, 1, 2]
 L        M        R
```

We check:

```cpp
nums[l] <= nums[mid]
```

If this is true, the **left half is sorted**.

Then we check whether the target lies between:

```text
nums[l] and nums[mid]
```

If it does:

```cpp
r = mid - 1;
```

Otherwise:

```cpp
l = mid + 1;
```

If the left half is not sorted, then the **right half must be sorted**.

We then check whether the target lies between:

```text
nums[mid] and nums[r]
```

and eliminate the irrelevant half.

---

## 💻 Optimal Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // Right half is sorted
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << s.search(nums, target) << endl;

    return 0;
}
```

---

## 📊 Complexity Comparison

| Approach      | Time Complexity | Space Complexity |
| ------------- | --------------: | ---------------: |
| Brute Force   |          `O(n)` |           `O(1)` |
| Binary Search |  **`O(log n)`** |       **`O(1)`** |

---

## 🧠 Key Takeaways

* A rotated sorted array still contains a sorted half.
* Binary search can be adapted to work with rotated arrays.
* First determine which half is sorted.
* Then determine whether the target belongs to that half.
* Eliminate the half that cannot contain the target.
* This reduces the search space by roughly half every iteration.

### 🔑 Core Pattern

```text
Find Mid
   ↓
Target == Mid?
   ↓ No
Which Half Is Sorted?
   ↓
Is Target In Sorted Half?
   ↓
Keep That Half
   ↓
Repeat
```

---

## 🏆 Day 21 Result

```text
Problem: Search in Rotated Sorted Array
LeetCode: 33

Brute Force: ✅ Accepted
Optimal Approach: ✅ Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)

Day 21: COMPLETED 🔥
```

> **Day 21 lesson:**
> Don't stop when the solution works. First make it work, then make it efficient. 🚀

---

## 🔥 DSA Grind Progress

**Day 21 / ∞**

Another problem conquered. 🫡

**Work → Understand → Optimize → Document → Repeat.**
