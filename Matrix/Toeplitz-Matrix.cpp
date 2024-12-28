// Leetcode 766. Toeplitz Matrix

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }

        return true;
    }
};

// Explanation:
// We iterate over the matrix starting from the second row and second column.
// For each cell, we check if the value is equal to the value of the cell diagonally above and to the left.
// If any cell does not satisfy this condition, we return false.
// If all cells satisfy the condition, we return true.
