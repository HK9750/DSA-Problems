// Leetcode 39. Combination Sum

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, temp, n, target, 0);
        return ans;
    }

private:
    void solve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp, int n, int target, int start)
    {
        if (target < 0)
            return;
        if (target == 0)
            ans.push_back(temp);

        for (int i = start; i < n; i++)
        {
            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, n, target - candidates[i], i);
            temp.pop_back();
        }
    }
};

// Explanation

// We can use backtracking to solve this problem. We can start by iterating over the candidates array and for each candidate, we can add it to the temporary vector and recursively call the solve function with the updated target and start index. If the target becomes zero, we can add the temporary vector to the result. If the target becomes negative, we can return. We can continue this process for all the candidates and return the result.