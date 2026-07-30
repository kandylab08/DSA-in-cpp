# 242. Valid Anagram

## Problem Statement

Given two strings `s` and `t`, determine whether `t` is an anagram of `s`.

An anagram is formed by rearranging the letters of another word using all the original letters exactly once.

---

## Examples

### Example 1

```text
Input:
s = "anagram"
t = "nagaram"

Output:
true
```

### Example 2

```text
Input:
s = "rat"
t = "car"

Output:
false
```

---

# Approach

## Idea

If two strings are anagrams:

- Every character appears the same number of times in both strings.
- Count the frequency of each character in the first string.
- Decrease the frequency while traversing the second string.
- If every frequency becomes zero, the strings are anagrams.

---

# Algorithm

1. If the lengths are different, return `false`.
2. Create a frequency map.
3. Traverse the first string and increment the count of every character.
4. Traverse the second string and decrement the count.
5. Check whether every frequency is zero.
6. If yes, return `true`; otherwise return `false`.

---

# Complexity Analysis

### Time Complexity

**O(n)**

- First traversal → O(n)
- Second traversal → O(n)
- Frequency verification → O(k)

Overall complexity is **O(n)**.

---

### Space Complexity

**O(k)**

where **k** is the number of distinct characters.

If the input contains only lowercase English letters, the auxiliary space is **O(1)** because there are at most 26 different characters.

---

# Optimization

Since the problem guarantees lowercase English letters, an array of size 26 can replace `unordered_map`.

```cpp
int freq[26] = {0};
```

Benefits:

- Faster than hashing
- Constant extra space
- Simpler implementation
- Preferred in interviews

---

# Concepts Learned

- Frequency Counting
- Hash Map (`unordered_map`)
- Character Frequency
- String Traversal
- Time and Space Complexity Analysis
- Optimizing Hash Map solutions using arrays

---

# Common Mistakes

- Forgetting to compare string lengths first.
- Decrementing the wrong string.
- Using `map.size()` to determine whether frequencies became zero.
- Forgetting to verify every frequency after processing both strings.

---

# Interview Tip

If the interviewer specifies that the strings contain only lowercase English letters, use a frequency array of size 26 instead of an `unordered_map`. It is faster and uses constant extra space.
