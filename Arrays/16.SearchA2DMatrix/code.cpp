#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        bool res = false;

        int n = matrix[0].size() - 1;
        int m = matrix.size() - 1;

        int low_r = 0;
        int high_r = m;

        while (low_r <= high_r)
        {
            int mid_r = low_r + (high_r - low_r) / 2;

            if (matrix[mid_r][0] > target)
            {
                high_r = mid_r - 1;
            }
            else
            {
                if (matrix[mid_r][n] >= target)
                {
                    int low_c = 0;
                    int high_c = n;

                    while (low_c <= high_c)
                    {
                        int mid_c = low_c + (high_c - low_c) / 2;

                        if (matrix[mid_r][mid_c] == target)
                        {
                            res = true;
                            break;
                        }
                        else if (matrix[mid_r][mid_c] < target)
                        {
                            low_c = mid_c + 1;
                        }
                        else
                        {
                            high_c = mid_c - 1;
                        }
                    }

                    break;
                }
                else
                {
                    low_r = mid_r + 1;
                }
            }
        }

        return res;
    }
};