// Leetcode 322. Coin Change

class Solution
{
public:
    int dp[10001];

    int solve(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];

        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int res = solve(coins, amount - coin);
            if (res != INT_MAX)
                minCoins = min(minCoins, res + 1);
        }

        return dp[amount] = minCoins;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};

// Explanation:
// We can solve this problem using a recursive approach. We will try to take each coin and check if we can make the remaining amount using the remaining coins. We will take the minimum of all the possible ways to make the remaining amount. We will use memoization to store the results of the subproblems to avoid recomputation.