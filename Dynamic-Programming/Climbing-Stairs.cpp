// Leetcode 70. Climbing Stairs
// Similar to Fibonacci Series

class Solution
{
public:
    int memo[46];
    Solution() { memset(memo, -1, sizeof(memo)); }
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        if (memo[n] != -1)
            return memo[n];

        memo[n] = climbStairs(n - 2) + climbStairs(n - 1);

        return memo[n];
    }
};

// Explanation: The problem can be solved using dynamic programming. The problem can be solved using the following recursive relation:
// f(n) = f(n-1) + f(n-2)
// The base cases are f(1) = 1, f(2) = 2, f(3) = 3. The recursive relation can be used to solve the problem. The solution is implemented using memoization to avoid recomputation of the same subproblems. The time complexity of the solution is O(n) and the space complexity is O(n).
