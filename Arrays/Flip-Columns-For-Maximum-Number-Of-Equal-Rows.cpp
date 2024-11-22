// Leetcode 1072. Flip Columns For Maximum Number of Equal Rows

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &A)
    {
        int N = A[0].size(), ans = 0;
        unordered_map<string, int> cnt;
        for (auto &row : A)
        {
            bool flip = row[0] == 0;
            string s;
            for (int i = 0; i < N; ++i)
                s += '0' + (row[i] ^ flip);
            cnt[s]++;
            ans = max(ans, cnt[s]);
        }
        return ans;
    }
};

// Explanation:

// We start by iterating over each row in the input matrix A. For each row, we check if it is possible to flip the row to make all elements in the row equal. We do this by checking if the first element in the row is 0. If it is, we can flip the row to make all elements in the row equal to 1. Otherwise, we can flip the row to make all elements in the row equal to 0.