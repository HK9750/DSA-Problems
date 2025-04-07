// Leetcode 416. Partition Equal Subset Sum

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 == 1)
            return false;
        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
                if (dp[target])
                    return true;
            }
        }

        return false;
    }
};

// Explaination:
// The detailed approach is basically a 0/1 knapsack problem where we are trying to find if there is a subset of the given array that sums up to half of the total sum of the array.
// 0/1 knapsack problem is a classic dynamic programming problem where we have to find if we can fill a knapsack of a given capacity with the given items. In this case, the items are the elements of the array and the capacity is half of the total sum of the array. We can use a boolean dp array to keep track of whether we can achieve a certain sum with the given elements. The dp array is initialized with false values and dp[0] is set to true because we can always achieve a sum of 0 by not selecting any elements. Then we iterate through each element in the array and update the dp array accordingly. If we can achieve a sum of target, we return true, otherwise we return false.