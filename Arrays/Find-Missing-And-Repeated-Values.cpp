// Leetcode 2965. Find Missing And Repeated Values

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> nums(n * n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index = grid[i][j];
                nums[index - 1]++;
            }
        }

        int miss = -1, rep = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 2)
                rep = i + 1;
            if (nums[i] == 0)
                miss = i + 1;
        }

        return {rep, miss};
    }
};

// Explaination:

// We can solve this problem by creating a vector of size n * n and initializing all the elements to 0.
// Then we will iterate over the grid and increment the value of the index by 1.
// After that, we will iterate over the nums vector and check if the value is 2, then it is the repeated value.
// If the value is 0, then it is the missing value.
// Finally, we will return the repeated and missing values.