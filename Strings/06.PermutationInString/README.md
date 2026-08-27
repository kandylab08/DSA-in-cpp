# Day 32 — Permutation in String

## 🧩 Problem

**LeetCode 567 — Permutation in String**

Given two strings `s1` and `s2`, determine whether `s2` contains a substring that is a permutation of `s1`.

### Example

```text
Input:
s1 = "ab"
s2 = "eidbaooo"

Output:
true
```

The substring `"ba"` is a permutation of `"ab"`.

---

## 💡 Approach

I used a **Fixed-Size Sliding Window** with frequency arrays.

Since the problem only contains lowercase English letters, I used two arrays of size `26`:

* `s1_count` → frequency of characters in `s1`
* `s2_count` → frequency of characters in the current window of `s2`

### Steps

1. If `s1` is longer than `s2`, return `false`.
2. Build the frequency arrays for:

   * `s1`
   * The first `s1.length()` characters of `s2`
3. Compare both frequency arrays.
4. Slide the window through `s2`:

   * Add the newly included character.
   * Remove the character leaving the window.
5. If the two frequency arrays become equal, a permutation exists.
6. If no window matches, return `false`.

---

## 🔑 Key Insight

A permutation of `s1` must contain **exactly the same character frequencies** as `s1`.

For example:

```text
s1 = "abb"

Frequency:
a → 1
b → 2
```

Therefore, any substring of length `3` containing:

```text
"abb"
"bab"
"bba"
```

has the same frequency array and is a valid permutation.

The sliding window lets us check every possible substring of the required length efficiently.

---

## ⏱️ Complexity

* **Time:** `O(n)`
  The frequency arrays contain only 26 characters, which is constant work.

* **Space:** `O(1)`
  Only two arrays of size 26 are used.

---

## 📚 What I Learned

* Practiced the **fixed-size Sliding Window** technique.
* Learned how frequency arrays can efficiently compare character compositions.
* Understood how to add and remove elements while maintaining a window.
* Recognized that a permutation problem can be converted into a **frequency-matching problem**.
* Strengthened my ability to identify Sliding Window patterns independently.

---

## 🔥 Day 32 Progress

This problem was another important step in understanding Sliding Window.

After discovering the technique while solving problems on Day 29, I have now started recognizing when a **fixed-size window** can be used instead of simply trying to brute force every substring.

**Day 32 completed. 🚀**

**Consistency > Motivation.**

32 days and still grinding. 💪
