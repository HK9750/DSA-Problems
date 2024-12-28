// Leetcode 3033. Modify The Matrix

class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> cols(n, 0);
        vector<vector<int>> ans = matrix;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cols[j] = max(cols[j], matrix[i][j]);
                if (matrix[i][j] == -1)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            ans[i][j] = cols[j];
        }

        return ans;
    }
};

// Explanation:
// We first find the maximum value in each column of the matrix.
// We then iterate over the matrix and replace all -1 values with the maximum value in the corresponding column.
// Finally, we return the modified matrix.