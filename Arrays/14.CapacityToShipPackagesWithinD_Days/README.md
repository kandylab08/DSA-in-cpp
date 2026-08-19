# 🚀 Day 24 — Capacity To Ship Packages Within D Days

## 🧩 Problem

You are given an array `weights`, where `weights[i]` represents the weight of the `i`th package.

The packages must be shipped **in the given order** and within `days` days.

Find the **least weight capacity** of the ship that will allow all packages to be shipped within the given number of days.

---

## 💡 Approach

This problem can be solved using **Binary Search on Answer**.

Instead of directly searching for the answer, we search for the minimum possible ship capacity.

### 🔹 Step 1 — Determine the Search Range

The minimum possible capacity must be at least the **heaviest package**:

```cpp
low = max(weights)
```

The maximum possible capacity is the **sum of all package weights**, because the ship could theoretically carry everything in one day:

```cpp
high = sum(weights)
```

Therefore:

```text
low = maximum package weight
high = total weight of all packages
```

---

### 🔹 Step 2 — Calculate Required Days

For a given capacity, simulate the shipping process.

Keep adding packages to the current day while their total weight does not exceed the capacity.

If the next package does not fit:

* Start a new day.
* Set the current weight to that package.

This is handled using the helper function:

```cpp
int No_of_days_required(int capacity, vector<int> &weights)
{
    int day = 1;
    int cur_weight = 0;

    for (int w : weights)
    {
        if (w + cur_weight <= capacity)
            cur_weight += w;
        else
        {
            day++;
            cur_weight = w;
        }
    }

    return day;
}
```

---

### 🔹 Step 3 — Binary Search

For every middle capacity:

* If it can ship all packages within `days`, it is a **valid answer**.

  * Try a smaller capacity.
  * `high = mid`

* If it requires more than `days`, the capacity is too small.

  * Increase the capacity.
  * `low = mid + 1`

Eventually:

```cpp
low == high
```

and that value is the minimum valid capacity.

---

## 🧠 Key Insight

The important observation is:

> If a certain capacity can ship all packages within `days`, then every larger capacity can also do it.

This creates a monotonic search space:

```text
Too Small     Valid
   ❌ ❌ ❌ ❌ | ✅ ✅ ✅ ✅
               ↑
        Minimum Valid Capacity
```

This is why **Binary Search on Answer** works.

---

## ⏱️ Complexity

Let:

* `n` = number of packages
* `S` = sum of all package weights

### Time Complexity

```text
O(n log S)
```

Each binary-search iteration checks all packages in `O(n)` time.

### Space Complexity

```text
O(1)
```

Only constant extra space is used.

---

## 🎯 What I Learned

* How to identify **Binary Search on Answer** problems.
* How to define the minimum and maximum possible answer.
* How to build a greedy feasibility check.
* How monotonicity helps reduce a linear search to binary search.
* The pattern of finding the **minimum valid value** using binary search.

---

## 🏆 Day 24 Complete!

Another day. Another problem. Another algorithmic pattern unlocked. 🔥

**DSA Grind continues. 🚀**
