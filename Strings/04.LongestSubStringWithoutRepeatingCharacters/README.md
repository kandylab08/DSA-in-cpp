# 🚀 Day 29 — Longest Substring Without Repeating Characters

## 🧩 Problem

Given a string `s`, find the length of the longest substring without repeating characters.

### Example

```text
Input:  s = "abcabcbb"
Output: 3
```

The longest substring without repeating characters is `"abc"`.

---

## 💡 Approach — Sliding Window

For this problem, I used an `unordered_map` to store the **most recent index** of every character.

I maintained a window using two pointers:

- `left` → beginning of the current valid window
- `right` → current character being processed
- `mp[character]` → most recent index of that character

Whenever I encountered a duplicate character, I moved `left` forward.

The important condition is:

```cpp
if (mp.find(s[right]) != mp.end() &&
    mp[s[right]] >= left)
```

This checks whether the previous occurrence of the character is actually **inside the current window**.

If it is, we move the left boundary:

```cpp
left = mp[s[right]] + 1;
```

Then we update the character's latest position:

```cpp
mp[s[right]] = right;
```

Finally, the current window length is:

```cpp
right - left + 1
```

and we keep track of the maximum window length.

---

## 🧠 Key Insight

The interesting part of today's problem was that I **didn't initially know the Sliding Window pattern**.

I independently thought of maintaining a range of characters and moving the starting position whenever a duplicate appeared.

After solving it, I realized that this approach is actually the classic **Sliding Window technique**.

This was a great reminder that algorithmic patterns are not just templates to memorize — they can often be discovered naturally by understanding the problem.

---

## ⏱️ Complexity

### Time Complexity

```text
O(n)
```

Each character is processed once, with average `O(1)` hash-map operations.

### Space Complexity

```text
O(min(n, charset))
```

The hash map stores the characters present in the string.

---

## 🧪 Test Cases

### Example 1

```text
Input:
"abcabcbb"

Output:
3
```

The longest substring is:

```text
"abc"
```

---

### Example 2

```text
Input:
"bbbbb"

Output:
1
```

The longest substring is:

```text
"b"
```

---

### Example 3

```text
Input:
"pwwkew"

Output:
3
```

One valid longest substring is:

```text
"wke"
```

---

### Edge Case

```text
Input:
""

Output:
0
```

---

## 🔍 Important Concept

### Why do we check `mp[s[right]] >= left`?

Consider:

```text
s = "abba"
```

When we reach the final `a`, its previous occurrence is at index `0`.

But our current window starts at index `2`.

The previous `a` is **outside the current window**.

Therefore, we should NOT move `left` backward.

That's why we check:

```cpp
mp[s[right]] >= left
```

This ensures that only duplicates **inside the current window** affect the window.

---

## 🏆 Day 29 Takeaway

Today was more than just solving another LeetCode problem.

I discovered the **Sliding Window technique on my own** before even knowing that the approach had a name.

That is a huge step in developing problem-solving intuition.

Instead of thinking:

> "This is a Sliding Window problem, so I'll use Sliding Window."

I naturally thought:

> "I need to maintain a valid substring and move the starting point whenever I encounter a duplicate."

And it turned out to be the Sliding Window pattern.

This is exactly the kind of problem-solving intuition I want to develop.

---

## 🚀 Day 29 Progress

- [x] Understood the problem
- [x] Developed the approach independently
- [x] Discovered the Sliding Window pattern
- [x] Implemented the solution
- [x] Passed all LeetCode test cases
- [x] Got accepted on the first try 🎯

---

# 🔥 Day 29 Complete

> **Don't just memorize patterns. Understand problems deeply enough to discover the patterns yourself.**

**28 days → 29 days → still grinding. 🚀**
