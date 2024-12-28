// Leetcode 883. Projection Area of 3D Shapes

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int rowS = 0;
            int colS = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    ans++;
                rowS = max(rowS, grid[i][j]);
                colS = max(colS, grid[j][i]);
            }
            ans += rowS + colS;
        }

        return ans;
    }
};

// Explanation:
// We calculate the area of the projection on the xy-plane by counting the number of non-zero cells in the grid.
// We calculate the area of the projection on the xz-plane by taking the maximum value in each row.
// We calculate the area of the projection on the yz-plane by taking the maximum value in each column.
// Finally, we add the three areas to get the total projection area.
