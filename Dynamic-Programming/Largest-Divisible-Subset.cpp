// Leetcode 368. Largest Divisible Subset

// Using Dynamic Programming + Sorting

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxi])
                maxi = i;
        }
        vector<int> res;
        for (int i = maxi; i >= 0; i = prev[i])
        {
            res.push_back(nums[i]);
        }
        return res;
    }
};

// Explaination:

// 1. Sort the array in ascending order.
// 2. Create a dp array to store the length of the largest divisible subset ending at each index.
// 3. Create a prev array to store the previous index of the largest divisible subset ending at each index.
// 4. Initialize the dp array with 1, as each element can be a subset of size 1.
// 5. Iterate through the array and for each element, check if it is divisible by any of the previous elements.
// 6. If it is divisible, update the dp array and prev array accordingly.
// 7. Keep track of the maximum length of the divisible subset and its index.
// 8. Finally, backtrack using the prev array to construct the largest divisible subset and return it.
// 9. The time complexity of this approach is O(n^2), where n is the size of the input array.
// 10. The space complexity is O(n) for the dp and prev arrays.

// Using Backtracking + Sorting

class Solution
{
public:
    void generate(int idx, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev)
    {
        if (idx >= nums.size())
        {
            if (temp.size() > result.size())
            {
                result = temp;
            }
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0)
        {
            temp.push_back(nums[idx]);
            generate(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }

        generate(idx + 1, nums, result, temp, prev);
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        vector<int> result;
        vector<int> temp;
        generate(0, nums, result, temp, -1);

        return result;
    }
};

// Explaination:

// 1. Sort the array in ascending order.
// 2. Create a result vector to store the largest divisible subset.
// 3. Create a temporary vector to store the current subset being generated.
// 4. Use a backtracking function to generate all possible subsets of the array.
// 5. For each element, check if it is divisible by the previous element in the subset (if any).
// 6. If it is divisible, add it to the temporary subset and continue generating subsets from the next index.
// 7. If it is not divisible, skip it and continue generating subsets from the next index.
// 8. If the size of the temporary subset is greater than the size of the result vector, update the result vector.
// 9. Finally, return the result vector containing the largest divisible subset.
// 10. The time complexity of this approach is O(2^n) in the worst case, where n is the size of the input array.
// 11. The space complexity is O(n) for the temporary vector and the result vector.