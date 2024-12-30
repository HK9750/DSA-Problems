// Leetcode 2466. Count Ways to Build Good Strings

// Khandaani Tareeqa Recursion + Memoization

class Solution
{
public:
    const int mod = 1e9 + 7;
    int dp[100002];

    int solve(int low, int high, int zero, int one, int len)
    {
        if (len > high)
            return 0;
        if (dp[len] != -1)
            return dp[len];
        int total = (len >= low) ? 1 : 0;
        total += solve(low, high, zero, one, len + zero);
        total += solve(low, high, zero, one, len + one);
        return dp[len] = total % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(low, high, zero, one, 0);
        return ans % mod;
    }
};

// Explaination:

// We take a dp array of size 100002 and initialize it with -1.
// Then we wrote a solve function that takes the arguments of low, high, zero, one, and len = 0.
// In the solve function, we will add a base case that if len exceeds high return 0.
// Then we will add a memoization check if dp[len] is not equal to -1 then return dp[len].
// Then we will add a base case that if len is greater than or equal to low then return 1 else 0.
// Then we will add the total variable and initialize it with 0.
// Then we will add the total variable with the solve function with the arguments of low, high, zero, one, and len + zero.
// Then we will add the total variable with the solve function with the arguments of low, high, zero, one, and len + one.
// Then we will return dp[len] = total % mod.
// Then we will call the solve function with the arguments of low, high, zero, one, and 0.
// Then we will return the answer % mod.

// Bottom Up Approach

Class Solution
{
public:
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one)
    {
        int n = high;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i >= low)
                dp[i] = 1;
            dp[i] += dp[i - zero];
            dp[i] += dp[i - one];
            dp[i] %= mod;
        }
        int ans = 0;
        for (int i = low; i <= high; i++)
            ans = (ans + dp[i]) % mod;
        return ans;
    }
};

class Solution
{
public:
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int len = 1; len <= high; ++len)
        {
            if (len + zero <= high)
            {
                dp[len + zero] = (dp[len + zero] + dp[len]) % mod;
            }
            if (len + one <= high)
            {
                dp[len + one] = (dp[len + one] + dp[len]) % mod;
            }
        }

        int result = 0;
        for (int i = low; i <= high; ++i)
        {
            result = (result + dp[i]) % mod;
        }

        return result;
    }
};

// Two ways to solve this question by bottom up