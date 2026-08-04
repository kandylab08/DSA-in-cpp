class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int tar = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum == tar)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if (tar < sum)
                    --r;
                else
                    l++;
            }
        }
        return res;
    }
};