// Leetcode 1267. Count Servers that Communicate

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, int> row;
        unordered_map<int, int> col;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    row[i]++, col[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Explanation:

// We are given a matrix of servers. We need to find the number of servers that can communicate with each other.
// We can solve this problem by counting the number of servers in each row and column.
// We will iterate through the matrix and count the number of servers in each row and column.
// We will then iterate through the matrix again and check if the server is the only server in its row or column.
// If the server is not the only server in its row or column, we will increment the answer.
// Finally, we will return the answer.