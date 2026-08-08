# Day 16 — Daily Temperatures

## 🧩 Problem

**LeetCode 739 — Daily Temperatures**

Given an array `temperatures`, return an array where `answer[i]` represents the number of days you have to wait after the `i`th day to get a warmer temperature.

If there is no future day with a warmer temperature, `answer[i]` should be `0`.

### Example

```text
Input:
[73, 74, 75, 71, 69, 72, 76, 73]

Output:
[1, 1, 4, 2, 1, 1, 0, 0]
```

---

## 💡 Approach 1 — Brute Force

For every temperature, scan all the temperatures to its right until a warmer temperature is found.

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (temperatures[i] < temperatures[j])
        {
            ans[i] = j - i;
            break;
        }
    }
}
```

### Complexity

```text
Time:  O(n²)
Space: O(n)
```

This approach is straightforward but becomes slow for large inputs.

---

## 🚀 Approach 2 — Monotonic Stack

Instead of repeatedly searching to the right, maintain a stack containing the **indices of temperatures that are still waiting for a warmer day**.

For each temperature:

1. Check the top index of the stack.
2. If the current temperature is warmer, the current day is the answer for that index.
3. Calculate the number of days using `i - idx`.
4. Pop the index.
5. Continue checking because the current temperature may solve multiple waiting temperatures.
6. Push the current index onto the stack.

### Key Condition

```cpp
temperatures[i] > temperatures[s.top()]
```

When this is true:

```cpp
int idx = s.top();
s.pop();
ans[idx] = i - idx;
```

Then:

```cpp
s.push(i);
```

---

## 💻 Optimized C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() &&
                   temperatures[i] > temperatures[s.top()])
            {
                int idx = s.top();
                s.pop();

                ans[idx] = i - idx;
            }

            s.push(i);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> temperatures =
        {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> res =
        s.dailyTemperatures(temperatures);

    for (const auto& temp : res)
    {
        cout << temp << " ";
    }

    return 0;
}
```

### Output

```text
1 1 4 2 1 1 0 0
```

---

## 🧠 Important Insight

The stack stores **indices, not temperatures**.

Why?

Because the answer requires the distance between two positions:

```text
Current Index - Previous Index
```

The stack represents temperatures that are still **waiting for a warmer temperature**.

When a warmer temperature arrives, those waiting temperatures are resolved and removed from the stack.

---

## 🔥 Why `while` Instead of `if`?

A single warmer temperature can resolve multiple previous temperatures.

For example:

```text
[75, 71, 69, 72]
```

When `72` arrives:

```text
72 > 69  → resolve 69
72 > 71  → resolve 71
72 < 75  → stop
```

Therefore, we need:

```cpp
while (...)
```

rather than:

```cpp
if (...)
```

---

## ⏱️ Complexity

| Approach        |    Time |  Space |
| --------------- | ------: | -----: |
| Brute Force     | `O(n²)` | `O(n)` |
| Monotonic Stack |  `O(n)` | `O(n)` |

The optimized solution is `O(n)` because every index is:

* pushed onto the stack once
* popped from the stack at most once

Therefore, the total number of stack operations is linear.

---

## 🎯 Pattern Learned

### Monotonic Stack

This pattern is useful for problems involving:

* Next greater element
* Next smaller element
* Previous greater element
* Previous smaller element
* Elements waiting for a future condition

---

## 📈 Today's Learning

Today's problem was an important transition from **brute force to optimized pattern-based thinking**.

The brute-force approach repeatedly searched to the right.

The optimized approach changed the perspective:

> Instead of searching for a warmer day for every temperature, let each temperature wait in a stack until a warmer day arrives.

### ✅ Status

**Solved — Brute Force + Optimized Monotonic Stack**

**Pattern:** Monotonic Stack

**Difficulty:** Medium

**LeetCode:** 739
