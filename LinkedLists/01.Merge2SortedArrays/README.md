# 📅 Day 12 - Merge Two Sorted Lists

## 🧩 Problem

**LeetCode 21 - Merge Two Sorted Lists**

**Difficulty:** Easy

---

## 🎯 Objective

Merge two sorted linked lists into a single sorted linked list by reusing the existing nodes.

---

## 💡 Approach

* Created a **dummy node** to simplify handling the head of the merged list.
* Used two pointers to traverse both linked lists simultaneously.
* Compared the current nodes of both lists and attached the smaller node to the merged list.
* Continued until one list was exhausted.
* Connected the remaining nodes from the non-empty list to the merged list.
* Returned `dummy->next` as the head of the final merged list.

---

## ⏱️ Complexity

* **Time:** `O(n + m)`
* **Space:** `O(1)`

---

## 📚 Concepts Learned

* Linked List traversal
* Dummy Node technique
* Two Pointer approach
* In-place merging of linked lists
* Efficient pointer manipulation

---

## 🚀 Key Takeaway

Using a dummy node eliminates special handling for the head of the merged list, resulting in cleaner and more maintainable code. This problem is a foundational linked list pattern that appears in many advanced interview questions.

---

### Status

✅ Solved independently
