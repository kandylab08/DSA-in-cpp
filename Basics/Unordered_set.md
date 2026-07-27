# Unordered Set (`unordered_set`) in C++

## What is an Unordered Set?

An **Unordered Set** is a container in the C++ Standard Template Library (STL) that stores **unique elements**.

Unlike an array or vector, duplicate values are **not allowed**.

Internally, `unordered_set` uses a **Hash Table**, which provides **O(1)** average time complexity for insertion, deletion, and searching.

---

# Syntax

```cpp
#include <unordered_set>

unordered_set<DataType> setName;
```

### Example

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> numbers;

    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);

    return 0;
}
```

---

# How Does It Work?

Whenever an element is inserted:

1. A **hash function** computes its hash value.
2. The element is stored in a bucket.
3. Searching uses the same hash function to locate the bucket directly.

This avoids scanning every element, making lookups very fast.

---

# Properties of `unordered_set`

- Stores **only unique elements**.
- Duplicate values are ignored.
- Elements are **not stored in sorted order**.
- Provides fast insertion and searching.
- Implemented using a **Hash Table**.

---

# Common Operations

## 1. Insert an Element

```cpp
unordered_set<int> st;

st.insert(10);
st.insert(20);
st.insert(30);
```

Output

```text
{10, 20, 30}
```

---

## 2. Duplicate Insertion

```cpp
st.insert(20);
```

Nothing changes because `20` already exists.

Output

```text
{10, 20, 30}
```

---

## 3. Search for an Element

```cpp
if (st.find(20) != st.end())
{
    cout << "Found";
}
```

If the element exists:

```text
find() != end()
```

Otherwise:

```text
find() == end()
```

---

## 4. Remove an Element

```cpp
st.erase(20);
```

Now the set contains:

```text
{10, 30}
```

---

## 5. Size

```cpp
cout << st.size();
```

Returns the number of unique elements.

---

## 6. Check if Empty

```cpp
if (st.empty())
{
    cout << "Set is empty";
}
```

---

## 7. Clear the Set

```cpp
st.clear();
```

Removes all elements.

---

# Traversing an Unordered Set

```cpp
for (int num : st)
{
    cout << num << " ";
}
```

Example Output

```text
30 10 20
```

**Note:** The order is not guaranteed.

---

# Time Complexity

| Operation | Average Case |
| --------- | -----------: |
| Insert    |         O(1) |
| Search    |         O(1) |
| Delete    |         O(1) |
| Traverse  |         O(n) |

Worst-case complexity can become **O(n)** because of hash collisions, but this is uncommon.

---

# Space Complexity

```text
O(n)
```

where `n` is the number of stored elements.

---

# `unordered_set` vs `set`

| Feature        | `unordered_set` | `set`          |
| -------------- | --------------- | -------------- |
| Implementation | Hash Table      | Red-Black Tree |
| Ordering       | No              | Yes (Sorted)   |
| Insert         | O(1) average    | O(log n)       |
| Search         | O(1) average    | O(log n)       |
| Delete         | O(1) average    | O(log n)       |

Use `unordered_set` when ordering is **not** required.

Use `set` when elements need to remain sorted.

---

# Important Member Functions

| Function    | Description                                      |
| ----------- | ------------------------------------------------ |
| `insert()`  | Inserts an element                               |
| `find()`    | Searches for an element                          |
| `erase()`   | Removes an element                               |
| `count()`   | Returns `1` if the element exists, otherwise `0` |
| `size()`    | Returns the number of elements                   |
| `empty()`   | Checks whether the set is empty                  |
| `clear()`   | Removes all elements                             |
| `reserve()` | Pre-allocates buckets to reduce rehashing        |

---

# Understanding `insert().second`

One useful feature of `unordered_set` is that `insert()` returns a `pair`.

```cpp
auto result = st.insert(10);
```

Return type:

```cpp
pair<iterator, bool>
```

- `result.first` → Iterator pointing to the element.
- `result.second` → Indicates whether insertion succeeded.

Example:

```cpp
unordered_set<int> st;

cout << st.insert(10).second << endl; // true
cout << st.insert(10).second << endl; // false
```

Output

```text
1
0
```

This is useful for detecting duplicates.

Example:

```cpp
if (!st.insert(num).second)
{
    return true;
}
```

Meaning:

- If insertion succeeds → continue.
- If insertion fails → duplicate found.

---

# Why Use `reserve()`?

```cpp
unordered_set<int> st;
st.reserve(1000);
```

`reserve()` allocates space for buckets in advance.

Benefits:

- Reduces internal rehashing.
- Slightly improves performance.
- Useful when the approximate number of elements is known.

---

# Common Mistakes

## 1. Expecting Sorted Order

```cpp
unordered_set<int> st;
```

The order of elements is unpredictable.

If sorted order is needed, use `set`.

---

## 2. Storing Duplicate Elements

```cpp
st.insert(5);
st.insert(5);
```

Only one `5` is stored.

---

## 3. Forgetting the Header File

Always include:

```cpp
#include <unordered_set>
```

---

# Applications of `unordered_set`

- Detecting Duplicate Elements
- Removing Duplicates
- Fast Membership Checking
- Graph Algorithms
- Breadth First Search (Visited Set)
- Depth First Search (Visited Set)
- Longest Consecutive Sequence
- Cycle Detection
- Caching

---

# Example: Contains Duplicate

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

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

# Key Takeaways

- `unordered_set` stores **only unique elements**.
- Duplicate insertions are ignored.
- Uses a **Hash Table** internally.
- Provides **O(1)** average insertion, deletion, and lookup.
- `insert().second` is a clean way to detect duplicates.
- `reserve()` can improve performance by reducing rehashing.
- Elements are **not stored in sorted order**.

---

# Problems Where I Used This Concept

- ✅ LeetCode #217 — Contains Duplicate
- ⬜ Longest Consecutive Sequence
- ⬜ Happy Number
- ⬜ Intersection of Two Arrays
- ⬜ Find the Difference
- ⬜ Jewels and Stones

---

# Revision Tip

Whenever a problem asks:

- "Does this element already exist?"
- "Remove duplicates."
- "Store only unique values."
- "Fast membership checking."

Think about using an **`unordered_set`**.
