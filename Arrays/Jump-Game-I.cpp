// Leetcode 55. Jump Game

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int end = 0;
        for (int i = 0; i <= end; i++)
        {
            end = max(end, i + nums[i]);
            if (end >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

// Explanation

// We can solve this problem by iterating over the array and keeping track of the maximum reachable index. We can start from the first index and update the maximum reachable index at each step. If the maximum reachable index is greater than or equal to the last index, we can return true. Otherwise, we can return false.