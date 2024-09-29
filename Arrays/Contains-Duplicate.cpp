// Leetcode 217. Contains Duplicate

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int x : nums)
        {
            if (mp.find(x) != mp.end())
                return true;
            mp[x]++;
        }
        return false;
    }
};

// Explaination

// The idea is to use a hash map to store the frequency of each element in the array. If the frequency of any element is greater than 1, then return true. Otherwise, return false.
