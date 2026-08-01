# Pair in C++

## What is Pair?

A `pair` is an STL container that stores exactly two values together.

Both values can be of the same or different data types.

---

## Header

```cpp
#include <utility>
```

> `#include <bits/stdc++.h>` already includes this header.

---

## Declaration

```cpp
pair<int, int> p;
```

---

## Initialization

```cpp
pair<int, int> p = {10, 20};
```

or

```cpp
pair<int, int> p(10, 20);
```

or

```cpp
pair<int, int> p = make_pair(10, 20);
```

---

## Accessing Values

```cpp
cout << p.first;
cout << p.second;
```

---

## Pair with Different Data Types

```cpp
pair<int, string> student;

student = {1, "Kundan"};
```

---

## Vector of Pairs

```cpp
vector<pair<int,int>> v;
```

Insert

```cpp
v.push_back({1,100});
v.push_back({2,200});
```

Traverse

```cpp
for(auto x : v)
{
    cout << x.first << " " << x.second << endl;
}
```

---

## Pair inside Map

Each element inside

```cpp
unordered_map<int,int>
```

is stored as

```cpp
pair<const int,int>
```

Example

```cpp
for(auto x : mp)
{
    cout << x.first;
    cout << x.second;
}
```

---

## Common Uses

- Coordinates `(x,y)`
- Element & Frequency
- Graph `(node, weight)`
- Returning two values from a function
- Sorting based problems

---

## Time Complexity

Accessing

```cpp
first
second
```

takes

**O(1)**

---

## Interview Tips

Remember:

- `pair` stores only two values.
- Access using `.first` and `.second`.
- Frequently used with vectors, maps, priority queues, and graphs.