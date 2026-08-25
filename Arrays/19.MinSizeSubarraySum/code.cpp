class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int cur_sum = 0;
        int res = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            cur_sum += nums[right];

            while (cur_sum >= target)
            {
                res = min(res, right - left + 1);

                cur_sum -= nums[left];
                left++;
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};