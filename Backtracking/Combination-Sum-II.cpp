// Leetcode 40. Combination Sum II

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
};

// Explanation

// We can use backtracking to solve this problem. We can start by sorting the candidates array. We can then iterate over the candidates array and for each candidate, we can add it to the temporary vector and recursively call the findCombination function with the updated target and start index. If the target becomes zero, we can add the temporary vector to the result. If the target becomes negative, we can return. We can continue this process for all the candidates and return the result. We also need to handle duplicates by skipping the same element at the same level of recursion.