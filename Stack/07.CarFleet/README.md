# 🚀 Day 20 — Car Fleet 🚗💨

## 🧩 Problem

There are `n` cars traveling toward the same target.

Each car has a starting `position` and a `speed`.

A car cannot pass another car in front of it. If a faster car catches up to a slower car, they become part of the same **car fleet**.

The goal is to determine the total number of car fleets that will arrive at the target.

### Example

```text
Input:
target = 12
position = [10,8,0,5,3]
speed = [2,4,1,1,3]

Output:
3
```

---

## 💡 Approach

I initially thought about processing the cars one by one and removing cars that would eventually merge into the fleet ahead.

### 1. Brute Force — Sorting + `erase()`

Initially, I sorted the cars by position and processed the car closest to the target.

For every car, I compared its remaining time with the car/fleet ahead.

If the car behind could reach the target at the same time or earlier, I removed it from the vector because it would merge with the fleet ahead.

However, I initially used:

```cpp
p.erase(p.begin());
```

This is inefficient because removing the first element of a vector shifts all remaining elements.

This could lead to **O(n²)** time complexity.

### 2. Optimized — Sorting + `pop_back()`

I realized that I could reverse the sorting order and process the cars from the **back of the vector**.

Instead of:

```cpp
p.erase(p.begin());
```

I changed the approach to:

```cpp
p.pop_back();
```

Since `pop_back()` takes **O(1)** time, this removes the unnecessary shifting.

The final approach is:

- Calculate the time required for each car to reach the target.
- Sort cars by position in ascending order.
- Start from the car closest to the target using `p.back()`.
- Compare the arrival time of the current fleet with the car behind.
- If the car behind catches the fleet, remove it.
- Otherwise, it forms a new fleet.

---

## 🔍 Key Insight

The most important observation is that we can determine whether cars form the same fleet by comparing their **arrival times**.

For a car:

```cpp
time = (target - position) / speed;
```

After processing the cars from closest to farthest:

```cpp
if (rem_time[car_no] >= rem_time[car_back])
{
    p.pop_back();
}
```

If the car behind can reach the target in the same amount of time or earlier, it will catch the fleet ahead and become part of the same fleet.

Otherwise, it cannot catch the fleet and forms a **new fleet**.

> **A car with a smaller or equal arrival time than the fleet ahead will eventually catch it.**

---

## ⏱️ Complexity

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

Sorting takes `O(n log n)` time, while processing all the cars takes `O(n)` time.

Using `pop_back()` takes `O(1)` time.

---

## 🧠 What I Learned

- How to solve a problem using **sorting + greedy thinking**.
- How arrival time can determine whether cars form the same fleet.
- Why processing cars from **closest to farthest** makes the problem easier.
- Why `erase(begin())` can make a vector-based approach inefficient.
- How changing the sorting order allowed me to replace `erase()` with `pop_back()`.
- How a small implementation change can improve an `O(n²)` approach to `O(n log n)`.
- Most importantly, how recognizing the cost of individual vector operations can make a big difference in overall complexity.

---

## 🏁 Day 20 Status

**Problem:** Car Fleet  
**Difficulty:** Medium  
**Pattern:** Sorting + Greedy  
**Time:** `O(n log n)`  
**Space:** `O(n)`  
**Status:** ✅ Completed

> **20 days. Still showing up. Still grinding. 🚗🔥**
