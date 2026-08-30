# 📅 Day 35 — Best Time to Buy and Sell Stock

## 🧩 Problem

**LeetCode 121 — Best Time to Buy and Sell Stock**

**Difficulty:** Easy 🟢
**Pattern:** Greedy / One Pass
**Language:** C++

---

## 📝 Problem Statement

Given an array `prices` where `prices[i]` represents the price of a stock on the `i`-th day, find the maximum profit that can be achieved by buying on one day and selling on a later day.

If no profit can be made, return `0`.

### Example

```text
Input:  prices = [7,1,5,3,6,4]
Output: 5
```

Buy at `1` and sell at `6`:

```text
Profit = 6 - 1 = 5
```

---

## 💡 Approach

The key observation is that for every selling price, we want to know the **lowest buying price seen before it**.

So I maintain two variables:

* `min_price` → minimum stock price seen so far
* `max_profit` → maximum profit found so far

For every price:

1. If it is smaller than `min_price`, update `min_price`.
2. Otherwise, calculate the profit from buying at `min_price` and selling at the current price.
3. Update `max_profit` if this profit is larger.

### 🔑 Core Idea

Instead of checking every possible buy/sell pair, keep track of the best buying opportunity while scanning the array once.

---

## ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

Only one pass through the array is required, with constant extra space.

---

## 🧠 What I Learned

* How to optimize a brute-force buy/sell comparison into a single pass.
* How maintaining the **minimum value seen so far** can eliminate unnecessary comparisons.
* Recognized another example of a **greedy one-pass strategy**.
* Reinforced the importance of tracking only the information needed for future decisions.

---

## 🏆 Day 35 Takeaway

> **"Keep the cheapest buying price seen so far, and use every future price as a potential selling price."**


### 🔥 Progress

**Day 35 / 35 — Completed ✅**