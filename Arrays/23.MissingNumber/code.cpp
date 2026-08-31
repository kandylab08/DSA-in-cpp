#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int sum = n * (n + 1) / 2;

        for (auto number : nums)
            sum -= number;

        return sum;
    }
};