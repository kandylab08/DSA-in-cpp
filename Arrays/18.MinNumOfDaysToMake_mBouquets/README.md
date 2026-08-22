# 🚀 Day 28 — Minimum Number of Days to Make m Bouquets

## 🧩 Problem

You are given an array `bloomDay`, where `bloomDay[i]` represents the day the `i-th` flower will bloom.

You need to make exactly `m` bouquets.

Each bouquet requires `k` **adjacent flowers**, and a flower can only be used once.

Return the **minimum number of days** needed to make all `m` bouquets.

If it is impossible, return `-1`.

---

## 💡 Approach — Binary Search on Answer

Instead of trying to directly find the minimum number of days, we ask:

> **Can we make at least `m` bouquets if we wait `X` days?**

This creates a monotonic condition:

```text
Days:       1   2   3   4   5   6   ...
Possible:   ❌  ❌  ❌  ✅  ✅  ✅  ...
                         ↑
                       Answer
```

If we can make the required bouquets in `X` days, then we can also make them in any number of days greater than `X`.

Therefore, we can apply binary search.

---

## 🔍 Binary Search Range

```cpp
low = minimum bloom day
high = maximum bloom day
```

The answer must lie between these two values.

For every `mid`:

* Check which flowers have bloomed by day `mid`.
* Count consecutive bloomed flowers.
* Whenever we collect `k` adjacent flowers, form one bouquet.
* If the number of bouquets reaches `m`, `mid` is feasible.
* Otherwise, we need more days.

---

## ⚠️ Important Edge Case

Each bouquet requires `k` flowers.

Therefore, we need at least:

```text
m × k
```

flowers.

If:

```cpp
(long long)m * k > n
```

then forming the required bouquets is impossible.

Return:

```cpp
-1
```

---

## 🧠 Key Insight

The most important part of the problem is maintaining **adjacency**.

When a flower has not bloomed yet:

```cpp
adjacentCount = 0;
```

This breaks the current sequence.

When `k` consecutive bloomed flowers are found:

```cpp
bouquetCount++;
adjacentCount = 0;
```

This forms one bouquet and starts searching for the next one.

---

## ⏱️ Complexity

### Time Complexity

```text
O(n × log(maxBloomDay - minBloomDay))
```

We scan the array for every binary-search iteration.

### Space Complexity

```text
O(1)
```

Only a few variables are used apart from the input array.

---

## 📚 Pattern Learned

### Binary Search on Answer

This problem reinforces the pattern:

```text
1. Identify the possible answer range.
2. Define a feasibility/check function.
3. Check whether mid is possible.
4. If possible → search left.
5. If impossible → search right.
6. Return the first feasible answer.
```

This pattern is useful for problems involving:

* Minimum possible maximum
* Maximum possible minimum
* Scheduling
* Allocation
* Capacity
* Speed
* Time
* Days

---

## 🏆 Day 28 Takeaway

> **Don't always binary search an array. Sometimes binary search the answer itself.**

Another Binary Search on Answer problem conquered. 🔥

**Day 28 — CLEARED ✅**

### 📈 DSA Grind

**Day 28 / 100+**

Keep grinding. Keep learning. Keep improving. 🚀
