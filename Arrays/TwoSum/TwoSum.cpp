class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hmp;
        hmp.reserve(nums.size());

        const int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            auto it = hmp.find(target - nums[i]);

            if (it != hmp.end())
                return {it->second, i};

            hmp.emplace(nums[i], i);
        }

        return {};
    }
};