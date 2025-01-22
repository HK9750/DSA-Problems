// Leetcode 01 Matrix

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            for (auto &dir : dirs)
            {
                int newI = i + dir.first;
                int newJ = j + dir.second;

                if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && ans[newI][newJ] == -1)
                {
                    ans[newI][newJ] = ans[i][j] + 1;
                    q.push({newI, newJ});
                }
            }
        }

        return ans;
    }
};

// Explaination:

// Multisource BFS
// We start by pushing all the 0s into the queue and marking their distance as 0.
// Then we start BFS from these 0s and keep on updating the distance of the neighbouring cells.
// We keep on doing this until the queue is empty.
// The distance of the neighbouring cells is the distance of the current cell + 1.
// We keep on updating the distance of the neighbouring cells until we have visited all the cells.
// Then we return the distance matrix.