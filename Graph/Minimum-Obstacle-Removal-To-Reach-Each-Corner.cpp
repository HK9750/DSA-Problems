// Leetcode 2290. Minimum Obstacle Removal to Reach Each Corner

// Dijsktra's Algorithm
class Solution
{
public:
#define P pair<int, pair<int, int>>
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int cwt = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for (auto &dir : directions)
            {
                int newX = i + dir[0];
                int newY = j + dir[1];

                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;

                int wt = grid[newX][newY];

                if (cwt + wt < result[newX][newY])
                {
                    result[newX][newY] = cwt + wt;
                    pq.push({cwt + wt, {newX, newY}});
                }
            }
        }

        return result[m - 1][n - 1];
    }
};

// Explanation:

// We can use Dijkstra's algorithm to solve this problem. We will use a priority queue to store the current weight and the current position. We will also use a 2D vector to store the minimum weight required to reach each cell.
// We will start from the top left corner and keep moving in all four directions. We will calculate the weight of the current cell and add it to the weight of the previous cell. If the new weight is less than the weight stored in the 2D vector, we will update the weight and push the new weight and position into the priority queue.
// We will keep doing this until we reach the bottom right corner. Finally, we will return the weight stored in the bottom right corner of the 2D vector. This will be the minimum weight required to reach the bottom right corner.
// Time Complexity: O(m*n*log(m*n))
