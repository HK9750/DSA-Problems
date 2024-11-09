// Leetcode 3133. Minimum Array End

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long result = x;
        long long remaining = n - 1;
        long long position = 1;

        while (remaining)
        {
            if (!(x & position))
            {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }

        return result;
    }
};

// Explanation:

// We are given two integers n and x. We need to find the minimum value that can be obtained by setting the last n - 1 bits of x to 0.
// We can find the minimum value that can be obtained by setting the last n - 1 bits of x to 0 by following the below steps:
// 1. Initialize the result variable with the value of x.
// 2. Initialize the remaining variable with the value of n - 1.
// 3. Initialize the position variable with the value of 1.
// 4. While the remaining variable is greater than 0, do the following:
//     a. If the bit at the position in x is 0, then set the bit at the position in the result variable to the last bit of the remaining variable and right shift the remaining variable by 1.
//     b. Left shift the position variable by 1.
// 5. Return the result variable as the minimum value that can be obtained by setting the last n - 1 bits of x to 0.
