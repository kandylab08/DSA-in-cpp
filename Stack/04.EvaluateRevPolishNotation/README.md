# Evaluate Reverse Polish Notation

## 🧩 Problem

Given an array of strings `tokens` representing an arithmetic expression in **Reverse Polish Notation (RPN)**, evaluate the expression and return the result.

The valid operators are:

* `+` Addition
* `-` Subtraction
* `*` Multiplication
* `/` Division

For division, the result is truncated toward zero.

### Example

**Input:**

```text
["2", "1", "+", "3", "*"]
```

**Evaluation:**

```text
2 + 1 = 3
3 * 3 = 9
```

**Output:**

```text
9
```

---

## 💡 Approach

This problem can be solved efficiently using a **Stack**.

While traversing the tokens:

1. If the token is a number, convert it to an integer and push it onto the stack.
2. If the token is an operator:

   * Pop the second operand.
   * Pop the first operand.
   * Perform the operation.
   * Push the result back onto the stack.
3. After processing all tokens, the top element of the stack is the final answer.

### Important

The order of operands matters for subtraction and division.

For an operator:

```text
n1 op n2
```

we must first pop `n2`, then `n1`.

For example:

```text
["4", "13", "5", "/", "+"]
```

becomes:

```text
13 / 5 = 2
4 + 2 = 6
```

---

## 🧠 Algorithm

```text
Create an empty stack

For every token:
    If token is a number:
        Push token onto stack

    Else:
        n2 = pop stack
        n1 = pop stack

        result = n1 operator n2

        Push result onto stack

Return top of stack
```

---


## ⏱️ Complexity Analysis

Let `n` be the number of tokens.

### Time Complexity

```text
O(n)
```

Each token is processed exactly once.

### Space Complexity

```text
O(n)
```

In the worst case, the stack can contain `O(n)` elements.

---

## 🔑 Key Concepts

* Stack
* Reverse Polish Notation
* Expression Evaluation
* Operand and Operator Processing
* `stoi()`
* Range-based `for` loop
* Operand ordering

---

## 📚 LeetCode

**Problem:** Evaluate Reverse Polish Notation
**LeetCode:** 150
**Difficulty:** Medium
**Topic:** Stack

---

## 🚀 DSA Journey

**Day 16 — Stack**

This problem reinforced the ability to recognize when a **Stack** is naturally suited for evaluating expressions where the most recently encountered operands are required first.
