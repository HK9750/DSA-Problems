// Leetcode 78. Subsets

// Power Set Algorithm
// It starts off with calculating the number of subsets possible for a given set of numbers.
// For each subset, we iterate over the set of numbers and check if the jth bit is set in the current subset.
// If the jth bit is set, we add the number at the jth index to the current subset.
// Finally, we add the current subset to the answer.

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        int pows = 1 << n;

        for (int i = 0; i < pows; i++)
        {
            vector<int> curr;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    curr.push_back(nums[j]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

// Backtracking Algorithm
// Take or not-take way of thinking
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }

private:
    void backtrack(int start, vector<int> &nums, vector<int> &curr,
                   vector<vector<int>> &ans)
    {
        if (start == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[start]);
        backtrack(start + 1, nums, curr, ans);
        curr.pop_back();
        backtrack(start + 1, nums, curr, ans);
    }
};

// Backtracking Algorithm
// Optimized version

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        return ans;
    }

private:
    void backtrack(int start, vector<int> &nums, vector<int> &curr,
                   vector<vector<int>> &ans)
    {
        ans.push_back(curr);
        for (int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }
};