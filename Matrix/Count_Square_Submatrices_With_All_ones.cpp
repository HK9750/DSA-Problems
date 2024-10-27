// Leetcode 1277. Count Square Submatrices with All Ones

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int ans = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    ans += dp[i][j];
                }
            }
        }

        return ans;
    }
};

// Explanation:
// First we find the number of rows and columns in the matrix.
// Then we create a dp matrix of the same size as the input matrix and initialize it with 0.
// Then we iterate through the matrix and check if the element is 1 or not.
// If the element is 1 then we check if the row is 0 or the column is 0. If it is then we set the dp[i][j] to 1.
// Else we set the dp[i][j] to the minimum of the three elements above it, to the left of it and to the top left of it + 1.
// Then we add the dp[i][j] to the answer.
// In the end we return the answer.
