// Leetcode 2563. Count the Number of Fair Pairs

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); ++i)
        {
            int left =
                lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) -
                begin(nums);
            int right =
                upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) -
                begin(nums) - 1;

            if (left <= right)
            {
                ans += (right - left + 1);
            }
        }

        return ans;
    }
};

// Explanation:

// Sort the input array.
// Initialize the answer to 0.
// Iterate over the array.
// For each element, find the left and right indices such that the sum of the current element and the element at the left index is greater than or equal to lower and the sum of the current element and the element at the right index is less than or equal to upper.
// If the left index is less than or equal to the right index, increment the answer by the count of fair pairs.
// Return the answer.