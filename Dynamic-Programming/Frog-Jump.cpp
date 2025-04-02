// Leetcode 403. Frog Jump`

class Solution
{
public:
    int dp[2001][2001];
    bool solve(vector<int> &stones, int index, int k)
    {
        if (index == stones.size() - 1)
            return true;
        if (dp[index][k] != -1)
            return dp[index][k];
        for (int jump : {k - 1, k, k + 1})
        {
            if (jump > 0)
            {
                int nextIndex = lower_bound(stones.begin(), stones.end(), stones[index] + jump) - stones.begin();
                if (nextIndex < stones.size() && stones[nextIndex] == stones[index] + jump)
                {
                    if (solve(stones, nextIndex, jump))
                        return dp[index][k] = 1;
                }
            }
        }
        return dp[index][k] = 0;
    }
    bool canCross(vector<int> &stones)
    {
        if (stones[1] != 1)
            return false;
        memset(dp, -1, sizeof(dp));
        return solve(stones, 1, 1);
    }
};

// Explaination:

// The frog can jump to the next stone with a distance of k-1, k, or k+1.
// First we check if the first jump is possible, which is only possible if the second stone is at position 1.
// We use a recursive function to check if the frog can reach the last stone from the current stone with a given jump distance k.
// We use memoization to store the results of previously computed states to avoid redundant calculations.
// The function returns true if the frog can reach the last stone, otherwise it returns false.
// The time complexity of this solution is O(n^2) in the worst case, where n is the number of stones.
// The solution uses binary search to find the next stone that the frog can jump to, which reduces the time complexity of finding the next stone to O(log n).
// The overall time complexity is O(n log n) due to the binary search for each stone.
// The space complexity is O(n) due to the memoization array.