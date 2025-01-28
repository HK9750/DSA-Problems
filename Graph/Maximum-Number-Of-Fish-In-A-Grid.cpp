// Leetcode 2658. Maximum Number of Fish in a Grid

class Solution
{
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(int i, int j, vector<vector<bool>> &visited,
            vector<vector<int>> &grid)
    {
        visited[i][j] = true;
        int ans = grid[i][j];

        int m = grid.size();
        int n = grid[0].size();

        for (auto &dir : dirs)
        {
            int newI = i + dir.first;
            int newJ = j + dir.second;

            if (newI < 0 || newI >= m || newJ < 0 || newJ >= n)
                continue;

            if (!visited[newI][newJ] && grid[newI][newJ])
            {
                ans += dfs(newI, newJ, visited, grid);
            }
        }

        return ans;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0 && !visited[i][j])
                {
                    ans = max(ans, dfs(i, j, visited, grid));
                }
            }
        }

        return ans;
    }
};

// Explanation:

// The problem is to find the maximum number of fish in a grid. We can solve this problem using DFS. We will start from each cell in the grid and perform DFS to find the maximum number of fish we can catch starting from that cell. We will keep track of the visited cells to avoid visiting the same cell multiple times. We will also keep track of the maximum number of fish we can catch starting from any cell. Finally, we will return the maximum number of fish we can catch starting from any cell.