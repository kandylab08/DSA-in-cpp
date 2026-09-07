# 🚀 Day 40 — Implement Queue using Stacks

## 🧩 Problem

**LeetCode 232 — Implement Queue using Stacks**

**Difficulty:** Easy
**Topic:** Stack / Queue / Data Structures

---

## 📌 Problem Statement

Implement a FIFO (First In, First Out) queue using only two stacks.

The queue should support the following operations:

* `push(x)` — Add an element to the back of the queue.
* `pop()` — Remove and return the element at the front.
* `peek()` — Return the element at the front.
* `empty()` — Check whether the queue is empty.

---

## 💡 Approach

The key idea is to use **two stacks** to simulate the behavior of a queue.

Since stacks follow **LIFO (Last In, First Out)** order, transferring elements from one stack to another reverses their order.

For example:

```text
Input Stack:   [1, 2, 3]

Transfer → 

Output Stack:  [3, 2, 1]
                          ↑
                        top
```

This makes the oldest element (`1`) available at the top of the second stack, giving us FIFO behavior.

An optimized implementation transfers elements only when the output stack is empty.

---

## 🧠 Key Learning

* Difference between **FIFO** and **LIFO**
* Using two stacks to simulate a queue
* Understanding how reversing a stack changes access order
* Amortized `O(1)` complexity for queue operations

---

## ⏱️ Complexity

### Time Complexity

* `push()` → **O(1)**
* `pop()` → **Amortized O(1)**
* `peek()` → **Amortized O(1)**
* `empty()` → **O(1)**

### Space Complexity

* **O(n)**

where `n` is the number of elements in the queue.

---

## 💻 My Attempt

I initially implemented the queue using two stacks to maintain the front and back indices, along with an array for storing the elements.

The approach correctly maintained FIFO behavior, but it did not satisfy the problem's intended constraint of using **only two stacks for the queue storage**.

This helped reinforce the distinction between:

> **Making something work** vs. **solving it under the given constraints.**

---

## 🔥 Day 40 Progress

Another day of consistent DSA practice completed!

**40 Days → 40 Problems → Still Going 🚀**

#DSA #LeetCode #100DaysOfCode #CodingJourney #CPlusPlus #ProblemSolving