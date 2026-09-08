# 🚀 Day 41 — Remove All Adjacent Duplicates In String

### 🟢 LeetCode 1047 — Remove All Adjacent Duplicates In String

**Difficulty:** Easy
**Topic:** Stack / String

## 📝 Problem

Given a string `s`, repeatedly remove adjacent duplicate characters until no adjacent duplicates remain.

---

## 💡 Approach 1 — Using `stack<char>`

I processed the string from **right to left** using a stack.

* If the stack is empty or its top character is different from the current character, push the character.
* If the top character is the same as the current character, pop it because the two characters form an adjacent duplicate pair.
* Finally, pop the remaining characters from the stack to construct the answer.

### 💻 Solution

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> res;
        string res_string = "";
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            if (res.empty() || res.top() != s[i]) {
                res.push(s[i]);
            } else {
                res.pop();
            }
        }

        while (!res.empty()) {
            res_string.push_back(res.top());
            res.pop();
        }

        return res_string;
    }
};
```

### ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

Each character is pushed and popped at most once.

---

## 🚀 Approach 2 — Using `string` as a Stack

After solving the problem with `stack<char>`, I realized that a `string` can itself work as a stack.

The required stack operations already exist:

```cpp
push_back()  → push
pop_back()   → pop
back()       → top
empty()      → empty
```

This allows us to process the string from **left to right** and directly build the answer.

* If the current character matches the last character in the result, remove the last character.
* Otherwise, add the current character.
* The resulting string is already the final answer, so no extra reconstruction step is required.

### 💻 Optimized Solution

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for (char c : s) {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};
```

### ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

Each character is added to or removed from `res` at most once.

---

## 🧠 Key Learning

This problem demonstrates the **stack cancellation pattern**:

> When the current element conflicts with the most recently stored element, remove the previous element.

It also reinforced that **the choice of data structure and its implementation can sometimes be simplified without changing the underlying algorithm**.

A `string` can act as a stack when we only need operations from one end.

---

## 🔥 Day 41 Completed!

Another day of consistent DSA practice.

**41 days down — keep going! 🚀**