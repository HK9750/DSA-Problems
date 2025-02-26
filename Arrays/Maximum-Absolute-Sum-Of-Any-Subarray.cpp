// Leetcode 1749. Maximum Absolute Sum of Any Subarray

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};

// Explaination:

// The idea is to find the maximum and minimum prefix sum of the array.
// The maximum absolute sum of any subarray is the difference between the maximum and minimum prefix sum of the array.
// The maximum prefix sum of the array is the maximum sum of any subarray of the array.
// The minimum prefix sum of the array is the minimum sum of any subarray of the array.
// The maximum absolute sum of any subarray is the maximum sum of any subarray of the array minus the minimum sum of any subarray of the array.
// Now, we can find the maximum and minimum prefix sum of the array by iterating through the array and keeping track of the maximum and minimum prefix sum of the array.
// We can initialize the maximum and minimum prefix sum of the array to 0.
// We can iterate through the array and update the maximum and minimum prefix sum of the array by adding the current element to the prefix sum and updating the maximum and minimum prefix sum of the array.
// Finally, we can return the maximum absolute sum of any subarray by subtracting the minimum prefix sum of the array from the maximum prefix sum of the array.
// Time Complexity: O(n)