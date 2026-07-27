# Hash Map (`unordered_map`) in C++

## What is a Hash Map?

A **Hash Map** is a data structure that stores data as **key-value pairs**.

In C++, the STL implementation of a hash map is `unordered_map`.

It allows us to **insert**, **search**, **update**, and **delete** elements efficiently using a **key**.

---

# Syntax

```cpp
#include <unordered_map>

unordered_map<KeyType, ValueType> mapName;
```

### Example

```cpp
unordered_map<int, string> students;

students[1] = "Alice";
students[2] = "Bob";
students[3] = "Charlie";
```

Here,

- **Key** → Student ID
- **Value** → Student Name

---

# How Does It Work?

A hash map uses a **hash function** to convert a key into an index where the value is stored.

Instead of searching every element one by one, the hash function calculates where the element should be located.

This is why searching is usually **O(1)**.

---

# Common Operations

## 1. Insert

```cpp
unordered_map<int, int> hmp;

hmp[10] = 100;
hmp[20] = 200;
```

Output:

```text
10 → 100
20 → 200
```

---

## 2. Access Value

```cpp
cout << hmp[10];
```

Output

```text
100
```

---

## 3. Update Value

```cpp
hmp[10] = 500;
```

Now,

```text
10 → 500
```

---

## 4. Search

```cpp
if (hmp.find(20) != hmp.end())
{
    cout << "Found";
}
```

If the key exists,

```text
find() != end()
```

Otherwise,

```text
find() == end()
```

---

## 5. Delete

```cpp
hmp.erase(20);
```

Removes the key `20` from the map.

---

## 6. Size

```cpp
cout << hmp.size();
```

Returns the number of key-value pairs.

---

## 7. Check Empty

```cpp
if (hmp.empty())
{
    cout << "Map is empty";
}
```

---

# Traversing a Hash Map

Using a range-based loop:

```cpp
for (auto pair : hmp)
{
    cout << pair.first << " -> " << pair.second << endl;
}
```

Output

```text
10 -> 100
20 -> 200
30 -> 300
```

Where:

- `pair.first` → Key
- `pair.second` → Value

---

# Time Complexity

| Operation | Average Case |
| --------- | -----------: |
| Insert    |         O(1) |
| Search    |         O(1) |
| Update    |         O(1) |
| Delete    |         O(1) |

Worst-case complexity can be **O(n)** due to hash collisions, but this is uncommon.

---

# Space Complexity

```text
O(n)
```

where `n` is the number of stored key-value pairs.

---

# `unordered_map` vs `map`

| Feature        | `unordered_map` | `map`          |
| -------------- | --------------- | -------------- |
| Implementation | Hash Table      | Red-Black Tree |
| Ordering       | No ordering     | Sorted by key  |
| Insert         | O(1) average    | O(log n)       |
| Search         | O(1) average    | O(log n)       |
| Delete         | O(1) average    | O(log n)       |

Use **`unordered_map`** when ordering is not required and fast lookup is needed.

Use **`map`** when sorted keys are required.

---

# Important Member Functions

| Function   | Description                              |
| ---------- | ---------------------------------------- |
| `insert()` | Inserts a key-value pair                 |
| `find()`   | Searches for a key                       |
| `erase()`  | Removes a key                            |
| `count()`  | Returns `1` if key exists, otherwise `0` |
| `size()`   | Number of elements                       |
| `empty()`  | Checks whether the map is empty          |
| `clear()`  | Removes all elements                     |

---

# Common Mistakes

## Mistake 1: Using `operator[]` for Searching

❌ Incorrect

```cpp
if (hmp[5])
```

Reason:

If key `5` does not exist, `operator[]` **creates** it automatically.

✔ Correct

```cpp
if (hmp.find(5) != hmp.end())
```

---

## Mistake 2: Assuming Elements are Ordered

```cpp
unordered_map<int, int> hmp;
```

The order of elements is **not guaranteed**.

If sorted order is required, use `map`.

---

## Mistake 3: Forgetting to Include the Header

Always include:

```cpp
#include <unordered_map>
```

---

# Applications of Hash Maps

- Two Sum
- Frequency Counting
- Counting Duplicate Elements
- Grouping Anagrams
- Finding Missing Numbers
- Caching
- Database Indexing
- Compiler Symbol Tables
- Graph Algorithms
- Memoization in Dynamic Programming

---

# Example: Frequency Counting

```cpp
vector<int> nums = {1, 2, 2, 3, 1, 2};

unordered_map<int, int> freq;

for (int num : nums)
{
    freq[num]++;
}
```

Output

```text
1 -> 2
2 -> 3
3 -> 1
```

---

# Key Takeaways

- `unordered_map` stores data as **key-value pairs**.
- Uses a **hash table** internally.
- Provides **O(1)** average time complexity for insertion, lookup, and deletion.
- `find()` is preferred over `operator[]` when checking if a key exists.
- Elements are **not stored in sorted order**.
- One of the most important data structures for solving coding interview problems efficiently.

---

# Problems Where I Used This Concept

- ✅ LeetCode #1 — Two Sum
- ⬜ Group Anagrams
- ⬜ Valid Anagram
- ⬜ Top K Frequent Elements
- ⬜ Contains Duplicate
- ⬜ Happy Number
- ⬜ Longest Consecutive Sequence
- ⬜ Isomorphic Strings

> **Revision Tip:** Whenever you see words like **lookup**, **frequency**, **pair search**, **duplicate detection**, or **mapping one value to another**, consider using a **Hash Map**.
