class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> grp;
        for (const string &s : strs)
        {
            string pat = s;
            sort(pat.begin(), pat.end());
            grp[pat].push_back(s);
        }
        for (const auto &it : grp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};