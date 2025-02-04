// Leetcode 1800. Maximum Ascending Subarray Sum

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0];
        int ans = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                sum += nums[i];
            }
            else
            {
                ans = max(ans, sum);
                sum = nums[i];
            }
        }

        ans = max(ans, sum);

        return ans;
    }
};

// Explaintion:

// We will iterate over the array and check if the current element is greater than the previous element.
// If it is, we will add the current element to the sum.
// If it is not, we will update the answer with the maximum of the current sum and the answer and reset the sum to the current element.
// Finally, we will return the answer.
