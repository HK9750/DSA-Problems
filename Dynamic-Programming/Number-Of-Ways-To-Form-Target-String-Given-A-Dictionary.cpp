// Leetcode 1639. Number of Ways to Form a Target String Given a Dictionary

// Khandaani Tareeqa Recursion + Memoization

class Solution
{
public:
    int targetLen;
    int wordLength;
    const int mod = 1e9 + 7;
    int memo[1001][1001];

    int numWays(vector<string> &words, string target)
    {
        targetLen = target.length();
        wordLength = words[0].length();
        vector<vector<long long>> freq(26, vector<long long>(wordLength, 0));
        memset(memo, -1, sizeof(memo));

        for (int i = 0; i < wordLength; i++)
        {
            for (auto &str : words)
            {
                char ch = str[i];
                freq[ch - 'a'][i]++;
            }
        }

        long long cnt = solve(freq, 0, 0, target);
        return cnt % mod;
    }

private:
    long long solve(vector<vector<long long>> &freq, int i, int j, string &target)
    {
        if (i == targetLen)
            return 1;
        if (j == wordLength)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];

        long long not_take = solve(freq, i, j + 1, target) % mod;
        long long take = (freq[target[i] - 'a'][j] * solve(freq, i + 1, j + 1, target)) % mod;

        return memo[i][j] = (not_take + take) % mod;
    }
};

// Explaination:
// The solution uses recursion with memoization to efficiently calculate the number of ways to form the target string from the given list of words.
// First, the lengths of the target string and the words are determined. A frequency table (freq) is built where each entry freq[c][i] counts how many times character c appears at the i-th position across all words.
// Memoization is used to store previously computed results in a 2D array (memo), which avoids redundant calculations.
// The solve function recursively explores two choices at each position:
// either skip the current column (not_take), or if the current character matches the target, include the character and move to the next target character and column (take).
//  The base cases are when all characters of the target are formed, returning 1, or when all columns are exhausted, returning 0. The final result is stored in memo[0][0], which is the number of ways to form the target from the first character and first column. The result is returned modulo 1e9 + 7 to prevent overflow.

// Bottom Up DP

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        int targetLen = target.length();
        int wordLength = words[0].length();
        const int mod = 1e9 + 7;

        vector<vector<long long>> freq(26, vector<long long>(wordLength, 0));
        vector<vector<long long>> dp(targetLen + 1, vector<long long>(wordLength + 1, 0));

        for (int i = 0; i < wordLength; i++)
        {
            for (auto &str : words)
            {
                freq[str[i] - 'a'][i]++;
            }
        }

        for (int j = 0; j <= wordLength; j++)
        {
            dp[targetLen][j] = 1;
        }

        for (int i = targetLen - 1; i >= 0; i--)
        {
            for (int j = wordLength - 1; j >= 0; j--)
            {
                long long not_take = dp[i][j + 1];
                long long take = (freq[target[i] - 'a'][j] * dp[i + 1][j + 1]) % mod;
                dp[i][j] = (not_take + take) % mod;
            }
        }

        return dp[0][0];
    }
};

// Explaination:
// As we are now using the bottom up DP approach, we will start from the last character of the target string and move towards the first character.
// We will maintain a 2D dp array where dp[i][j] will store the number of ways to form the target string starting from the ith character of the target string and jth character of the words.
// We will initialize the dp array with 1 for the last row as there is only one way to form an empty string.
// Now, we will iterate from the second last row to the first row and from the second last column to the first column.
// For each cell dp[i][j], we will calculate the number of ways to form the target string starting from the ith character of the target string and jth character of the words.
// We will calculate the number of ways to form the target string starting from the ith character of the target string and jth character of the words by adding the number of ways to form the target string starting from the (i+1)th character of the target string and (j+1)th character of the words and the number of ways to form the target string starting from the ith character of the target string and (j+1)th character of the words.
// The number of ways to form the target string starting from the ith character of the target string and jth character of the words is given by the formula:
// dp[i][j] = dp[i+1][j+1] * freq[target[i]][j] + dp[i][j+1]
// Finally, the number of ways to form the target string is given by dp[0][0].

// Time Complexity: O(n*m) where n is the length of the target string and m is the length of the words.