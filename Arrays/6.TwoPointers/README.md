# Day 10 - Two Pointers (LeetCode 167 & 15)

## Problems Solved

### 1. Two Sum II - Input Array Is Sorted (LeetCode 167)

#### Approach 1: Brute Force
- Checked every possible pair using two nested loops.
- Returned 1-based indices when the target sum was found.

**Time Complexity:** O(n²)

**Space Complexity:** O(1)

---

#### Approach 2: Two Pointers (Optimal)

**Observation:**
- The array is already sorted.
- If the current sum is too small, move the left pointer to increase the sum.
- If the current sum is too large, move the right pointer to decrease the sum.

This allows us to eliminate impossible pairs without checking every combination.

**Algorithm**
1. Initialize `left = 0` and `right = n - 1`.
2. Calculate `sum = numbers[left] + numbers[right]`.
3. If `sum == target`, return the answer.
4. If `sum < target`, increment `left`.
5. Otherwise, decrement `right`.

**Time Complexity:** O(n)

**Space Complexity:** O(1)

---

### Key Takeaway

Whenever a problem involves a **sorted array** and asks for a pair satisfying a condition, think about using the **Two Pointer** technique before considering hashing or brute force.

---

## 2. 3Sum (LeetCode 15)

#### Approach 1: Brute Force

- Used three nested loops to generate every possible triplet.
- Checked whether the sum equals zero.

**Time Complexity:** O(n³)

**Space Complexity:** O(1) (excluding output)

---

#### Approach 2: Sorting + Two Pointers (Optimal)

### Observation

Instead of searching for three numbers simultaneously:

- Fix one number.
- Convert the remaining problem into a **Two Sum** problem.
- Use two pointers to search efficiently.

### Duplicate Handling

To avoid duplicate triplets:

- Skip duplicate values of the first element.
- After finding a valid triplet, move both pointers and skip duplicate values on both sides.

### Complexity

**Time Complexity:** O(n²)

**Space Complexity:** O(1) (excluding output)

---

## Concepts Learned Today

- Two Pointer Technique
- Using sorted arrays efficiently
- Eliminating search space
- Fix one element + Two Sum reduction
- Duplicate handling in sorted arrays
- Problem decomposition