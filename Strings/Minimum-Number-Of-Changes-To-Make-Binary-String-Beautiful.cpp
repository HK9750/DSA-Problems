// Leetcode 2914. Minimum Number of Changes to Make Binary String Beautiful

class Solution
{
public:
    int minChanges(string s)
    {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i += 2)
        {
            if (s[i] != s[i + 1])
                ans++;
        }

        return ans;
    }
};

// Explaination:

// If we have a string of 0s and 1s, we can make it beautiful by changing the string to 00... or 11... (i.e. all 0s or all 1s).
// So, we can just count the number of times the string changes from 0 to 1 or 1 to 0. This will be the minimum number of changes required to make the string beautiful.
// We can do this by iterating over the string and checking if the current character is different from the next character. If it is, we increment the answer by 1.
// Finally, we return the answer.
