// Leetcode 3301. Maximize the Total Height of Unique Towers

class Solution
{
public:
    long long maximumTotalSum(vector<int> &nums)
    {
        long long totalSum = 0;
        sort(nums.rbegin(), nums.rend());
        int prev = INT_MAX;

        for (int a : nums)
        {
            prev = a = min(prev - 1, a);
            if (a == 0)
                return -1;
            totalSum += a;
        }

        return totalSum;
    }
};

// Explanation:

// We will sort the array in descending order.
// We will iterate over the array and assign the minimum of the previous element and the current element - 1 to the current element.
// If the current element becomes 0, we will return -1.
// Otherwise, we will add the current element to the total sum.
// We will return the total sum.