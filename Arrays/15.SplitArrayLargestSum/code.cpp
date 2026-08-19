class Solution
{
public:
    bool canSplit(vector<int> &nums, int k, int mid)
    {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int num : nums)
        {
            if (currentSum + num > mid)
            {
                subarrayCount++;
                currentSum = num;

                if (subarrayCount > k)
                    return false;
            }
            else
            {
                currentSum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int low = 0;
        int high = 0;

        for (int num : nums)
        {
            low = max(low, num);
            high += num;
        }

        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};