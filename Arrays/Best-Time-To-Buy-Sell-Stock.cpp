// Leetcode 121. Best Time to Buy and Sell Stock

class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        int maxProfit = 0;
        int minVal = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (minVal > nums[i])
                minVal = nums[i];
            if (maxProfit < nums[i] - minVal)
                maxProfit = nums[i] - minVal;
        }
        return maxProfit;
    }
};

// Explaination
// The idea is to iterate over the array and keep track of the minimum value and the maximum profit.
// Initialize two variables, maxProfit and minVal, to store the maximum profit and the minimum value.
// Iterate over the array and update the minimum value and maximum profit accordingly.
// Return the maximum profit.
