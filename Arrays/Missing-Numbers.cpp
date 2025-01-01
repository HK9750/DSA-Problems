// Leetcode 268. Missing Number

// Using Hash Map

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(i) == mp.end())
                return i;
        }
        if (mp.find(n) == mp.end())
            return n;

        return -1;
    }
};

// Optimized Solution (Using math)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum1 = (n * (n + 1)) / 2;
        int sum2 = 0;

        for (int x : nums)
            sum2 += x;
        return sum1 - sum2;
    }
};