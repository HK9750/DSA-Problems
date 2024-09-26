// Leetcode 45. Jump Game II

class Solution
{
public:
    int jump(vector<int> &nums)
    {

        if (nums.size() <= 1)
            return 0;

        int n = nums.size();
        int cnt = 0;
        int curr = 0;
        int end = 0;

        for (int i = 0; i < n; i++)
        {
            end = max(end, i + nums[i]);

            if (i == curr)
            {
                cnt++;
                curr = end;
                if (curr >= n - 1)
                    break;
            }
        }

        return cnt;
    }
};

// Explanation

// We can solve this problem by iterating over the array and keeping track of the maximum reachable index. We can start from the first index and update the maximum reachable index at each step. If the current index is equal to the last index, we can return the count. Otherwise, we can update the current index to the maximum reachable index and continue the process. We can return the count at the end.