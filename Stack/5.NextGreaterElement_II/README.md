# Day 17 — Next Greater Element II

## 📌 Problem

**LeetCode 503 — Next Greater Element II**

Given a circular integer array `nums`, return the next greater element for every element.

The next greater element of an element `x` is the first element greater than `x` encountered while traversing the array in the forward direction. Since the array is circular, traversal continues from the beginning after reaching the end.

If no greater element exists, return `-1`.

### Example

```text
Input:
nums = [1, 2, 1]

Output:
[2, -1, 2]
```

---

## 💡 Approach

### 1. Brute Force

For every element, traverse forward through the array until:

* A greater element is found, or
* We return to the starting index.

This handles the circular nature using modulo arithmetic.

**Time Complexity:** `O(n²)`
**Space Complexity:** `O(n)`

---

### 2. Optimized — Monotonic Stack

We can solve the problem in `O(n)` using a **monotonic decreasing stack**.

The main idea is to conceptually traverse the array twice:

```text
[1, 2, 3, 4, 3]
[1, 2, 3, 4, 3]
```

Instead of actually creating a second array, we iterate from:

```cpp
0 → 2*n - 1
```

and access the circular index using:

```cpp
i % n
```

The stack stores indices whose next greater element has not yet been found.

Whenever:

```cpp
nums[i % n] > nums[stack.back()]
```

the current element is the next greater element for the index on top of the stack.

We pop that index and update its answer.

### Important Detail

Indices are pushed into the stack **only during the first traversal**:

```cpp
if (i < n)
    stck.push_back(i);
```

During the second traversal, we only use elements to resolve remaining indices.

---

## 🧠 Key Pattern

```text
Circular Array
      ↓
Traverse 2n elements
      ↓
Use i % n
      ↓
Monotonic Stack
      ↓
Resolve smaller elements
```

This is a useful pattern for many **Next Greater Element** problems involving circular arrays.

---

## 💻 C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> res(n, -1);
        vector<int> stck;

        for (int i = 0; i < 2 * n; ++i)
        {
            int current = i % n;

            while (!stck.empty() && nums[current] > nums[stck.back()])
            {
                res[stck.back()] = nums[current];
                stck.pop_back();
            }

            if (i < n)
                stck.push_back(current);
        }

        return res;
    }
};
```

---

## ⏱️ Complexity

| Complexity | Value  |
| ---------- | ------ |
| Time       | `O(n)` |
| Space      | `O(n)` |

Although there is a `while` loop inside the `for` loop, every index is pushed onto the stack once and popped at most once. Therefore, the total stack operations are linear.

---

## 🔑 Key Takeaways

* Recognized the **Next Greater Element** pattern.
* Used a **monotonic decreasing stack**.
* Handled a circular array using `2 * n` traversal.
* Used `% n` to simulate circular indexing.
* Improved the brute-force `O(n²)` solution to `O(n)`.
* Learned that nested loops do not automatically mean `O(n²)` when each element is pushed/popped a limited number of times.

---

## 🚀 Progress

**Day 17 — Completed ✅**

> Pattern learned: **Circular Array + Monotonic Stack**
