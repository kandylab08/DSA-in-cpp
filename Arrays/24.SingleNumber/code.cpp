#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;

        for (auto number : nums)
        {
            res ^= number;
        }

        return res;
    }
};