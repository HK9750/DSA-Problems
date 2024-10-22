// Leetcode 47. Permutations II

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, ans);
        return ans;
    }

private:
    void backtrack(int start, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (start == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++)
        {
            if (used.find(nums[i]) != used.end())
                continue;

            used.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums, ans);
            swap(nums[start], nums[i]);
        }
    }
};

// Explaination:
// Sorting: The input array is sorted initially to ensure that duplicate elements are adjacent. This helps in efficiently identifying and skipping over duplicate permutations during the backtracking process.

// Backtracking Approach:

// The backtrack function is used to generate permutations by recursively swapping elements from the start index.
// When start equals the length of nums, a complete permutation has been formed, which is then added to the result list (ans).
// The unordered_set<int> used keeps track of elements that have already been processed at the current recursion level. This prevents reusing the same element for the current position, effectively avoiding duplicate permutations.
// Handling Duplicates:

// Before proceeding with recursion, the code checks if the current element has already been used at the current start index. If it has, the loop continues without swapping, thus skipping duplicate values.
// This ensures that each unique permutation is generated only once, eliminating any repetitions caused by identical elements in the input.