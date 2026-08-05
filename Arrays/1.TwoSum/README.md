# Two Sum (LeetCode #1)

## Problem Statement

Given an integer array `nums` and an integer `target`, return the **indices** of the two numbers such that they add up to the target.

You may assume that:

- Exactly one valid solution exists.
- You cannot use the same element twice.
- The answer can be returned in any order.

### Example

```text
Input:
nums = [2, 7, 11, 15]
target = 9

Output:
[0, 1]
```

---

# Intuition

A brute-force approach would compare every element with every other element until the required sum is found.

Although simple, this requires checking many unnecessary pairs and results in **O(n²)** time complexity.

A better approach is to use a **Hash Map (`unordered_map`)**.

While traversing the array:

1. Calculate the number required to reach the target (called the **complement**).
2. Check whether the complement has already been seen.
3. If yes, return both indices.
4. Otherwise, store the current number along with its index.

This reduces the time complexity to **O(n)**.

---

# Algorithm

1. Create an empty `unordered_map<int, int>`.
2. Traverse the array from left to right.
3. For every element:
   - Compute the complement:

     ```cpp
     complement = target - nums[i];
     ```

   - If the complement exists in the hash map:
     - Return the stored index and the current index.

   - Otherwise:
     - Store the current number and its index.

4. Return an empty vector (or `{-1, -1}`) if no solution exists.

---

# Dry Run

### Input

```text
nums = [2, 7, 11, 15]
target = 9
```

| Index | Number | Complement | Hash Map After Step | Result         |
| ----: | -----: | ---------: | ------------------- | -------------- |
|     0 |      2 |          7 | {2 → 0}             | Continue       |
|     1 |      7 |          2 | {2 → 0}             | Found → {0, 1} |

---

# Code Explanation

### Step 1

```cpp
unordered_map<int, int> hmp;
```

Creates a hash map where

- **Key** = Array element
- **Value** = Index of that element

Example:

```text
{
    2  -> 0
    7  -> 1
    11 -> 2
}
```

---

### Step 2

```cpp
for (int i = 0; i < nums.size(); i++)
```

Traverse every element exactly once.

---

### Step 3

```cpp
int complement = target - nums[i];
```

Find the number needed to reach the target.

Example:

```text
Current number = 7
Target = 10

Complement = 10 - 7 = 3
```

Now check whether **3** has already appeared.

---

### Step 4

```cpp
if (hmp.find(complement) != hmp.end())
```

Check whether the complement already exists in the hash map.

If it exists:

```cpp
return {hmp[complement], i};
```

Return the stored index and the current index.

---

### Step 5

```cpp
hmp[nums[i]] = i;
```

If the complement is not found, store the current number and continue.

---

# Why Does This Work?

When processing an element, all previous elements have already been stored in the hash map.

So if the required complement exists, it can be found instantly in **O(1)** average time.

Example:

```text
nums = [3, 2, 4]
target = 6
```

### Iteration 1

```text
Current = 3
Need = 3

Hash Map:
{3 → 0}
```

---

### Iteration 2

```text
Current = 2
Need = 4

Hash Map:
{
3 → 0
2 → 1
}
```

---

### Iteration 3

```text
Current = 4
Need = 2

2 exists in the hash map.

Return:
{1, 2}
```

---

# Time Complexity

| Operation        |   Complexity |
| ---------------- | -----------: |
| Traversing array |         O(n) |
| Hash map lookup  | O(1) average |
| Overall          |     **O(n)** |

---

# Space Complexity

The hash map stores at most **n** elements.

**Space Complexity = O(n)**

---

# Why `unordered_map`?

| `unordered_map`      | `map`                |
| -------------------- | -------------------- |
| Hash Table           | Red-Black Tree       |
| O(1) average lookup  | O(log n) lookup      |
| Faster for searching | Slower than hash map |

For this problem, `unordered_map` is the preferred choice.

---

# Common Mistakes

### 1. Using `sizeof(nums)`

❌ Incorrect

```cpp
for (int i = 0; i < sizeof(nums); i++)
```

When passed to a function, an array becomes a pointer.

`sizeof(nums)` returns the size of the pointer, **not** the number of elements.

✔ Correct

```cpp
for (int i = 0; i < nums.size(); i++)
```

---

### 2. Using `operator[]` for searching

❌ Incorrect

```cpp
if (hmp[complement])
```

`operator[]` inserts a new key if it doesn't exist.

✔ Correct

```cpp
if (hmp.find(complement) != hmp.end())
```

---

### 3. Forgetting to return a value

Always end the function with

```cpp
return {};
```

or

```cpp
return {-1, -1};
```

Even though LeetCode guarantees a valid solution, C++ requires every code path in a non-void function to return a value.

---

# Interview Questions

### Why is the time complexity O(n)?

Each element is processed exactly once, and hash map operations take **O(1)** average time.

---

### Why not use two nested loops?

Two nested loops require checking every pair.

Time Complexity:

```text
O(n²)
```

The hash map approach avoids repeated comparisons.

---

### Why store previous elements?

Future elements have not been processed yet.

By storing previous elements, the complement can be found immediately when encountered.

---

### Does this work with duplicate numbers?

Yes.

Example:

```text
nums = [3, 3]
target = 6
```

Execution:

- Store first `3`.
- Second `3` finds the first `3` in the hash map.
- Return `{0, 1}`.

---

# Key Takeaways

- Use a hash map to achieve **O(n)** time complexity.
- Store each number with its index.
- Search for the complement before inserting the current element.
- `unordered_map` provides **O(1)** average lookup.
- `find()` should be used instead of `operator[]` when checking for existence.
- This is the optimal solution for the Two Sum problem.
