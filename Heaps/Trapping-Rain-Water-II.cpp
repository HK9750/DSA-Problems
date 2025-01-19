// Leetcode 407. Trapping Rain Water II

class Solution
{
public:
    typedef pair<int, pair<int, int>> cell;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int trapRainWater(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<cell, vector<cell>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++)
        {
            for (int col : {0, n - 1})
            {
                if (!visited[row][col])
                {
                    pq.push({grid[row][col], {row, col}});
                    visited[row][col] = true;
                }
            }
        }

        for (int col = 0; col < n; col++)
        {
            for (int row : {0, m - 1})
            {
                if (!visited[row][col])
                {
                    pq.push({grid[row][col], {row, col}});
                    visited[row][col] = true;
                }
            }
        }

        int water = 0;

        while (!pq.empty())
        {
            cell temp = pq.top();
            pq.pop();
            int height = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;

            for (auto &dir : dirs)
            {
                int newI = i + dir[0];
                int newJ = j + dir[1];

                if (newI < 0 || newI >= m || newJ < 0 || newJ >= n)
                    continue;
                if (!visited[newI][newJ])
                {
                    water += max(height - grid[newI][newJ], 0);
                    pq.push({max(height, grid[newI][newJ]), {newI, newJ}});
                    visited[newI][newJ] = true;
                }
            }
        }

        return water;
    }
};

// Explaination:

// First, we push the boundary cells into the priority queue. We also mark them as visited.
// Then, we start popping the cells from the priority queue. For each cell, we check all its neighbors.
// If the neighbor is not visited, we calculate the water trapped between the current cell and the neighbor.
// We add this water to the total water trapped and push the neighbor into the priority queue.
// We also mark the neighbor as visited.
// We continue this process until the priority queue is empty.
// The time complexity of this approach is O(m*n*log(m*n)), where m is the number of rows and n is the number of columns in the grid. The priority queue can have at most m*n elements, and each insertion and deletion operation takes O(log(m*n)) time. The space complexity is O(m*n) due to the visited array and the priority queue.