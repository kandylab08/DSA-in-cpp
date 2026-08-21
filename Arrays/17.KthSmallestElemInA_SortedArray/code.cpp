#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[m - 1][n - 1];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (countLessOrEqual(matrix, mid, m, n) >= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }

    int countLessOrEqual(
        const vector<vector<int>> &matrix,
        int target,
        int m,
        int n)
    {
        int count = 0;

        int r = m - 1;
        int c = 0;

        while (r >= 0 && c < n)
        {
            if (matrix[r][c] <= target)
            {
                count += r + 1;
                c++;
            }
            else
            {
                r--;
            }
        }

        return count;
    }
};