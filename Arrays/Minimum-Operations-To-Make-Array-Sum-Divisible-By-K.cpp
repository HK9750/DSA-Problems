// Leetcode 3512. Minimum Operations to Make Array Sum Divisible by K

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int sum = accumulate(begin(nums), end(nums), 0);
        return sum % k;
    }
};

// Explaination:

// 1. The function `minOperations` calculates the minimum operations required to make the sum of the array divisible by `k`.
// 2. It first calculates the sum of the elements in the array `nums` using `accumulate`.
// 3. Then, it checks the remainder of the sum when divided by `k` using the modulo operator `%`.
// 4. The function returns the remainder, which represents the minimum operations needed to make the sum divisible by `k`.