// Leetcode 2873. Maximum Value of an Ordered Triplet I

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long maxi = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int k = n - 1; k > i; k--)
            {
                int j = i + 1;
                while (j < k)
                {
                    long long curr = (static_cast<long long>(nums[i]) - nums[j]) * nums[k];
                    maxi = max(maxi, curr);
                    j++;
                }
            }
        }
        return maxi < 0 ? 0 : maxi;
    }
};

// Explaination:

// 1. The function `maximumTripletValue` takes a vector of integers `nums` as input and returns the maximum value of the expression (nums[i] - nums[j]) * nums[k] for all valid triplets (i, j, k) where i < j < k.
// 2. It initializes a variable `maxi` to 0 to keep track of the maximum value found so far and gets the size of the input vector `n`.
// 3. It uses a nested loop to iterate through all possible triplets (i, j, k) in the vector. The outer loop iterates over `i`, and the inner loop iterates over `k` in reverse order to ensure that `k` is always greater than `i`.
// 4. Inside the inner loop, it initializes `j` to `i + 1` and uses a while loop to iterate over all possible values of `j` between `i` and `k`.
// 5. For each triplet (i, j, k), it calculates the value of the expression (nums[i] - nums[j]) * nums[k] and updates `maxi` if the current value is greater than the previous maximum.
// 6. Finally, it returns `maxi` if it's greater than or equal to 0; otherwise, it returns 0.
// 7. The time complexity of this solution is O(n^3) due to the three nested loops, which may not be efficient for large input sizes.
// 8. The space complexity is O(1) since no additional data structures are used that depend on the input size.