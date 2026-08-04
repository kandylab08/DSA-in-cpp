# Product of Array Except Self (LeetCode 238)

## Problem

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

**Constraints**

* Do not use division.
* Solve the problem in **O(n)** time.
* Use **O(1)** extra space (excluding the output array).

---

## Approach

The key idea is to compute the product of all elements to the left and right of every index.

### Step 1: Prefix Products

* Traverse the array from left to right.
* Store the product of all previous elements in the answer array.

### Step 2: Suffix Products

* Traverse the array from right to left.
* Maintain a variable `rightProduct` that stores the product of all elements to the right of the current index.
* Multiply the current answer with `rightProduct`.
* Update `rightProduct` by multiplying it with the current element.

This eliminates the need for separate prefix and suffix arrays while achieving constant extra space.

---

## Algorithm

1. Initialize an answer array with the first value as `1`.
2. Fill the answer array with prefix products.
3. Initialize `rightProduct = 1`.
4. Traverse from right to left:

   * Multiply `answer[i]` by `rightProduct`.
   * Update `rightProduct *= nums[i]`.
5. Return the answer array.

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` extra space (excluding the output array)

---

## Concepts Learned

* Prefix Product
* Suffix Product
* Two-pass array traversal
* Space optimization
* Eliminating nested loops
* Interview pattern for left-right computations

---

## Key Takeaway

Whenever a problem requires information from both the left and right side of every element, think about the **Prefix + Suffix** pattern. Many interview questions can be optimized using this technique.
