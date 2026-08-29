# 🚀 Day 33 — Find All Anagrams in a String

📅 **Date:** August 28, 2026
🧩 **LeetCode:** 438 — Find All Anagrams in a String
🏷️ **Topic:** Sliding Window, Hashing / Frequency Array, Strings

---

## 🧠 Problem

Given two strings `s` and `p`, return a vector containing the **starting indices of all anagrams of `p` in `s`**.

### Example

```text
Input:
s = "cbaebabacd"
p = "abc"

Output:
[0, 6]
```

Explanation:

* `"cba"` is an anagram of `"abc"` → index `0`
* `"bac"` is an anagram of `"abc"` → index `6`

---

## 💡 Approach

I used a **fixed-size sliding window** whose size is equal to the length of `p`.

### Steps

1. Create two frequency arrays of size `26`:

   * `freq_p` → frequency of characters in `p`
   * `freq_s` → frequency of characters in the current window of `s`

2. Build the first window of size `p.length()`.

3. Compare the two frequency arrays.

   * If they are equal, the current window is an anagram, so store its starting index.

4. Slide the window through `s`:

   * Add the new character entering from the right.
   * Remove the character leaving from the left.
   * Move `left` forward.
   * Compare the frequency arrays again.

5. Whenever the frequencies match, add the current window's starting index to the result.

---

## 🔑 Key Idea

The important observation is:

> Two strings are anagrams if and only if their character frequencies are identical.

Since the window always has exactly `p.length()` characters, we only need to maintain its frequency counts while sliding.

```text
Current Window

[left ........ right]

      ↓ slide

   remove ← | → add
```

This avoids creating and checking every substring from scratch.

---

## ⏱️ Complexity

### Time Complexity

```text
O(n × 26) → O(n)
```

The frequency arrays contain only 26 lowercase English letters, so comparing them takes constant time.

### Space Complexity

```text
O(26) → O(1)
```

Only two fixed-size frequency arrays are used.

---

## 📚 What I Learned

* How to use a **fixed-size sliding window** to find multiple valid substrings.
* How character frequency arrays can efficiently detect anagrams.
* How to update a sliding window incrementally instead of rebuilding it.
* The importance of handling edge cases such as `p.length() > s.length()`.
* Most importantly, I was able to **recognize and apply the sliding-window pattern independently** after learning it through previous problems.

---

## 🔥 Day 33 Progress

This problem felt much more natural compared to when I first encountered sliding window.

Instead of starting from scratch, I recognized that this problem was closely related to **Permutation in String (LeetCode 567)** from Day 32.

The main difference was:

```text
Day 32:
Find whether an anagram exists.

Day 33:
Find ALL anagrams.
```

Another successful day in the DSA grind! 🚀

**LeetCode Status: ✅ All Test Cases Passed**