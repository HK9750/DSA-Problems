// Leetcode 494: Target Sum

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int count = 0;
        backtrack(nums, target, 0, 0, count);
        return count;
    }

private:
    void backtrack(vector<int> &nums, int target, int idx, int sum, int &count)
    {
        if (idx == nums.size())
        {
            if (sum == target)
            {
                count++;
            }
            return;
        }

        backtrack(nums, target, idx + 1, sum + nums[idx], count);
        backtrack(nums, target, idx + 1, sum - nums[idx], count);
    }
};

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return helper(nums, target, 0, 0);
    }

private:
    int helper(vector<int> &arr, int target, int idx, int sum)
    {
        if (idx >= arr.size())
            return sum == target ? 1 : 0;

        int subtract = helper(arr, target, idx + 1, sum - arr[idx]);
        int add = helper(arr, target, idx + 1, sum + arr[idx]);

        return subtract + add;
    }
};
