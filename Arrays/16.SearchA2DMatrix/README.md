# 🚀 Day 25 — Search a 2D Matrix

## 🧩 Problem

Given an `m x n` integer matrix with the following properties:

* Each row is sorted in ascending order.
* The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` exists in the matrix, otherwise return `false`.

### Example

```text
Input:
matrix =
[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]

target = 3

Output:
true
```

---

## 💡 Approach 1 — Brute Force

Traverse every element of the matrix and compare it with the target.

```cpp
for (auto row : matrix)
{
    for (int element : row)
    {
        if (element == target)
            return true;
    }
}

return false;
```

### Complexity

* **Time:** `O(m × n)`
* **Space:** `O(1)`

This works, but it doesn't take advantage of the fact that the matrix is sorted.

---

## 🚀 Approach 2 — Binary Search Twice

Since every row is sorted and the rows themselves are ordered, we can use binary search in two stages.

### Step 1 — Find the Candidate Row

Perform binary search on the rows.

For a row:

```text
[first element] ... [last element]
```

If:

```text
matrix[mid][0] > target
```

the target must be in an earlier row.

If:

```text
matrix[mid][n] < target
```

the target must be in a later row.

If:

```text
matrix[mid][0] <= target <= matrix[mid][n]
```

then this is the only row where the target can exist.

### Step 2 — Binary Search Inside the Row

Once the candidate row is found, perform a normal binary search on that row.

```text
target < matrix[mid][column]
        ↓
search left

target > matrix[mid][column]
        ↓
search right
```

---

## ⏱️ Complexity Analysis

Let:

* `m` = number of rows
* `n` = number of columns

### Time Complexity

Binary search for the row:

```text
O(log m)
```

Binary search inside the selected row:

```text
O(log n)
```

Therefore:

```text
O(log m + log n)
```

### Space Complexity

No extra data structures are used.

```text
O(1)
```

---

## 🧠 Key Takeaways

* A sorted matrix should immediately make us think about **Binary Search**.
* We can exploit the structure of the matrix instead of checking every element.
* First identify the **candidate row**.
* Then perform binary search inside that row.
* Always remember the binary search movement:

  * `value < target` → move right
  * `value > target` → move left
* The optimized solution reduces the brute-force `O(m × n)` approach to `O(log m + log n)`.

---

## 🏆 Day 25 Status

**Problem:** LeetCode 74 — Search a 2D Matrix
**Difficulty:** Medium
**Pattern:** Binary Search
**Approach:** Binary Search on Rows + Binary Search on Columns
**Time:** `O(log m + log n)`
**Space:** `O(1)`
**Status:** ✅ Solved

---

## 🔥 Progress

**26 Days of DSA — Completed!**

> Consistency beats motivation.
> One problem at a time. One pattern at a time. 🚀
