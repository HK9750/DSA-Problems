// Leetcode 2982. Find The Longest Special String That Occurs Thrice II

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        if (n == 0)
            return -1;

        vector<vector<int>> dp(26, vector<int>(n + 1, 0));
        int ans = 0, l = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && s[i] == s[i - 1])
            {
                l++;
            }
            else
            {
                l = 1;
            }
            dp[s[i] - 'a'][l]++;
        }

        for (int row = 0; row < 26; row++)
        {
            int cumSum = 0;
            for (int col = n; col >= 1; col--)
            {
                cumSum += dp[row][col];
                if (cumSum >= 3)
                {
                    ans = max(ans, col);
                    break;
                }
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

// Explaination:

// We will maintain a 2D dp array for each character and its length for about n.
// We will keep track of the count of each character and its length.
// We will iterate over the dp array and check if the count of any character is greater than or equal to 3.
// If it is, we will update the answer with the maximum length of the character.
// Finally, we will return the answer. If the answer is 0, we will return -1.

// Using Binary Search

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        int l = 1, r = n;

        if (!helper(s, n, l))
            return -1;

        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (helper(s, n, mid))
                l = mid;
            else
                r = mid;
        }

        return l;
    }

private:
    bool helper(const string &s, int n, int x)
    {
        vector<int> cnt(26, 0);
        int p = 0;

        for (int i = 0; i < n; i++)
        {
            while (s[p] != s[i])
                p++;
            if (i - p + 1 >= x)
                cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 2)
                return true;
        }

        return false;
    }
};

// Explaination:

// Declares a helper function to check if a substring of length x satisfies the condition.
// Uses binary search (l to r) to find the maximum valid length.
// The helper function:
// Uses two pointers to track valid substrings.
// Counts character occurrences with a cnt array.
// Returns true if any character appears more than 2 times consecutively in a substring of length x.