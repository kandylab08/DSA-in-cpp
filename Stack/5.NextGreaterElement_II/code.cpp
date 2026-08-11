class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<int> stck;
        for (int i = 0; i < 2 * n; ++i)
        {
            if (i < n)
            {
                while (!stck.empty() && nums[i] > nums[stck.back()])
                {
                    res[stck.back()] = nums[i];
                    stck.pop_back();
                }

                stck.push_back(i);
            }
            else
            {
                while (!stck.empty() && nums[i % n] > nums[stck.back()])
                {
                    res[stck.back()] = nums[i % n];
                    stck.pop_back();
                }
            }
        }

        return res;
    }
};