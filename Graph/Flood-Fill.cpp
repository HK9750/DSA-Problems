// Leetcode 733. Flood Fill

// DFS Solution

class Solution
{
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &ans, vector<vector<int>> &image, int color, int initialColor, int r, int c)
    {
        ans[r][c] = color;
        int m = image.size();
        int n = image[0].size();

        for (auto &dir : dirs)
        {
            int newR = r + dir.first;
            int newC = c + dir.second;

            if (newR < 0 || newR >= m || newC < 0 || newC >= n)
                continue;
            if (image[newR][newC] == initialColor && ans[newR][newC] != color)
            {
                dfs(ans, image, color, initialColor, newR, newC);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(ans, image, color, initialColor, sr, sc);
        return ans;
    }
};

// BFS Solution

class Solution
{
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        ans[sr][sc] = color;

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto &dir : dirs)
            {
                int newR = r + dir.first;
                int newC = c + dir.second;

                if (newR < 0 || newR >= m || newC < 0 || newC >= n)
                    continue;
                if (image[newR][newC] == initialColor && ans[newR][newC] != color)
                {
                    q.push({newR, newC});
                    ans[newR][newC] = color;
                }
            }
        }

        return ans;
    }
};

// Explanation:

// The problem is a simple flood fill problem. We have to change the color of the given cell and all the connected cells with the same color to the new color.
// We can solve this problem using both DFS and BFS. I have provided both solutions above.
// In the DFS solution, we start from the given cell and change its color to the new color. Then, we recursively call the DFS function on all the neighboring cells with the same color.
// In the BFS solution, we start from the given cell and change its color to the new color. Then, we push the cell into the queue and keep processing the cells in the queue until it is empty. We change the color of the neighboring cells with the same color and push them into the queue.
// Both solutions have the same time complexity of O(m*n) and space complexity of O(m*n) where m is the number of rows and n is the number of columns in the image matrix.