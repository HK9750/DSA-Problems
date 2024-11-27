// Leetcode 491. Non-decreasing Subsequences

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> curr;
        vector<vector<int>> result;
        backtrack(result, 0, curr, nums);
        return result;
    }

private:
    void backtrack(vector<vector<int>> &result, int index, vector<int> &curr, vector<int> &nums)
    {
        if (curr.size() >= 2)
        {
            result.push_back(curr);
        }
        unordered_set<int> used;
        for (int i = index; i < nums.size(); ++i)
        {
            if (!curr.empty() && nums[i] < curr.back())
                continue;
            if (used.count(nums[i]))
                continue;
            used.insert(nums[i]);
            curr.push_back(nums[i]);
            backtrack(result, i + 1, curr, nums);
            curr.pop_back();
        }
    }
};

// Explaination:

// The idea is to use backtracking to generate all possible subsequences of the given array.
// The key is to avoid duplicates. To do this, we use a set to keep track of the elements that have been used in the current subsequence.
// We also use a set to keep track of the elements that have been used in the current subsequence.
// We iterate over the array and for each element, we check if it is greater than or equal to the last element in the current subsequence.
// If it is, we add it to the current subsequence and recursively call the backtrack function with the next index.
// After the recursive call, we remove the last element from the current subsequence to backtrack and try the next element.
// This way, we generate all possible subsequences of the given array without duplicates.
