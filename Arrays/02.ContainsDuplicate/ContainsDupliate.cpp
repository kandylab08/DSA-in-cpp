/*
Problem    : Contains Duplicate
Platform   : LeetCode (#217)
Difficulty : Easy

Approach :
Use an unordered_set to store visited elements.
If inserting an element fails, it means the element already exists,
so the array contains a duplicate.

Time Complexity : O(n)
Space Complexity: O(n)
*/
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        unordered_set<int> hs;

        for (int num : nums)
        {
            if (hs.find(num) != hs.end())
                return true;

            hs.insert(num);
        }

        return false;
    }
};