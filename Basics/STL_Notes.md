# C++ STL Notes

These are important C++ STL concepts learned while solving LeetCode problems.

---

# 1. sort()

### Header

```cpp
#include <algorithm>
```

### Syntax

```cpp
sort(first_iterator, last_iterator);
```

### Example

```cpp
string s = "tea";
sort(s.begin(), s.end());

cout << s;
```

Output

```text
aet
```

### Time Complexity

**O(n log n)**

---

# 2. begin() and end()

Every STL container provides these functions.

```cpp
container.begin()
```

Returns an iterator pointing to the first element.

```cpp
container.end()
```

Returns an iterator pointing **one position after** the last element.

Example

```cpp
vector<int> v = {4,2,5};

sort(v.begin(), v.end());
```

---

# 3. Range-Based For Loop

Traditional loop

```cpp
for(int i = 0; i < v.size(); i++)
{
    cout << v[i];
}
```

Range-based loop

```cpp
for(int x : v)
{
    cout << x;
}
```

Cleaner and easier to read.

---

# 4. References (&)

Without reference

```cpp
for(string s : strs)
```

Creates a copy of every string.

With reference

```cpp
for(string &s : strs)
```

Works on the original string.

---

# 5. const Reference

```cpp
for(const string &s : strs)
```

Advantages

* No copying
* Faster
* Prevents accidental modification

Preferred for read-only loops.

---

# 6. auto Keyword

Instead of writing long types

```cpp
unordered_map<string, vector<string>>::iterator it;
```

Use

```cpp
auto it = mp.begin();
```

The compiler automatically determines the type.

---

# 7. unordered_map

Header

```cpp
#include <unordered_map>
```

Syntax

```cpp
unordered_map<Key, Value> mp;
```

Example

```cpp
unordered_map<string, vector<string>> groups;
```

Stores

```text
"aet" -> ["eat","tea","ate"]
```

Access value

```cpp
groups[key]
```

---

# 8. push_back()

Adds an element to the end of a vector.

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
```

Result

```text
10 20
```

---

# 9. Common Headers

| Header            | Purpose                   |
| ----------------- | ------------------------- |
| `<iostream>`      | cin, cout                 |
| `<vector>`        | vector                    |
| `<string>`        | string                    |
| `<algorithm>`     | sort(), reverse(), find() |
| `<unordered_map>` | unordered_map             |
| `<unordered_set>` | unordered_set             |
| `<stack>`         | stack                     |
| `<queue>`         | queue                     |
| `<map>`           | map                       |
| `<set>`           | set                       |

---

# Key Takeaways

* `sort()` requires `<algorithm>`.
* `begin()` points to the first element.
* `end()` points one position after the last element.
* `const Type&` avoids copying while preventing modification.
* `auto` lets the compiler infer complex types.
* `unordered_map` stores data as **Key → Value** pairs.
