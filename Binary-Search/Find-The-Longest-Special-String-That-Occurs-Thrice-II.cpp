// Leetcode 2982. Find The Longest Special String That Occurs Thrice II

// Can be solved using dp(2D) for each character and its length.

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