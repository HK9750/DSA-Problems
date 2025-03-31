// Leetcode 3498. Reverse Degree of a String

class Solution
{
public:
    int reverseDegree(string s)
    {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += (26 - (s[i] - 'a')) * (i + 1);
        }

        return ans;
    }
};

// Explaination:

// The problem is asking us to find the reverse degree of a string, which is defined as the sum of the reverse degrees of each character in the string.
// The reverse degree of a character is defined as the number of characters that come after it in the alphabet, multiplied by its position in the string (1-indexed).
