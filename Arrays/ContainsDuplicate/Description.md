# Contains Duplicate (LeetCode #217)

## Problem Statement

Given an integer array `nums`, return **`true`** if any value appears **at least twice** in the array, and return **`false`** if every element is distinct.

### Example 1

```text
Input: nums = [1,2,3,1]
Output: true
```

### Example 2

```text
Input: nums = [1,2,3,4]
Output: false
```

---

# Intuition

If we've already seen a number before, then the array contains a duplicate.

Instead of comparing every element with every other element (which takes **O(n²)** time), we can use a **Hash Set** to remember all previously seen elements.

As we iterate through the array:

- If the current element is already in the set, return `true`.
- Otherwise, insert it into the set.
- If we finish the traversal without finding duplicates, return `false`.

---

# Algorithm

1. Create an empty `unordered_set`.
2. Traverse the array.
3. For each element:
   - Try to insert it into the set.
   - If insertion fails, the element already exists.
   - Return `true`.

4. If the loop finishes, return `false`.

---

# Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;
        seen.reserve(nums.size());

        for (int num : nums)
        {
            if (!seen.insert(num).second)
                return true;
        }

        return false;
    }
};
```

---

# Dry Run

### Input

```text
nums = [1,2,3,1]
```

| Current Number | Hash Set | Duplicate?            |
| -------------: | -------- | --------------------- |
|              1 | {1}      | No                    |
|              2 | {1,2}    | No                    |
|              3 | {1,2,3}  | No                    |
|              1 | {1,2,3}  | **Yes → Return true** |

---

# Code Explanation

### Step 1

```cpp
unordered_set<int> seen;
```

Creates a hash set to store unique numbers.

Unlike `unordered_map`, a set stores **only values**, not key-value pairs.

---

### Step 2

```cpp
seen.reserve(nums.size());
```

Pre-allocates memory for the expected number of elements.

This reduces internal rehashing and may slightly improve performance.

---

### Step 3

```cpp
if (!seen.insert(num).second)
```

`insert()` returns a pair:

```cpp
pair<iterator, bool>
```

- `.first` → Iterator pointing to the element.
- `.second` → `true` if insertion succeeded.
- `.second` → `false` if the element already existed.

If `.second` is `false`, a duplicate has been found.

---

# Time Complexity

| Operation            |   Complexity |
| -------------------- | -----------: |
| Traversal            |         O(n) |
| Set Lookup/Insertion | O(1) average |
| Overall              |     **O(n)** |

---

# Space Complexity

The set stores at most **n** unique elements.

**Space Complexity = O(n)**

---

# Concepts Learned

- `unordered_set`
- Hash Table
- Unique Element Storage
- `insert()` return value
- `pair<iterator, bool>`
- `reserve()`
- Duplicate Detection using Hashing

---

# Common Mistakes

### 1. Using `sizeof()` with a vector

❌ Incorrect

```cpp
int n = sizeof(nums) / sizeof(nums[0]);
```

✔ Correct

```cpp
int n = nums.size();
```

---

### 2. Using `unordered_map` when values are unnecessary

If only existence needs to be checked, prefer:

```cpp
unordered_set<int> seen;
```

instead of

```cpp
unordered_map<int, int> mp;
```

---

### 3. Performing Two Lookups

❌

```cpp
if (seen.find(num) != seen.end())
    return true;

seen.insert(num);
```

✔ Better

```cpp
if (!seen.insert(num).second)
    return true;
```

This combines insertion and duplicate detection into a single operation.

---

# Interview Questions

### Why use `unordered_set` instead of `unordered_map`?

A set stores only unique values.

Since we don't need indices or associated values, a set is more appropriate and uses less memory.

---

### Why not sort the array first?

Sorting gives an **O(n log n)** solution.

Hashing provides an **O(n)** average solution, making it more efficient.

---

### Why call `reserve()`?

It allocates space in advance, reducing the number of rehash operations as elements are inserted.

---

# Key Takeaways

- Use a **Hash Set** when only element existence matters.
- `insert().second` is an elegant way to detect duplicates.
- `unordered_set` provides **O(1)** average insertion and lookup.
- This is the optimal solution for the Contains Duplicate problem.

---

# Related Concepts

- Hash Table
- `unordered_set`
- Duplicate Detection
- Time Complexity Optimization
- Hashing Pattern

---

# Personal Learning Log

- ✅ Learned when to use `unordered_set` instead of `unordered_map`.
- ✅ Learned how `insert()` returns `pair<iterator, bool>`.
- ✅ Learned the purpose of `reserve()`.
- ✅ Reinforced the Hashing pattern for fast lookups.
