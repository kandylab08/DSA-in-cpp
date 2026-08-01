# Top K Frequent Elements

## 📝 Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

The answer may be returned in any order.

---

## 💡 Approach

1. Traverse the array and count the frequency of each element using an `unordered_map`.
2. Store each `(element, frequency)` pair inside a `vector<pair<int, int>>`.
3. Sort the vector in descending order of frequency using a custom comparator (lambda function).
4. Extract the first `k` elements from the sorted vector.

---

## 🧠 STL Concepts Used

- `unordered_map`
- `vector`
- `pair`
- `sort()`
- Lambda Function (Custom Comparator)

---

## ⏱️ Time Complexity

- Frequency Counting: **O(n)**
- Copying Map to Vector: **O(m)**
- Sorting: **O(m log m)**
- Extracting Result: **O(k)**

Overall:

**O(n + m log m)**

Worst Case:

**O(n log n)**

where

- `n` = total number of elements
- `m` = number of unique elements

---

## 💾 Space Complexity

- Frequency Map → **O(m)**
- Vector of Pairs → **O(m)**
- Result Vector → **O(k)**

Overall:

**O(m)**

---

## 📚 Concepts Learned

- Frequency Counting
- Hash Maps
- STL Pair
- Vector of Pairs
- Lambda Functions
- Custom Sorting