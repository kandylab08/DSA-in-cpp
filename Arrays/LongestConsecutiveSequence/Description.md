# Longest Consecutive Sequence (LeetCode 128)

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

Your algorithm must run in **O(n)** time.

### Example

**Input:**

```text
nums = [100,4,200,1,3,2]
```

**Output:**

```text
4
```

**Explanation:**

The longest consecutive sequence is:

```text
1 → 2 → 3 → 4
```

Hence, the answer is **4**.

---

# Approach

## Observation

A straightforward solution is to sort the array and count consecutive elements. However, sorting requires **O(n log n)** time, while the problem specifically asks for an **O(n)** solution.

To achieve linear time, we use an `unordered_set`.

The key idea is:

* Store every number in an `unordered_set`.
* A number is considered the **start of a sequence** only if `num - 1` is **not** present in the set.
* Once a starting point is found, continue checking `num + 1`, `num + 2`, ... until the sequence ends.
* Track the maximum sequence length.

This ensures every sequence is counted exactly once.

---

# Algorithm

1. Insert all elements into an `unordered_set`.
2. Initialize `largestSeq = 0`.
3. Traverse each unique number.
4. If `(num - 1)` is **not** present:

   * Start a new sequence.
   * Keep checking whether the next consecutive number exists.
   * Count the sequence length.
5. Update the maximum sequence length.
6. Return the maximum.

---

# Complexity Analysis

### Time Complexity

* Building the hash set: **O(n)**
* Traversing all unique elements: **O(n)**
* Every element is visited at most once while expanding sequences.

**Overall:** **O(n)**

---

### Space Complexity

* Hash set stores all unique elements.

**Overall:** **O(n)**

---

# Concepts Learned

* `unordered_set`
* Constant-time lookup using hash tables
* Identifying the start of a sequence
* Avoiding redundant computations
* Difference between theoretical complexity and practical runtime
* Why an `O(n)` algorithm may not always have a lower runtime than an `O(n log n)` solution

---

# Key Takeaways

* `unordered_set` is ideal when only existence checking is required.
* Never rely on the iteration order of an `unordered_set`.
* Start counting **only** from the beginning of a sequence.
* Skipping numbers that already belong to a sequence prevents unnecessary work and keeps the algorithm linear.
* Always analyze both **time complexity** and **implementation details**, especially when optimizing for interview problems.

---

# Status

✅ Solved using the optimal **Hash Set** approach.
