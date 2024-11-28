// Leetcode 1293. Shortest Path in a Grid with Obstacles Elimination

class Solution
{
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<vector<int>> q;
        q.push({0, 0, k});
        visited[0][0][k] = true;

        int steps = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto temp = q.front();
                q.pop();

                int i = temp[0];
                int j = temp[1];
                int remk = temp[2];

                if (i == m - 1 && j == n - 1)
                    return steps;

                for (auto &dir : directions)
                {
                    int newX = i + dir[0];
                    int newY = j + dir[1];

                    if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                        continue;

                    int newK = remk - grid[newX][newY];

                    if (newK >= 0 && !visited[newX][newY][newK])
                    {
                        q.push({newX, newY, newK});
                        visited[newX][newY][newK] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

// Explaination:

// We will use BFS to solve this problem. We will start from the top left corner and keep moving in all 4 directions. We will keep track of the number of obstacles we have removed so far. We will keep track of the visited nodes in a 3D array. The third dimension will be the number of obstacles we have removed so far. If we reach the bottom right corner, we will return the number of steps we have taken so far. If we are not able to reach the bottom right corner, we will return -1.
// Time Complexity: O(m*n*k)