// Leetcode 3340. Check Balanced String

class Solution
{
public:
    bool isBalanced(string num)
    {
        int n = num.size();
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                sum1 += num[i] - '0';
            if (i % 2 != 0)
                sum2 += num[i] - '0';
        }

        return sum1 == sum2;
    }
};

// Explanation:
// We need to check if the sum of the digits at even positions is equal to the sum of the digits at odd positions.
// We can do this by iterating over all the digits of the number and maintaining two sums, one for the digits at even positions and one for the digits at odd positions.
// We can then check if the two sums are equal or not.
// If the two sums are equal, then the number is balanced, and we return true.
// Otherwise, we return false.
