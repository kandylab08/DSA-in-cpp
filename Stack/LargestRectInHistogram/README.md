# Day 18 — Largest Rectangle in Histogram

## 🧩 Problem

Given an array of integers `heights` representing the histogram's bar heights, where each bar has a width of `1`, find the **largest rectangular area** that can be formed in the histogram.

### Example

```text
Input:  [2,1,5,6,2,3]
Output: 10
```

The largest rectangle is formed by heights `5` and `6`:

```text
height = 5
width  = 2
area   = 10
```

---

## 💡 Approach 1 — Brute Force

For every possible starting index `i`, expand the rectangle toward the right using index `j`.

While expanding, maintain the minimum height in the current range:

```cpp
minElem = min(minElem, heights[j]);
```

The area of the rectangle from `i` to `j` is:

```text
area = minimum height × width
```

where:

```text
width = j - i + 1
```

### Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)`

---

## 🚀 Approach 2 — Monotonic Stack

The brute-force solution repeatedly searches for the minimum height in every range.

We can optimize this using a **monotonic increasing stack**.

The stack stores **indices** of bars whose heights are in increasing order.

When we encounter a bar shorter than the bar at the top of the stack, the taller bar can no longer extend to the right.

Therefore, we pop it and calculate its maximum possible rectangle.

### Area Calculation

After popping an index:

```text
height = heights[poppedIndex]
```

The current index `i` is the first smaller bar on the right.

After popping, the new stack top is the first smaller bar on the left.

Therefore:

```text
width = i - stack.top() - 1
```

If the stack becomes empty:

```text
width = i
```

So:

```text
area = height × width
```

### Sentinel Technique

The loop runs until `i <= n`.

When:

```cpp
i == n
```

there is no actual bar, but we use this condition to force all remaining bars out of the stack and calculate their areas.

---

## 🧠 Key Insight

The important observation is:

> **For every bar, find the largest range in which that bar can remain the minimum height.**

The monotonic stack helps us discover the left and right boundaries efficiently.

Each index is:

* pushed onto the stack once
* popped from the stack once

Therefore the total work is linear.

---

## ⏱️ Complexity

### Brute Force

```text
Time:  O(n²)
Space: O(1)
```

### Monotonic Stack

```text
Time:  O(n)
Space: O(n)
```

---

## 🔑 Pattern Learned

**Monotonic Increasing Stack**

This problem reinforced:

* Monotonic stacks
* Previous smaller element
* Next smaller element
* Stack-based boundary detection
* Range width calculation
* Sentinel technique
* Optimizing an `O(n²)` solution to `O(n)`

---

## 🏁 Takeaway

This problem was a great example of turning a brute-force idea into an efficient solution.

The progression was:

```text
Brute Force
    ↓
Find minimum height in every range
    ↓
Realize boundaries are the key
    ↓
Monotonic Increasing Stack
    ↓
O(n) Solution
```

**Day 18 completed! 🔥**
