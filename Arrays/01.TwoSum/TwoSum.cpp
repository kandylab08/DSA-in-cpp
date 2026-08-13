/*
Problem : Two Sum
Platform : Leetcode (#1)
Difficulty : Easy

Approach :
Use an unordered_map (Hash Map) to store each number along with its index.
For every element, calculate its complement (target - current element) and
check if it already exists in the hash map. If found, return the indices.
Otherwise, store the current element and continue.

Time Complexity : O(n)
Space Complexity : O(n)
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hmp;
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];

            if (hmp.find(complement) != hmp.end())
            {
                return {hmp[complement], i};
            }

            hmp[nums[i]] = i;
        }

        return {};
    }
};