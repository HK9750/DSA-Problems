// Leetcode 2155. All Divisions With The Highest Score Of A Binary Array

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int n = nums.size();
        int noOfOnes = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                noOfOnes++;
        }

        vector<pair<int, int>> v;
        int target = 0, zeros = 0, leftOnes = 0;

        for (int i = 0; i <= n; i++)
        {
            int ones = noOfOnes - leftOnes;
            int score = ones + zeros;
            target = max(target, score);
            v.push_back({i, score});
            if (i < n && nums[i] == 1)
                leftOnes++;
            if (i < n && nums[i] == 0)
                zeros++;
        }

        vector<int> ans;
        for (auto &p : v)
        {
            if (p.second == target)
            {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};

// Explaination:

// We first count the number of ones in the nums array.
// We then iterate over the nums array and calculate the score for each index. The score is the number of ones to the right of the current index plus the number of zeros to the left of the current index.
// We store the maximum score in the target variable.
// We store the indices and their scores in the v vector.
// We iterate over the v vector and store the indices with the maximum score in the ans vector.
// Finally, we return the ans vector.