// Leetcode 46. Permutations

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, int index)
    {
        if (index == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(nums, res, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};

// Explaination:
// We are using backtracking to solve this problem. We are swapping the elements of the array and then calling the backtrack function recursively.
// We are swapping the elements back to their original position after the recursive call. This is done to maintain the original array.
// We are using a vector of vectors to store the permutations. We are pushing the array into the vector of vectors when we reach the base case.
// The base case is when the index is equal to the size of the array - 1. This is because we have reached the end of the array and we have a permutation.
