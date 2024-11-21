// Leetcode 2257. Count UnGuarded Cells In A Grid

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto w : walls)
        {
            grid[w[0]][w[1]] = -1;
        }
        for (auto g : guards)
        {
            grid[g[0]][g[1]] = 2;
        }

        auto dfs = [&](int x, int y, int dx, int dy, auto &&dfs_ref) -> void
        {
            int newX = x + dx;
            int newY = y + dy;

            if (newX < 0 || newX >= m || newY < 0 || newY >= n ||
                grid[newX][newY] == -1 || grid[newX][newY] == 2)
                return;

            if (grid[newX][newY] == 0)
            {
                grid[newX][newY] = 1;
            }

            dfs_ref(newX, newY, dx, dy, dfs_ref);
        };

        for (auto &g : guards)
        {
            for (auto &d : dir)
            {
                dfs(g[0], g[1], d.first, d.second, dfs);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// Explanation:

// First we create a grid of size m x n and initialize it with 0.
// Then we iterate through the walls vector and mark the cells with -1 in the grid.
// Then we iterate through the guards vector and mark the cells with 2 in the grid.
// Then we define a lambda function dfs which takes the current cell coordinates and the direction to move in and recursively marks the cells as unguarded.
// We iterate through the guards and for each guard we call the dfs function in all four directions.
// Finally we count the number of cells with value 0 in the grid and return the count as the answer.