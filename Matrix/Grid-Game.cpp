// Leetcode 2017. Grid Game

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();

        long long first_row_sum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long second_row_sum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            first_row_sum -= grid[0][i];
            long long maxi = max(first_row_sum, second_row_sum);
            ans = min(ans, maxi);
            second_row_sum += grid[1][i];
        }

        return ans;
    }
};

// Explaination:

// Initialize the first_row_sum with the sum of the first row.
// Initialize the second_row_sum with 0.
// Initialize the ans with LLONG_MAX.
// Iterate over the columns of the grid.
// Subtract the current element of the first row from the first_row_sum.
// Calculate the maximum of the first_row_sum and the second_row_sum as this will be the highest numbe of points second robot will get if the first robot comes down at this column.
// Update the ans with the minimum of the current ans and the maximum.
// Add the current element of the second row to the second_row_sum.
// Return the ans.