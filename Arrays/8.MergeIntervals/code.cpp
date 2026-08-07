class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        vector<int> curInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= curInterval[1])
            {
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
            else
            {
                res.push_back(curInterval);
                curInterval = intervals[i];
            }
        }
        res.push_back(curInterval);
        return res;
    }
};