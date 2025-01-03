// Leetcode 2270. Number of Ways to Split array

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums)
        {
            totalSum += num;
        }

        long long prefixSum = 0;
        int count = 0;

        for (int i = 0; i < n - 1; i++)
        {
            prefixSum += nums[i];
            long long diff = totalSum - prefixSum;
            if (diff <= prefixSum)
                count++;
        }

        return count;
    }
};

// Explaination:

// First we calculate the total sum of the array.
// Then we iterate over the array and calculate the prefix sum.
// For each prefix sum we calculate the remaining sum of the array.
// If the remaining sum is less than or equal to the prefix sum then we increment the count.
// Finally we return the count.
