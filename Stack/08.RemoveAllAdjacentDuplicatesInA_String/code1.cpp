#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> res;
        string res_string = "";
        int n = s.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (res.empty() || res.top() != s[i])
            {
                res.push(s[i]);
            }
            else
            {
                res.pop();
            }
        }

        while (!res.empty())
        {
            res_string.push_back(res.top());
            res.pop();
        }

        return res_string;
    }
};