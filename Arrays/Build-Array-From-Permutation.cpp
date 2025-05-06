// Leetcode 1920. Build Array From Permutation

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};

// Explaination:

// 1. The problem is about building an array from a given permutation array.
// 2. The input is an array `nums` of size `n`, where each element is a permutation of the numbers from `0` to `n-1`.
// 3. The goal is to create a new array `ans` such that `ans[i] = nums[nums[i]]` for each index `i` in the range from `0` to `n-1`.
// 4. We first determine the size of the input array `n` using `nums.size()`.
// 5. We then create a new vector `ans` of the same size `n` to store the result.
// 6. We iterate through each index `i` from `0` to `n-1` and assign the value `nums[nums[i]]` to `ans[i]`.
// 7. This means that for each index `i`, we first look up the value at `nums[i]`, and then use that value as an index to look up the value in `nums` again.
// 8. Finally, we return the constructed array `ans` as the result.
// 9. The time complexity of this solution is O(n), as we are iterating through the array once. The space complexity is also O(n) due to the use of the `ans` vector to store the result.