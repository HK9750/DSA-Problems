// Leetcode 1415. The k-th Lexicographical String of All Happy Strings of Length n

class Solution
{
    int n2;
    string dfs(string prefix, int n, int k)
    {
        if (n == 0)
            return prefix;
        for (char c = 'a'; c <= 'c'; c++)
        {
            if (!prefix.empty() && c == prefix.back())
                continue;
            int cnt = (1 << (n2 - prefix.length() - 1));
            if (cnt >= k)
                return dfs(prefix + c, n - 1, k);
            else
                k -= cnt;
        }
        return "";
    }

public:
    string getHappyString(int n, int k)
    {
        n2 = n;
        return dfs("", n, k);
    }
};

// Explanation:

// The idea is to generate all the happy strings of length n and then return the k-th lexicographically smallest string. We can do this by using backtracking. We will start by iterating over the characters 'a', 'b', and 'c' and for each character, we will check if the character is the same as the last character in the prefix. If it is the same, we will skip the character. We will then calculate the count of the number of happy strings of length n - prefix.length() - 1. If the count is greater than or equal to k, we will recursively call the function with the updated prefix and n - 1 and k. If the count is less than k, we will decrement k by the count and continue the process. We will then return the prefix. We will then call the function with an empty prefix and n and k. We will then return the result.
// Time Complexity: O(3^n)