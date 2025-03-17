// Leetcode 2206. Divide Array Into Equal Pairs

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto &x : nums)
            mp[x]++;

        for (auto &x : mp)
        {
            if (x.second % 2 != 0)
                return false;
        }

        return true;
    }
};

// Explaination:

// We are given an array of integers. We need to divide the array into pairs such that each pair has the same sum. We need to return true if it is possible to divide the array into pairs such that each pair has the same sum. Otherwise, we need to return false.
