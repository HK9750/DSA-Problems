// Leetcode 1975. Maximum Matrix Sum

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        long long totalSum = 0;
        int neg = 0;
        int smallestNegativeVal = INT_MAX;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = matrix[i][j];
                totalSum += abs(val);
                if (val < 0)
                    neg++;
                smallestNegativeVal = min(smallestNegativeVal, abs(val));
            }
        }

        if (neg % 2 != 0)
        {
            return totalSum - 2 * smallestNegativeVal;
        }

        return totalSum;
    }
};