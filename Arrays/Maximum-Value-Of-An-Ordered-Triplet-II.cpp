// Leetcode 2874. Maximum Value of an Ordered Triplet II

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], nums[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            res = max(res, (long long)(left[i] - nums[i]) * right[i]);
        }

        return res;
    }
};

// Explaination:

// 1. We create two arrays left and right to store the maximum values to the left and right of each element in nums respectively.
// 2. We iterate through the nums array to fill the left array with the maximum values to the left of each element.
// 3. We iterate through the nums array in reverse to fill the right array with the maximum values to the right of each element.
// 4. Finally, we iterate through the nums array again to calculate the maximum value of the expression (left[i] - nums[i]) * right[i] for each element and return the maximum value found.
// 5. The time complexity of this solution is O(n) and the space complexity is O(n) due to the use of the left and right arrays.
// 6. This solution is efficient and works well for the given problem constraints.
// 7. The maximum value of the expression is returned as the final result.