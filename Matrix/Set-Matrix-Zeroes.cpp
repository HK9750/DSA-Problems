// Leetcode 73. Set Matrix Zeroes

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bitset<200> col0 = 0, row0 = 0;
        const int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row0[i] = 1;
                    col0[j] = 1;
                }
            }
        for (int i = 0; i < n; i++)
        {
            if (row0[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for (int j = 0; j < m; j++)
        {
            if (!col0[j])
                continue;
            for (int i = 0; i < n; i++)
                matrix[i][j] = 0;
        }
    }
};

// Explaination:

// 1. The function `setZeroes` takes a 2D vector `matrix` as input.
// 2. It initializes two bitsets `col0` and `row0` to keep track of which rows and columns need to be set to zero.
// 3. It iterates through the matrix to find the positions of zeros and updates the `row0` and `col0` bitsets accordingly.
// 4. It then iterates through the rows and sets the entire row to zero if the corresponding bit in `row0` is set.
// 5. Finally, it iterates through the columns and sets the entire column to zero if the corresponding bit in `col0` is set.
// 6. The time complexity of this algorithm is O(n * m), where n is the number of rows and m is the number of columns in the matrix.
// 7. The space complexity is O(n + m) due to the `row0` and `col0` bitsets.