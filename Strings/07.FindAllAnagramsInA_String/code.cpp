#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        if (n2 > n1)
            return {};

        vector<int> freq_s(26, 0);
        vector<int> freq_p(26, 0);
        vector<int> res = {};

        // Build the first window
        for (int i = 0; i < n2; i++) {
            freq_s[s[i] - 'a']++;
            freq_p[p[i] - 'a']++;
        }

        // Check the first window
        if (freq_s == freq_p)
            res.push_back(0);

        int left = 0;

        // Slide the window
        for (int right = n2; right < n1; right++) {
            freq_s[s[right] - 'a']++;
            freq_s[s[left] - 'a']--;

            left++;

            if (freq_s == freq_p)
                res.push_back(left);
        }

        return res;
    }
};