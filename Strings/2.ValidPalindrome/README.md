# Valid Palindrome (LeetCode 125)

## Problem Statement

Given a string `s`, determine whether it is a palindrome after converting all uppercase letters into lowercase and removing all non-alphanumeric characters.

A palindrome is a sequence that reads the same forward and backward.

---

## Examples

### Example 1

**Input**

```text
s = "A man, a plan, a canal: Panama"
```

**Output**

```text
true
```

**Explanation**

After removing non-alphanumeric characters and converting to lowercase:

```text
amanaplanacanalpanama
```

This reads the same forward and backward.

---

### Example 2

**Input**

```text
s = "race a car"
```

**Output**

```text
false
```

---

## Approach

This problem can be solved efficiently using the **Two Pointer** technique.

- Initialize one pointer at the beginning of the string (`left`) and another at the end (`right`).
- Skip all characters that are not letters or digits using `isalnum()`.
- Compare the lowercase versions of the current characters using `tolower()`.
- If the characters are different, the string is not a palindrome.
- Otherwise, move both pointers toward the center.
- Continue until the pointers meet or cross.

This approach avoids creating an additional string and uses constant extra space.

---

## Algorithm

1. Set `left = 0` and `right = s.length() - 1`.
2. While `left < right`:
   - Move `left` forward until it points to an alphanumeric character.
   - Move `right` backward until it points to an alphanumeric character.
   - Compare `tolower(s[left])` and `tolower(s[right])`.
   - If they differ, return `false`.
   - Otherwise, increment `left` and decrement `right`.

3. If all comparisons succeed, return `true`.

---

## Time Complexity

- **Time:** `O(n)`

Each pointer moves across the string at most once.

---

## Space Complexity

- **Space:** `O(1)`

No extra data structures are used.

---

## Key Concepts Learned

- Two Pointer Technique
- Character manipulation in C++
- `isalnum()` for checking letters and digits
- `tolower()` for case-insensitive comparison
- Efficient string traversal
- Understanding why nested pointer movement is still `O(n)`

---

## C++ STL Functions Used

| Function        | Purpose                                          |
| --------------- | ------------------------------------------------ |
| `isalnum(char)` | Checks whether a character is a letter or digit. |
| `tolower(char)` | Converts an uppercase letter to lowercase.       |

---

## What I Learned

- Not every problem that looks like a stack problem requires a stack.
- Two pointers can often reduce space complexity from `O(n)` to `O(1)`.
- Nested loops do not always imply `O(n²)`; since each pointer moves only in one direction, the overall complexity remains `O(n)`.

---

## Tags

`Two Pointers` `String` `Palindrome` `Easy` `C++`
