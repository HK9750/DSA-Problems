// Leetcode 2661. First Completely Painted Row or Column

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> numToPos;
        vector<int> rows(m), cols(n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = mat[i][j];
                numToPos[val] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            int num = arr[i];
            auto &[row, col] = numToPos[num];

            rows[row]++;
            cols[col]++;

            if (rows[row] == n || cols[col] == m)
                return i;
        }

        return -1;
    }
};

// Explanation:

// First we take a hashmap to store the position of each number in the matrix.
// Then we take two arrays to store the count of each row and column.
// We iterate over the given array and for each number we get the position from the hashmap.
// We increment the count of the row and column of that position.
// If the count of the row or column becomes equal to the size of the row or column then we return the index.
// If we reach the end of the array then we return -1.
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)