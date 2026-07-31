# Group Anagrams

**LeetCode Problem:** 49. Group Anagrams
**Difficulty:** Medium
**Topics:** Array, Hash Table, String, Sorting

---

## Problem Statement

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

An **anagram** is a word or phrase formed by rearranging the letters of another word using all the original letters exactly once.

### Example

**Input**

```text
["eat","tea","tan","ate","nat","bat"]
```

**Output**

```text
[
  ["eat","tea","ate"],
  ["tan","nat"],
  ["bat"]
]
```

---

## Approach

The key observation is that **all anagrams become identical after sorting their characters**.

### Algorithm

1. Create an `unordered_map<string, vector<string>>`.
2. Traverse through each string in the input array.
3. Make a copy of the current string.
4. Sort the copied string to generate a unique pattern.
5. Use the sorted string as the key in the hash map and append the original string to its corresponding vector.
6. After processing all strings, copy every grouped vector from the hash map into the result vector.
7. Return the final grouped result.

---

## Data Structures Used

* **unordered_map<string, vector<string>>**

  * Stores the sorted string as the key.
  * Stores all original strings having the same sorted pattern as the value.

* **vector<vector<string>>**

  * Stores the final grouped anagrams.

---

## Why This Works

Consider the following strings:

```text
eat -> aet
tea -> aet
ate -> aet
```

After sorting, all three strings produce the same key `"aet"`.

Similarly,

```text
tan -> ant
nat -> ant
```

Both belong to the same group.

Since every anagram produces the same sorted representation, we can use that sorted string as a unique identifier.

---

## Complexity Analysis

Let:

* **n** = Number of strings
* **k** = Average length of each string

### Time Complexity

* Sorting each string: **O(k log k)**
* Processing all strings: **O(n × k log k)**

**Overall:** **O(n × k log k)**

### Space Complexity

* Hash map stores all strings and grouping information.

**Overall:** **O(n × k)**

---

## Edge Cases Considered

* Empty input array.
* Single string.
* Duplicate strings.
* Empty strings.
* Multiple groups of different sizes.

---

## Key Learning

* Using a transformed representation (sorted string) as a hash key.
* Efficient use of `unordered_map` for grouping.
* Working with `vector<string>` as values in a hash map.
* Understanding range-based for loops with `const` references.
* Using `sort()` from the STL to generate unique patterns.

---

## Concepts Practiced

* Hash Map (`unordered_map`)
* Strings
* Sorting
* STL Algorithms
* Vectors
* Range-based for loops
* Time and Space Complexity Analysis

---

## Status

✅ Solved

**Language:** C++
