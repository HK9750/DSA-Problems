// Leetcode 2570. Merge Two 2D Arrays By Summing Values

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> mp;

        auto insertValues = [&](const vector<vector<int>> &nums)
        {
            for (const auto &num : nums)
            {
                int id = num[0];
                int value = num[1];
                mp[id] += value;
            }
        };

        insertValues(nums1);
        insertValues(nums2);

        vector<vector<int>> ans;
        for (const auto &entry : mp)
        {
            ans.push_back({entry.first, entry.second});
        }

        return ans;
    }
};

// Explaination:

// We can use a map to store the sum of values for each id. We can iterate over both arrays and insert the values in the map. Finally, we can iterate over the map and create the answer array.
