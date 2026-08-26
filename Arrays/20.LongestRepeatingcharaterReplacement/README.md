# 🚀 Day 31 — Longest Repeating Character Replacement

## 🧩 Problem

Given a string `s` containing uppercase English letters and an integer `k`, you can replace at most `k` characters in the string.

Return the length of the longest substring containing the same letter after performing at most `k` replacements.

**LeetCode:** 424 — Longest Repeating Character Replacement

---

## 💡 Approach

This problem can be solved using the **Sliding Window** technique.

Maintain a window using two pointers:

* `left` → beginning of the window
* `right` → end of the window

Inside the current window, keep track of the frequency of every character.

The important observation is:

```text
Characters that need to be replaced
= Window Length - Most Frequent Character Count
```

Therefore, a window is valid when:

```text
(right - left + 1) - maxCount <= k
```

If the number of required replacements becomes greater than `k`, shrink the window from the left.

---

## 🔑 Key Insight

The character we want to keep does **not** necessarily have to be `s[left]`.

Instead, we keep the **most frequent character in the current window** and replace all the other characters.

For example:

```text
s = "AABAB"
k = 1
```

Consider:

```text
A A B A
```

The most frequent character is `A`.

```text
Window Length = 4
Most Frequent = 3

Replacements = 4 - 3
             = 1
```

Since `1 <= k`, the window is valid.

---

## 🧠 Algorithm

1. Create a frequency array of size `26`.
2. Start `left = 0`.
3. Expand the window using `right`.
4. Increase the frequency of `s[right]`.
5. Update `maxCount`, the highest frequency seen in the current window.
6. If:

```text
window length - maxCount > k
```

shrink the window by moving `left`.
7. Keep track of the maximum valid window length.
8. Return the maximum length.

---

## ⏱️ Complexity

### Time Complexity

```text
O(n)
```

Each character is processed at most a constant number of times.

### Space Complexity

```text
O(26) = O(1)
```

The frequency array contains only 26 characters.

---

## 📚 What I Learned Today

* Learned and applied the **Sliding Window** technique.
* Understood how to maintain a window using `left` and `right`.
* Learned how frequency counting can be combined with sliding window.
* Understood the important formula:

```text
Window Length - Maximum Frequency
```

* Learned how to determine whether a window requires more than `k` replacements.
* Learned that the most frequent character in the window is the one we should preserve.
* Practiced maintaining a valid window while searching for the maximum length.

---

## 🔥 Day 31 Reflection

Today was a big step in recognizing **Sliding Window patterns**.

My first attempt tried to compare characters with `s[left]`, which was not the correct way to determine the number of replacements.

After understanding that the important factor is the **most frequent character inside the window**, I was able to rewrite the solution using:

```text
window length - max frequency <= k
```

The final solution runs in **O(n)** time and **O(1)** space.

### Progress

```text
Day 31 / 31 ✅
Sliding Window ✅
Frequency Counting ✅
O(n) Solution ✅
Pattern Recognition 📈
```

**Another day completed. Another DSA pattern added to the toolkit. 🚀**
