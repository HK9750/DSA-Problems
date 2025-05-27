// Leetcode 2894. Divisible and Non-Divisible Sums Difference

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % m != 0)
            {
                ans += i;
            }
            else
            {
                ans -= i;
            }
        }
        return ans;
    }
};

// Explanation:

// 1. We initialize a variable `ans` to 0, which will hold the final result.
// 2. We iterate through all integers from 1 to `n`.
// 3. For each integer `i`, we check if it is divisible by `m`.
// 4. If `i` is not divisible by `m`, we add it to `ans`.
// 5. If `i` is divisible by `m`, we subtract it from `ans`.
// 6. Finally, we return the value of `ans` as the result.
// Time Complexity: O(n), where n is the input integer.
// Space Complexity: O(1), as we are using a constant amount of space for the variable `ans`.