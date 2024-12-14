// Leetcode 200. Number of Islands

class Solution
{
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        visited[i][j] = true;
        for (auto &dir : dirs)
        {
            int newI = i + dir.first;
            int newJ = j + dir.second;
            if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() &&
                !visited[newI][newJ] && grid[newI][newJ] == '1')
            {
                dfs(grid, visited, newI, newJ);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, visited, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

// Explanation:

// We can solve this problem using Depth First Search (DFS).
// We will create a 2D vector to store the visited status of each cell.
// We will iterate through each cell of the grid. If the cell is not visited and contains '1', we will call the DFS function.
// In the DFS function, we will mark the current cell as visited and recursively call the DFS function on all four adjacent cells.
// We will keep track of the number of islands by incrementing a counter each time we call the DFS function.
// Finally, we will return the counter, which will be the number of islands in the grid.
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.