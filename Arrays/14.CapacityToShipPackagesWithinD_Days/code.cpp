#include <bits/stdc++.h>
using namespace std;

int No_of_days_required(int capacity, vector<int> &weights)
{
    int day = 1;
    int cur_weight = 0;

    for (int w : weights)
    {
        if (w + cur_weight <= capacity)
            cur_weight += w;
        else
        {
            day++;
            cur_weight = w;
        }
    }

    return day;
}

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (No_of_days_required(mid, weights) <= days)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};