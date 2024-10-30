// Leetcode 1671. Minimum Number of Removals to Make Mountain Array

// Longest increasing subsequence (LIS) and Longest decreasing subsequence (LDS) are the two subsequences that we need to find.

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] > nums[j])
                {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (lis[i] > 1 && lds[i] > 1)
            {
                ans = max(ans, lis[i] + lds[i] - 1);
            }
        }

        return n - ans;
    }
};

class Solution
{
public:
    int minimumMountainRemovals(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> LIS(n, 1), LDS(n, 1);

        std::vector<int> dp;
        for (int i = 0; i < n; ++i)
        {
            auto pos = std::lower_bound(dp.begin(), dp.end(), nums[i]);
            if (pos == dp.end())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                *pos = nums[i];
            }
            LIS[i] = dp.size();
        }

        dp.clear();
        for (int i = n - 1; i >= 0; --i)
        {
            auto pos = std::lower_bound(dp.begin(), dp.end(), nums[i]);
            if (pos == dp.end())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                *pos = nums[i];
            }
            LDS[i] = dp.size();
        }

        int max_mountain_length = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            if (LIS[i] > 1 && LDS[i] > 1)
            {
                max_mountain_length = std::max(max_mountain_length, LIS[i] + LDS[i] - 1);
            }
        }

        return n - max_mountain_length;
    }
};
