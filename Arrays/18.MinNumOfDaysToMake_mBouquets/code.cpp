#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeBouquets(int days, vector<int> &bloomDay, int m, int k)
    {
        int bouquetCount = 0;
        int adjacentCount = 0;

        for (int flower : bloomDay)
        {
            if (flower <= days)
            {
                adjacentCount++;

                if (adjacentCount == k)
                {
                    bouquetCount++;
                    adjacentCount = 0;
                }
            }
            else
            {
                adjacentCount = 0;
            }
        }

        return bouquetCount >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        if ((long long)m * k > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(mid, bloomDay, m, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};