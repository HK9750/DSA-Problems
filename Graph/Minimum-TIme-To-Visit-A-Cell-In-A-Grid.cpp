// Leetcode 2577. Minimum Time to visit a cell in a Grid

// Dijkstra's Algorithm
class Solution
{
public:
#define P pair<int, pair<int, int>>
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumTime(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        pq.push({0, {0, 0}});
        seen[0][0] = true;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currTime = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            if (i == m - 1 && j == n - 1)
                return currTime;

            for (auto &dir : directions)
            {
                int nextX = i + dir[0];
                int nextY = j + dir[1];

                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                    continue;

                if (!seen[nextX][nextY])
                {
                    int waitTime =
                        ((grid[nextX][nextY] - currTime) % 2 == 0) ? 1 : 0;
                    int nextTime =
                        max(currTime + 1, grid[nextX][nextY] + waitTime);
                    pq.push({nextTime, {nextX, nextY}});
                    seen[nextX][nextY] = true;
                }
            }
        }

        return -1;
    }
};

// Explaination:

// We start by pushing the source cell (0, 0) into the priority queue with time 0. We also mark this cell as visited.
// We keep popping the cells from the priority queue until it is empty.
// For each cell, we check if it is the destination cell. If it is, we return the time taken to reach this cell.
// For each cell, we check all 4 directions. If the next cell is within the grid, we calculate the time taken to reach this cell. If the time taken is even, we add 1 to it. We then push this cell into the priority queue.
// We mark this cell as visited.
// If we are not able to reach the destination cell, we return -1.
// Time Complexity: O(m*n*log(m*n))