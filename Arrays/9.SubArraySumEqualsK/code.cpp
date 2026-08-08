class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        int count = 0;
        int n= nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }
            prefixSum[sum]++;
        }
        return count;
    }
};