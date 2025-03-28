// Leetcode 915. Partition Array into Disjoint Intervals

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> maxLeft(n), minRight(n);

        maxLeft[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }

        minRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            minRight[i] = min(minRight[i + 1], nums[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (maxLeft[i] <= minRight[i + 1])
            {
                return i + 1;
            }
        }

        return -1;
    }
};

// Explaination:

// We can solve this problem by using two arrays maxLeft and minRight. maxLeft[i] will store the maximum element from 0 to i and minRight[i] will store the minimum element from i to n-1. Now we can iterate from 0 to n-1 and check if maxLeft[i] <= minRight[i+1] then we can return i+1 as the answer. If we don't find any such i then we can return -1.
