# Container With Most Water (LeetCode 11)

## Problem

Given an integer array `height` where each element represents the height of a vertical line, find two lines that together with the x-axis form a container that can hold the maximum amount of water.

---

## Pattern

**Two Pointers**

---

## Approach 1: Brute Force

### Intuition

Check every possible pair of lines, calculate the area formed by each pair, and keep track of the maximum area.

### Algorithm

1. Iterate through every pair `(i, j)`.
2. Calculate:

   * `width = j - i`
   * `height = min(height[i], height[j])`
   * `area = width × height`
3. Update the maximum area.

### Complexity

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(1)`

---

## Approach 2: Optimal (Two Pointers)

### Intuition

The container's height is always limited by the **shorter line**.

Start with two pointers:

* Left pointer at the beginning.
* Right pointer at the end.

At each step:

* Calculate the current area.
* Move the pointer pointing to the **shorter line** inward.

### Why Move the Shorter Line?

The area depends on:

```
Area = min(height[left], height[right]) × width
```

Moving the taller line always decreases the width while the shorter line still limits the height, so the area cannot increase.

Moving the shorter line is the only way to potentially find a taller line that increases the limiting height enough to produce a larger area.

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Key Learning

* Learned the **Two Pointers** technique.
* Understood that the shorter line determines the container height.
* Learned the reasoning behind moving the shorter pointer instead of the taller one.
* Optimized the solution from `O(n²)` to `O(n)`.

---

## Takeaway

This problem demonstrates how identifying the limiting factor in a problem can lead to an optimal solution. Instead of checking every pair, a simple observation about the shorter line allows us to solve the problem efficiently in linear time.
