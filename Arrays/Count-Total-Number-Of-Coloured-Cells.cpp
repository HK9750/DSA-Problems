// Leetcode 2579. Count Total Number of Coloured Cells

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long ans = 1;
        if (n == 1)
            return ans;
        n--;
        long long add = 4;
        while (n--)
        {
            ans += add;
            add += 4;
        }
        return ans;
    }
};

// Explaination:

// We can Solve this problem using the formula 1 + 4 + 8 + 12 + 16 + 20 + ... + 4 * n.
