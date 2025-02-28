// Leetcode 1092. Shortest Common Supersequence

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
                else
                {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string result = "";

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                result += str1[i - 1];
                i--, j--;
            }
            else if (lcs[i - 1][j] > lcs[i][j - 1])
            {
                result += str1[i - 1];
                i--;
            }
            else
            {
                result += str2[j - 1];
                j--;
            }
        }

        while (i > 0)
            result += str1[--i];
        while (j > 0)
            result += str2[--j];

        reverse(result.begin(), result.end());
        return result;
    }
};

// Explaination:

// The idea is to find the shortest common supersequence of two strings.
// The shortest common supersequence of two strings is the shortest string that contains both strings as subsequences.
// The shortest common supersequence of two strings can be found by finding the longest common subsequence of the two strings.
// The longest common subsequence of two strings is the longest string that is a subsequence of both strings.
// We can find the longest common subsequence of two strings by using dynamic programming.
// We can create a 2D array lcs of size (m + 1) x (n + 1) where m is the length of the first string and n is the length of the second string.
// We can initialize the first row and the first column of the array to 0.
// We can iterate through the array and fill in the values of the array by comparing the characters of the two strings.
// If the characters are the same, we can set the value of the array at (i, j) to 1 + the value of the array at (i - 1, j - 1).
// If the characters are different, we can set the value of the array at (i, j) to the maximum of the values of the array at (i - 1, j) and (i, j - 1).
// The value of the array at (m, n) will be the length of the longest common subsequence of the two strings.
// We can then reconstruct the longest common subsequence of the two strings by starting at the bottom right corner of the array and moving up and to the left.
// If the characters are the same, we can add the character to the result string and move up and to the left.
// If the value of the array at (i - 1, j) is greater than the value of the array at (i, j - 1), we can add the character from the first string to the result string and move up.
// Otherwise, we can add the character from the second string to the result string and move to the left.
// We can continue this process until we reach the top left corner of the array.
// Finally, we can reverse the result string and return it as the shortest common supersequence of the two strings.
// Time Complexity: O(m * n) where m is the length of the first string and n is the length of the second string.
// Space Complexity: O(m * n) where m is the length of the first string and n is the length of the second string.