// Leetcode 2684. Maximum Number of Moves in Grid

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int j = col - 2; j >= 0; --j)
        {
            for (int i = 0; i < row; ++i)
            {
                if (i > 0 && grid[i][j] < grid[i - 1][j + 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
                }
                if (grid[i][j] < grid[i][j + 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                }
                if (i < row - 1 && grid[i][j] < grid[i + 1][j + 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < row; ++i)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

// Explanation:
// First we find the number of rows and columns in the grid.
// Then we create a dp matrix of the same size as the input grid and initialize it with 0.
// Then we iterate through the grid from the second last column to the first column and from the first row to the last row.
// If the current element is less than the element to the top right of it, then we update the dp[i][j] with the maximum of the current value and the value at the top right + 1.
// If the current element is less than the element to the right of it, then we update the dp[i][j] with the maximum of the current value and the value at the right + 1.
// If the current element is less than the element to the bottom right of it, then we update the dp[i][j] with the maximum of the current value and the value at the bottom right + 1.
// In the end we return the maximum value in the first column of the dp matrix.
