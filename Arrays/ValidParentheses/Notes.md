# Valid Parentheses (LeetCode #20)

## Problem Statement

Given a string `s` containing only the characters:

- `(`
- `)`
- `{`
- `}`
- `[`
- `]`

Determine whether the input string is valid.

A string is considered valid if:

- Every opening bracket has a corresponding closing bracket.
- Brackets are closed in the correct order.
- Every closing bracket matches the most recent unmatched opening bracket.

---

## Examples

### Example 1

```text
Input: "()"
Output: true
```

### Example 2

```text
Input: "()[]{}"
Output: true
```

### Example 3

```text
Input: "(]"
Output: false
```

### Example 4

```text
Input: "([)]"
Output: false
```

### Example 5

```text
Input: "{[]}"
Output: true
```

---

# Approach

The problem follows the **Last In, First Out (LIFO)** principle, making a **Stack** the ideal data structure.

### Algorithm

1. Traverse the string from left to right.
2. If the current character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
3. If the current character is a closing bracket:
   - If the stack is empty, return `false`.
   - Otherwise, compare the top element of the stack with the corresponding opening bracket.
   - If they match, pop the stack.
   - Otherwise, return `false`.

4. After processing all characters, the stack should be empty.
   - Empty stack → Valid parentheses.
   - Non-empty stack → Invalid parentheses.

---

# Data Structures Used

- Stack (implemented manually using an array)
- Hash Map (`unordered_map`) for bracket matching

---

# Time Complexity

| Operation             | Complexity |
| --------------------- | ---------- |
| Traversing the string | O(n)       |
| Stack Push            | O(1)       |
| Stack Pop             | O(1)       |
| Hash Map Lookup       | O(1)       |

### Overall Time Complexity

```text
O(n)
```

---

# Space Complexity

In the worst case, all opening brackets are stored in the stack.

```text
O(n)
```

---

# Key Learning Points

- Understanding the **LIFO (Last In, First Out)** principle.
- Practical application of stacks.
- Using a hash map to simplify bracket matching.
- Handling edge cases such as:
  - Empty stack while encountering a closing bracket.
  - Mismatched brackets.
  - Remaining opening brackets after traversal.

---

# Edge Cases Tested

```text
()
()[]{}
(]
([)]
{[]}
(
]
```

---

# My Implementation

Instead of using the C++ STL `stack`, I implemented the stack manually using an array to better understand how stack operations work internally. This helped reinforce the concepts of `push`, `pop`, and stack management before moving on to the STL implementation.

---

# Concepts Practiced

- Stack
- LIFO Principle
- Arrays
- Hash Map (`unordered_map`)
- String Traversal
- Conditional Logic
- Time & Space Complexity Analysis

---

## Status

✅ Solved

**Difficulty:** Easy

**Language:** C++
