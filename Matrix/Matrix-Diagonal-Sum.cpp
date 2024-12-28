// Leetcode 1572. Matrix Diagonal Sum

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += mat[i][i];
            sum += mat[i][n - i - 1];
        }

        if (n % 2 == 1)
        {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};

// Explaination:

// We iterate over the matrix and add the values of the main diagonal and the secondary diagonal to the sum.
// If the size of the matrix is odd, we need to subtract the value of the center element from the sum as it is added twice.
// Finally, we return the sum.