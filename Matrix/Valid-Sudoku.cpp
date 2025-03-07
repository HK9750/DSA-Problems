// Leetcode 36. Valid Sudoku

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {};
        int col[9][9] = {};
        int box[9][9] = {};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int n = board[i][j] - '1';
                if (row[i][n] || col[j][n] || box[i / 3 * 3 + j / 3][n])
                    return false;
                row[i][n] = col[j][n] = box[i / 3 * 3 + j / 3][n] = 1;
            }
        }

        return true;
    }
};

// Explanation

// We can use three 2D arrays to keep track of the numbers in each row, column, and box. We can then iterate over the board and for each cell, we can check if the number is already present in the row, column, or box. If it is present, we can return false. If the number is not present, we can mark it as present in the row, column, and box arrays. Finally, we can return true if all the numbers are valid.