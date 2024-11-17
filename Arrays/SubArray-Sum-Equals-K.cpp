// Leetcode 560: Subarray sum Equals k

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        prefix[0] = 0;
        unordered_map<long, int> prefixCount;
        prefixCount[0] = 1;
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            long target = prefix[i] - k;
            if (prefixCount.find(target) != prefixCount.end())
            {
                count += prefixCount[target];
            }
            prefixCount[prefix[i]]++;
        }

        return count;
    }
};

// Explaination

// The idea is to use a hashmap to store the prefix sum and the number of times it has occured.
// We iterate over the array and calculate the prefix sum at each index.
// We then check if the prefix sum - k has occured before. If it has, we increment the count by the number of times it has occured.
// We then increment the count of the current prefix sum in the hashmap.
// Finally, we return the count.
