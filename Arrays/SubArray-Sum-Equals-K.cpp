// Leetcode 560: Subarray sum Equals k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        prefix[0] = 0;
        unordered_map<long, int> prefixCount;
        prefixCount[0] = 1; 
        int count = 0;

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            long target = prefix[i] - k;
            if (prefixCount.find(target) != prefixCount.end()) {
                count += prefixCount[target];
            }
            prefixCount[prefix[i]]++;
        }

        return count;
    }
};
