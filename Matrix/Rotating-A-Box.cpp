// Leetcode 1861. Rotating the Box

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();

        for (int i = 0; i < m; i++)
        {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (box[i][j] == '*')
                {
                    empty = j - 1;
                }
                else if (box[i][j] == '#')
                {
                    swap(box[i][j], box[i][empty]);
                    empty--;
                }
            }
        }

        vector<vector<char>> rotatedBox(n, vector<char>(m));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rotatedBox[j][m - i - 1] = box[i][j];
            }
        }

        return rotatedBox;
    }
};

// Explaination:

// We start by iterating over each row in the input matrix box.
// For each row, we iterate over each column in the row.
// If we encounter an empty cell, we update the empty variable to the current column index.
// If we encounter a stone cell, we swap the stone cell with the empty cell.
// Finally, we rotate the box by 90 degrees clockwise and return the rotated box.