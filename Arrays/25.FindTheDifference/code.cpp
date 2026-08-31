#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        int n = t.size();

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                res ^= (t[i] - 'a');
            else
                res ^= (t[i] - 'a') ^ (s[i] - 'a');
        }

        return ('a' + res);
    }
};