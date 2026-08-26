#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();

        string res = "";

        int left = 0;
        int count1 = 0;

        for (int right = 0; right < n; right++)
        {
            if (s[right] == '1')
            {
                count1++;
            }

            while (count1 == k)
            {
                // Remove unnecessary leading zeroes
                if (s[left] == '0')
                {
                    left++;
                    continue;
                }

                string cur = s.substr(left, right - left + 1);

                // Update answer if current substring is better
                if (res == "" ||
                    cur.length() < res.length() ||
                    (cur.length() == res.length() && cur < res))
                {
                    res = cur;
                }

                // Remove the leftmost 1
                if (s[left] == '1')
                {
                    count1--;
                }

                left++;
            }
        }

        return res;
    }
};