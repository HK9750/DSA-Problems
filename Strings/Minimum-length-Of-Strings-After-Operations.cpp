// Leetcode 3223. Minimum Length of Strings after Operations

class Solution
{
public:
    int minimumLength(string s)
    {
        int freq[26] = {0};
        for (auto &x : s)
            freq[x - 'a']++;

        int ans = 0;

        for (auto &x : freq)
        {
            if (x == 0)
                continue;
            if (x % 2 == 0)
                ans += 2;
            else
                ans++;
        }

        return ans;
    }
};

// Explaintion:

// First we count the frequency of each character in the string.
// Then we iterate over the frequency array and check if the frequency of a character is even or odd.
// If the frequency is even, we add 2 to the answer.
// If the frequency is odd, we add 1 to the answer.
// Finally, we return the answer.
// Time Complexity: O(N)
