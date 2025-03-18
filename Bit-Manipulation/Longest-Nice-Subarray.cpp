// Leetcode 2401. Longest Nice Subarray

class Solution
{
public:
    bool isNice(vector<int> &nums, int start, int end)
    {
        int mask = 0;
        for (int i = start; i <= end; i++)
        {
            if ((mask & nums[i]) != 0)
                return false;
            mask |= nums[i];
        }
        return true;
    }

    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isNice(nums, i, j))
                {
                    result = max(result, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }

        return result;
    }
};

// Explaination:
// We can check if a subarray is nice by checking if the bitwise OR of all the elements in the subarray is equal to the bitwise XOR of all the elements in the subarray.
// We can iterate over all the subarrays and check if they are nice or not.
