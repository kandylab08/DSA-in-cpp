# 🚀 Day 23 — Koko Eating Bananas

## 🧩 Problem

You are given an integer array `piles`, where `piles[i]` represents the number of bananas in the `i-th` pile.

Koko can eat bananas at a speed of `k` bananas per hour. Each hour, she chooses one pile and eats `k` bananas from it. If the pile contains fewer than `k` bananas, she eats all the remaining bananas and spends the rest of the hour idle.

Given `piles` and an integer `h`, return the **minimum integer `k`** such that Koko can eat all the bananas within `h` hours.

### Example

```text
Input:
piles = [3,6,7,11]
h = 8

Output:
4
```

---

## 💡 Approach — Binary Search on Answer

Instead of searching for an element, we perform binary search on the possible **eating speed**.

### Search Range

```text
low = 1
high = max(piles)
```

* `1` is the minimum possible eating speed.
* `max(piles)` is the maximum speed required to finish the largest pile in one hour.

For every possible speed `mid`, calculate how many hours Koko would need.

```cpp
hoursSpent += (pile + mid - 1) / mid;
```

This is equivalent to:

```text
ceil(pile / mid)
```

but avoids floating-point calculations.

### Binary Search Logic

If:

```text
hoursSpent <= h
```

then the current speed is sufficient.

We store it as a possible answer and try a smaller speed:

```cpp
high = mid - 1;
```

Otherwise, Koko is too slow, so we increase the speed:

```cpp
low = mid + 1;
```

---

## 🧪 Test Cases

### Test Case 1

```text
Input:
piles = [3,6,7,11]
h = 8

Output:
4
```

### Test Case 2

```text
Input:
piles = [30,11,23,4,20]
h = 5

Output:
30
```

### Test Case 3

```text
Input:
piles = [30,11,23,4,20]
h = 6

Output:
23
```

### Test Case 4

```text
Input:
piles = [5]
h = 5

Output:
1
```

### Test Case 5

```text
Input:
piles = [10,10,10]
h = 6

Output:
5
```

---

## 📊 Complexity

| Complexity | Analysis               |
| ---------- | ---------------------- |
| ⏱️ Time    | `O(n log(max(piles)))` |
| 💾 Space   | `O(1)`                 |

---

## 🧠 Key Takeaways

* Learned **Binary Search on Answer**.
* The search space doesn't contain array indices; it contains possible answers.
* Used `max(piles)` as the upper bound.
* Used integer arithmetic to calculate ceiling division.
* Used `long long` for the total number of hours.
* When a speed works, search for an even smaller valid speed.

---

## 🔥 DSA Pattern

```text
Binary Search
      ↓
Search on Answer
      ↓
Find Minimum Valid Value
```

### 🎯 Day 23 Status

**✅ Completed**

> Another day. Another pattern mastered.
> **23 days of DSA — and still grinding. 🚀**
