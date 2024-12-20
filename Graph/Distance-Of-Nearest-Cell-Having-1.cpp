// GFG Link:https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<vector<int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({0, i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty())
        {
            auto temp = q.front();
            int dist = temp[0];
            int row = temp[1];
            int col = temp[2];
            q.pop();

            ans[row][col] = dist;

            for (auto &dir : dirs)
            {
                int newR = row + dir.first;
                int newC = col + dir.second;

                if (newR < 0 || newR >= m || newC < 0 || newC >= n)
                    continue;
                if (!visited[newR][newC])
                {
                    visited[newR][newC] = true;
                    q.push({dist + 1, newR, newC});
                }
            }
        }

        return ans;
    }
};

// Explanation:

// We are given a grid of 0's and 1's. We have to find the distance of the nearest 1 in the grid for each cell.
// We can solve this problem using BFS. We will start by pushing all the cells with 1's in the queue and mark them as visited.
// Then we will start popping the cells from the queue and update the distance of the nearest 1 in the grid for each cell.
// We will then push the adjacent cells of the current cell in the queue if they are not visited and mark them as visited.
// We will continue this process until the queue is empty.
// Finally, we will return the answer array which contains the distance of the nearest 1 in the grid for each cell.