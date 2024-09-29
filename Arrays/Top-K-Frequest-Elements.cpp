// Leetcode 347. Top K Frequent Elements

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1);
        for (auto &x : nums)
            mp[x]++;
        for (const auto &x : mp)
            freq[x.second].push_back(x.first);
        vector<int> ans;
        int m = freq.size() - 1;
        for (int i = m; i > 0 && ans.size() < k; i--)
        {
            for (int n : freq[i])
            {
                ans.push_back(n);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};

// Explaination

// The idea is to use a hash map to store the frequency of each element in the input array.
// Create a vector of vectors to store the elements based on their frequency.
// For each element in the input array, increment the frequency in the hash map.
// Iterate over the hash map and store the elements in the frequency vector based on their frequency.
// Iterate over the frequency vector from the end and push the elements into the answer vector until the size of the answer vector is equal to k.
// Return the answer vector.
