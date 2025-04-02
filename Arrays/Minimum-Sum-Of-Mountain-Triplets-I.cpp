// Leetcode 2908. Minimum Sum of Mountain Triplets I

class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int k = n - 1; k > i; k--)
            {
                int j = i + 1;
                while (j < k)
                {
                    if (nums[j] > nums[i] && nums[j] > nums[k])
                    {
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                    }
                    j++;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Explaination:

// 1. The function `minimumSum` takes a vector of integers `nums` as input and returns the minimum sum of the triplet (nums[i], nums[j], nums[k]) such that i < j < k and nums[j] is a mountain peak (greater than both nums[i] and nums[k]).
// 2. It initializes a variable `ans` to `INT_MAX` to keep track of the minimum sum found so far and gets the size of the input vector `n`.
// 3. It uses a nested loop to iterate through all possible triplets (i, j, k) in the vector. The outer loop iterates over `i`, and the inner loop iterates over `k` in reverse order to ensure that `k` is always greater than `i`.
// 4. Inside the inner loop, it initializes `j` to `i + 1` and uses a while loop to iterate over all possible values of `j` between `i` and `k`.
// 5. For each triplet (i, j, k), it checks if nums[j] is greater than both nums[i] and nums[k]. If so, it calculates the sum of the triplet and updates `ans` if the current sum is less than the previous minimum.
// 6. Finally, it returns `ans` if it's less than `INT_MAX`; otherwise, it returns -1 to indicate that no valid triplet was found.
// 7. The time complexity of this solution is O(n^3) due to the three nested loops, which may not be efficient for large input sizes.
// 8. The space complexity is O(1) since no additional data structures are used that depend on the input size.