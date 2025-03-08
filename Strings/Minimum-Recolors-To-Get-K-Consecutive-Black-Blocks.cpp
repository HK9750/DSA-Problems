// Leetcode 2379. Minimum Recolors To Get K Consecutive Black Blocks

class Solution
{
public:
    int minimumRecolors(string s, int k)
    {
        int ans = INT_MAX;
        int cnt = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                cnt++;
            }

            if (i >= k - 1)
            {
                int res = k - cnt;
                ans = min(ans, res);

                if (s[i - (k - 1)] == 'B')
                {
                    cnt--;
                }
            }
        }

        return ans;
    }
};

// Explaination:

// We are given a string s of length n and an integer k. We need to find the minimum number of recolors needed to get k consecutive black blocks.
// We can iterate over the string and keep track of the number of black blocks in the current window of size k. If the number of black blocks in the current window is less than k, we need to recolor the remaining blocks to black. The number of recolors needed is k - cnt, where cnt is the number of black blocks in the current window.
// We can keep track of the minimum number of recolors needed to get k consecutive black blocks and return the minimum number of recolors needed.
// Time Complexity: O(n)