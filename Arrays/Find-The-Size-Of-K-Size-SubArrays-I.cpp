// Leetcode 3254. Find the Size of K Size Subarrays I

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> results(n - k + 1, -1);

        for (int i = 0; i <= n - k; i++)
        {
            bool cons = true;
            int maxEl = nums[i];

            for (int j = 1; j < k; j++)
            {
                if (nums[i + j] != nums[i + j - 1] + 1)
                {
                    cons = false;
                    break;
                }
                maxEl = max(maxEl, nums[i + j]);
            }

            if (cons)
            {
                results[i] = maxEl;
            }
        }

        return results;
    }
};

// Explanation:

// We are given an array of integers and an integer k. We need to find the maximum element of each subarray of size k which is consecutive.
// We can solve this problem by iterating through the array and checking if the subarray of size k starting at the current index is consecutive.
// If the subarray is consecutive, we find the maximum element of the subarray and store it in the results array.
// Finally, we return the results array.
