// Leetcode 1368. Minimum Cost to Make at Least One Valid Path in a Grid

class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        result[0][0] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if (result[i][j] < currCost)
                continue;

            for (int dir_i = 0; dir_i <= 3; dir_i++)
            {
                int newI = i + dir[dir_i][0];
                int newJ = j + dir[dir_i][1];

                if (newI >= 0 && newJ >= 0 && newI < m && newJ < n)
                {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != dir_i) ? 1 : 0);
                    int newCost = currCost + dirCost;

                    if (newCost < result[newI][newJ])
                    {
                        result[newI][newJ] = newCost;
                        pq.push({newCost, newI, newJ});
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }
};

// Explaination:
// We will use Dijkstra's algorithm to solve this problem.
// We will use a priority queue to store the cost of reaching a cell and the cell's coordinates.
// We will keep track of the minimum cost to reach a cell in the result array.
// We will start from the top left cell and keep moving in all 4 directions.
// If the direction we are moving in is not the same as the direction in the grid, we will add 1 to the cost.
// We will keep track of the minimum cost to reach the bottom right cell and return it.