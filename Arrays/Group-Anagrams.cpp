// Leetcode 49. Group Anagrams

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() == 0)
            return {};

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (string x : strs)
        {
            string temp = x;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(x);
        }

        for (auto &n : mp)
        {
            ans.push_back(n.second);
        }
        return ans;
    }
};

// Explaination

// The idea is to use a hash map to store the sorted version of each string in the input array.
// For each string in the input array, sort the string and store it in the hash map.
// The key of the hash map is the sorted string, and the value is a vector of strings that are anagrams of the key.
// Finally, iterate over the hash map and push the values into the answer vector.
// Return the answer vector.
