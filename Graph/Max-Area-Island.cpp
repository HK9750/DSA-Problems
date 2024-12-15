// Leetcode 695. Max Area of Island

// DFS Solution

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto dfs = [&](int i, int j, auto &&dfs) -> int
        {
            int ans = 1;
            visited[i][j] = true;

            for (auto &dir : dirs)
            {
                int newI = i + dir.first;
                int newJ = j + dir.second;

                if (newI < 0 || newI >= m || newJ < 0 || newJ >= n)
                    continue;
                if (!visited[newI][newJ] && grid[newI][newJ] == 1)
                {
                    ans += dfs(newI, newJ, dfs);
                }
            }

            return ans;
        };

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int res = dfs(i, j, dfs);
                    ans = max(ans, res);
                }
            }
        }

        return ans;
    }
};

// BFS Solution

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxArea = 0;

        auto bfs = [&](int i, int j) -> int
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            int area = 0;

            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                area++;

                for (auto &dir : dirs)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                        !visited[newX][newY] && grid[newX][newY] == 1)
                    {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }

            return area;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int area = bfs(i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

// Explanation:

// We can solve this problem using both DFS and BFS. Here I have shown both the solutions.
// In the DFS solution, we will traverse the grid and whenever we find a cell with value 1 and not visited, we will call the dfs function.
// The dfs function will return the area of the island starting from that cell.
// We will keep track of the maximum area of the island found so far.
// In the BFS solution, we will traverse the grid and whenever we find a cell with value 1 and not visited, we will call the bfs function.
// The bfs function will return the area of the island starting from that cell.
// We will keep track of the maximum area of the island found so far.
// Both the solutions have a time complexity of O(m*n) and space complexity of O(m*n) where m is the number of rows and n is the number of columns in the grid.