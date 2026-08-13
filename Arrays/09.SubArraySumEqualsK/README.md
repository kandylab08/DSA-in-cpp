# Day 14 — Subarray Sum Equals K

## 🧩 Problem

**LeetCode 560 — Subarray Sum Equals K**

Given an integer array `nums` and an integer `k`, return the total number of continuous subarrays whose sum equals `k`.

### Example

```text
Input:
nums = [1, 2, 3]
k = 3

Output:
2
```

The valid subarrays are:

```text
[1, 2]
[3]
```

---

## 💡 Approach

### Prefix Sum + Hash Map

Maintain a running prefix sum:

```text
sum = nums[0] + nums[1] + ... + nums[i]
```

If an earlier prefix sum was:

```text
sum - k
```

then the elements between that earlier position and the current position have a sum of `k`.

Therefore, for every element:

1. Add the current element to `sum`.
2. Check whether `sum - k` exists in the hash map.
3. If it exists, add its frequency to `count`.
4. Store/increment the frequency of the current prefix sum.

We initialize:

```cpp
prefixSum[0] = 1;
```

This allows subarrays starting from index `0` to be counted correctly.

---

## 🧠 Key Formula

```text
Current Prefix Sum - Previous Prefix Sum = k
```

Therefore:

```text
Previous Prefix Sum = Current Prefix Sum - k
```

This gives us the lookup:

```cpp
prefixSum[sum - k]
```

---

## 💻 C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;

        prefixSum[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;

            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }

            prefixSum[sum]++;
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3};
    int k = 3;

    int result = solution.subarraySum(nums, k);

    cout << "Number of subarrays with sum "
         << k << ": " << result << endl;

    return 0;
}
```

### Output

```text
Number of subarrays with sum 3: 2
```

---

## ⏱️ Complexity

| Complexity | Value          |
| ---------- | -------------- |
| Time       | `O(n)` average |
| Space      | `O(n)`         |

---

## 🎯 Pattern Learned

**Prefix Sum + Hash Map**

This pattern is useful for problems involving:

* Subarrays with a target sum
* Counting subarrays
* Range/subarray sum relationships
* Prefix-sum frequency tracking

---

## 📈 Today's Learning

The main takeaway from today's problem was understanding that we don't need to calculate every subarray explicitly.

Instead, we can use:

```text
Prefix Sum + Hash Map
```

to determine how many previous prefix sums can form the required target sum.

### ✅ Status

**Solved independently**

**Pattern:** Prefix Sum + Hash Map

**Difficulty:** Medium

**LeetCode:** 560
