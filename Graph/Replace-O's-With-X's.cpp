// Problem Link: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

class Solution
{
public:
    vector<vector<char>> fill(vector<vector<char>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // The idea is to mark visited the "O" connected in the edges

        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] && mat[0][j] == 'O')
            {
                dfs(mat, visited, 0, j, dirs);
            }
            if (!visited[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(mat, visited, n - 1, j, dirs);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && mat[i][0] == 'O')
            {
                dfs(mat, visited, i, 0, dirs);
            }
            if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(mat, visited, i, m - 1, dirs);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }

private:
    void dfs(vector<vector<char>> &mat, vector<vector<bool>> &visited, int i, int j, vector<pair<int, int>> &dirs)
    {
        visited[i][j] = true;
        char node = mat[i][j];
        int n = mat.size();
        int m = mat[0].size();
        for (auto &dir : dirs)
        {
            int r = i + dir.first;
            int c = j + dir.second;

            if (r < 0 || r >= n || c < 0 || c >= m)
                continue;
            if (!visited[r][c] && mat[r][c] == 'O')
            {
                dfs(mat, visited, r, c, dirs);
            }
        }
    }
};

// Explaination: The idea is to mark visited the "O" connected in the edges

// The first step is to mark the "O" connected to the edges as visited. We can do this by traversing the edges and marking the "O" as visited. We can use a DFS to do this.
// The second step is to iterate over the matrix and mark the "O" which are not visited as "X".