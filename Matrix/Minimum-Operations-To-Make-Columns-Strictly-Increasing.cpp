// Leetcode 3402. Minimum Operations to Make Columns Strictly Increasing

class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int c = 0; c < grid[0].size(); ++c)
        {
            for (int r = 1; r < grid.size(); ++r)
            {
                if (grid[r][c] > grid[r - 1][c])
                    continue;
                ans += grid[r - 1][c] + 1 - grid[r][c];
                grid[r][c] = grid[r - 1][c] + 1;
            }
        }
        return ans;
    }
};

// Explanation:
// We need to make the columns strictly increasing. So, we need to make sure that the current element is greater than the previous element.
// If the current element is less than the previous element, we need to increase the current element to make it strictly increasing.
// We can do this by adding the difference between the previous element and the current element to the current element.
// We need to do this for all the elements in the column.
// We can do this for all the columns in the grid.
// The total number of operations required is the sum of the differences between the previous element and the current element in each column.
// We can return the total number of operations required.
