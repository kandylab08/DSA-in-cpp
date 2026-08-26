# 🧩 LeetCode 2904 — Shortest and Lexicographically Smallest Beautiful String

## 📌 Problem

Given a binary string `s` and an integer `k`, find the **shortest beautiful substring** of `s`.

A substring is called beautiful if it contains exactly `k` occurrences of `'1'`.

If multiple beautiful substrings have the same minimum length, return the **lexicographically smallest** one.

If no such substring exists, return an empty string.

---

## 💡 Approach

This problem can be solved using the **Sliding Window** technique.

We maintain a window using two pointers:

```text
left  → beginning of the window
right → end of the window
```

We also keep track of the number of `'1'` characters inside the current window.

```cpp
int count1 = 0;
```

As `right` moves forward, we increase `count1` whenever we encounter a `'1'`.

Once the window contains exactly `k` ones:

```cpp
while (count1 == k)
```

we try to shrink the window from the left.

---

## 🔑 Key Insight

When the window contains exactly `k` ones, any leading zeroes can be removed without changing the number of ones.

For example:

```text
00010100
```

If we need exactly `2` ones, the leading zeroes are unnecessary:

```text
000101
   ↑
```

Removing them produces a shorter valid substring.

Therefore, whenever `s[left] == '0'`, we simply move `left` forward.

Once `s[left] == '1'`, we have reached the shortest possible window for the current `right`.

---

## 🧠 Algorithm

1. Initialize:

   * `left = 0`
   * `count1 = 0`
   * `res = ""`

2. Expand the window using `right`.

3. Whenever `s[right] == '1'`, increment `count1`.

4. When the window contains exactly `k` ones:

   * Remove leading zeroes.
   * Construct the current substring.
   * Compare it with the best answer found so far.
   * Remove the leftmost `'1'` and continue searching.

5. For comparison:

   * Prefer the shorter substring.
   * If two substrings have the same length, prefer the lexicographically smaller one.

6. Return `res`.

---

## 🔍 Example

### Input

```text
s = "100011001"
k = 3
```

The window expands until it contains exactly `3` ones.

The algorithm then removes unnecessary leading zeroes and evaluates the shortest valid substring.

If multiple substrings have the same length, the lexicographically smaller one is selected.

---

## ⏱️ Complexity

### Time Complexity

The sliding-window movement itself is `O(n)`.

However, the implementation creates substrings using:

```cpp
s.substr(...)
```

and compares strings, so the practical worst-case complexity can be **O(n²)**.

### Space Complexity

The temporary substring and result can require up to:

```text
O(n)
```

space.

---

## 📚 What I Learned

* Practiced the **Sliding Window** technique again.
* Learned how to maintain a window containing exactly `k` occurrences of a character.
* Learned that unnecessary leading zeroes can be removed without affecting the number of ones.
* Practiced shrinking a window while maintaining a specific condition.
* Practiced comparing strings based on:

  1. Length
  2. Lexicographical order
* Reinforced the general sliding-window pattern:

```text
Expand → Check Condition → Shrink → Evaluate
```

---

## 🔥 Connection to Day 31

This problem was excellent additional practice after **LeetCode 424 — Longest Repeating Character Replacement**.

In both problems, the core pattern is:

```text
left = 0

for right:
    expand window

    while window violates/fulfills condition:
        adjust left

    update answer
```

The important lesson is that **sliding window is not one fixed algorithm**.

The condition that controls the window changes depending on the problem.

### Day 31 Sliding Window Practice

```text
LeetCode 424
Longest Repeating Character Replacement
        ↓
Frequency-based Sliding Window

LeetCode 2904
Shortest and Lexicographically Smallest Beautiful String
        ↓
Count-based Sliding Window
```

---

## 🚀 Day 31 Progress

```text
Sliding Window Pattern       ✅
Frequency Counting            ✅
Window Expansion              ✅
Window Shrinking              ✅
Maintaining Window Condition  ✅
Lexicographical Comparison    ✅
```

**Another sliding-window problem solved. Another pattern becoming natural. 🔥**
