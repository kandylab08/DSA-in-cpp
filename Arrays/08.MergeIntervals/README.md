# 📘 DSA Practice — Day 11

## 🧩 Problem Solved

### LeetCode 56 — Merge Intervals

**Difficulty:** Medium
**Topic:** Arrays / Intervals / Sorting
**Pattern:** Sorting + Greedy Interval Merging

---

## 💡 Problem

Given a collection of intervals, merge all overlapping intervals and return the non-overlapping intervals that cover all the intervals.

### Example

**Input:**

```text
[[1,3],[2,6],[8,10],[15,18]]
```

**Output:**

```text
[[1,6],[8,10],[15,18]]
```

---

## 🧠 Approach

The key observation is that merging intervals becomes much easier once the intervals are sorted by their starting points.

### Steps

1. Sort all intervals by their starting value.
2. Take the first interval as the current interval.
3. Traverse the remaining intervals.
4. Check whether the next interval overlaps with the current interval:

   ```cpp
   intervals[i][0] <= curInterval[1]
   ```
5. If they overlap:

   * Extend the current interval's ending point using:

   ```cpp
   curInterval[1] = max(curInterval[1], intervals[i][1]);
   ```
6. If they do not overlap:

   * Store the current interval in the result.
   * Start a new current interval.
7. After the loop, add the final current interval to the result.

---

## 🔑 Key Insight

> **Sort first, then process intervals from left to right.**

Once the intervals are sorted, we only need to compare the next interval with the current merged interval.

### Overlap condition

```text
next.start <= current.end
```

If true → merge.

Otherwise → save the current interval and move forward.

---

## ⏱️ Complexity

### Time Complexity

```text
O(n log n)
```

Sorting takes `O(n log n)` and the merging traversal takes `O(n)`.

### Space Complexity

```text
O(n)
```

The result array can contain up to `n` intervals.

---

## 🧪 Test Cases

### Case 1 — Normal Overlap

```text
Input:
[[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]
```

### Case 2 — Touching Intervals

```text
Input:
[[1,4],[4,5]]

Output:
[[1,5]]
```

### Case 3 — Completely Contained Interval

```text
Input:
[[1,10],[2,3]]

Output:
[[1,10]]
```

### Case 4 — No Overlap

```text
Input:
[[1,2],[3,4]]

Output:
[[1,2],[3,4]]
```

### Case 5 — Unsorted Input

```text
Input:
[[1,4],[0,2]]

Output:
[[0,4]]
```

---

## 🎯 What I Learned

The hardest part of this problem was not the implementation. The important step was recognizing that **sorting simplifies the entire problem**.

After sorting, I considered the possible cases mentally:

* Intervals overlap → merge them.
* The next interval is contained → keep the larger ending point.
* The next interval extends further → update the ending point.
* Intervals do not overlap → store the current interval and start a new one.
* Add the final interval after the loop.

This helped me derive the algorithm before writing the code.

### 🧠 Pattern Learned

```text
Intervals
   ↓
Sort by starting point
   ↓
Check overlap
   ↓
Merge / Start new interval
```

**Main takeaway:**

> Don't rush into coding. First sort the problem into cases in your mind, then design the algorithm to handle each case.
