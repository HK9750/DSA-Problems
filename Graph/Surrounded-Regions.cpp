// Leetcode 130. Surrounded Regions

class Solution
{
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(int i, int j, vector<vector<char>> &board)
    {
        board[i][j] = '#';

        for (auto &dir : dirs)
        {
            int newI = i + dir.first;
            int newJ = j + dir.second;

            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && board[newI][newJ] == 'O')
            {
                dfs(newI, newJ, board);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
                dfs(0, i, board);
            if (board[m - 1][i] == 'O')
                dfs(m - 1, i, board);
        }

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

// Explaination:

// We will start from the boundary of the matrix and do a DFS on all the 'O' cells that are connected to the boundary. We will mark all the 'O' cells that are connected to the boundary as '#'. After that, we will iterate over the matrix and mark all the 'O' cells as 'X' and all the '#' cells as 'O'.