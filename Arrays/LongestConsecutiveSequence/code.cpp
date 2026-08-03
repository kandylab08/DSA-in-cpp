class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(const int &num:nums) mp.insert(num);
        int largestSeq = 0;
        for (int num : mp)
        {
            if (mp.find(num - 1) == mp.end())
            {
                int curNum = num;
                int curSeq = 1;
                while (mp.find(curNum + 1) != mp.end())
                {
                    curNum += 1;
                    curSeq += 1;
                }
                if (curSeq > largestSeq)
                    largestSeq = curSeq;
            }
        }
        return largestSeq;
        
    }
};