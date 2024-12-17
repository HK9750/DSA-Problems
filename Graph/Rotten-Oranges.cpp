// Leetcode 994. Rotting Oranges

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, ans = -1;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            ans++;
            for (int i = 0; i < size; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : directions)
                {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? max(ans, 0) : -1;
    }
};

// Detailed Explanation:

// We will use a queue to store the rotten oranges. We will also keep a count of fresh oranges.
// We will iterate over the grid and push the rotten oranges into the queue and count the fresh oranges.
// We will iterate over the queue and for each rotten orange, we will check its adjacent cells and if they are fresh, we will rot them and push them into the queue.
// We will keep track of the time taken to rot all the oranges.
// If all the oranges are rotten, we will return the time taken, else we will return -1.
