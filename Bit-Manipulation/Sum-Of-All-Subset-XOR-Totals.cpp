// Leetcode 1863. Sum of All Subset XOR Totals

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, nums, curr, ans);
        int res = 0;
        for (vector<int> &arr : ans)
        {
            res += calculateXOR(arr);
        }
        return res;
    }

private:
    int calculateXOR(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int ans = arr[0];
        for (int i = 1; i < n; ++i)
        {
            ans ^= arr[i];
        }
        return ans;
    }

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

// Explaination

// First we create to create a subset of the given array using backtracking. We will create a vector of vectors to store all the subsets.
// Then we will calculate the XOR of each subset and add it to the result. Finally we will return the result.
// The time complexity of this solution is O(2^n) and the space complexity is O(n) where n is the size of the array.
// The time complexity is O(2^n) because we are generating all the subsets of the array and the space complexity is O(n) because we are using a vector to store the subsets.