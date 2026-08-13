class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> p;
        vector<int> res;
        int n = nums.size();
        for (int num : nums)
        {
            freq[num]++;
        }
        for (auto it : freq)
            p.push_back(it);
        sort(p.begin(), p.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });
        for (int i = 0; i < k; i++)
        {
            res.push_back(p[i].first);
        }
        return res;
        
    }
};