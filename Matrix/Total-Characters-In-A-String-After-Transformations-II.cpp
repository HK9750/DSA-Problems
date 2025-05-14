// Leetcode 3337. Total Characters In A String After Transformations II

using ll = long long;

class Solution
{
public:
    const int mod = 1e9 + 7;

    vector<vector<ll>> multiplyMatrices(const vector<vector<ll>> &A, const vector<vector<ll>> &B)
    {
        int rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
        vector<vector<__int128_t>> temp(rowsA, vector<__int128_t>(colsB, 0));
        vector<vector<ll>> result(rowsA, vector<ll>(colsB, 0));

        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsB; j++)
            {
                for (int k = 0; k < colsA; k++)
                {
                    temp[i][j] += A[i][k] * B[k][j];
                }
                result[i][j] = temp[i][j] % mod;
            }
        }
        return result;
    }

    vector<vector<ll>> powerMatrix(vector<vector<ll>> matrix, ll exponent)
    {
        vector<vector<ll>> result(matrix.size(), vector<ll>(matrix.size(), 0));

        for (int i = 0; i < matrix.size(); i++)
            result[i][i] = 1;

        while (exponent > 0)
        {
            if (exponent % 2 == 1)
                result = multiplyMatrices(result, matrix);
            matrix = multiplyMatrices(matrix, matrix);
            exponent /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        vector<vector<ll>> transform(26, vector<ll>(26, 0));

        for (int i = 0; i < 26; i++)
        {
            for (int shift = 0; shift < nums[i]; shift++)
            {
                transform[i][(i + 1 + shift) % 26]++;
            }
        }

        transform = powerMatrix(transform, t);
        vector<vector<ll>> freq(1, vector<ll>(26, 0));
        for (char ch : s)
        {
            freq[0][ch - 'a']++;
        }

        freq = multiplyMatrices(freq, transform);
        int totalLength = 0;
        for (int count : freq[0])
        {
            totalLength += count;
            if (totalLength >= mod)
                totalLength -= mod;
        }

        return totalLength;
    }
};

// Explanation:

// 1. The function `lengthAfterTransformations` takes a string `s`, an integer `t`, and a vector `nums` as input.
// 2. It initializes a transformation matrix `transform` of size 26x26 to represent the character transformations.
// 3. For each character in the alphabet (0 to 25), it populates the transformation matrix based on the `nums` vector.
// 4. The transformation matrix is then raised to the power of `t` using the `powerMatrix` function.
// 5. The `powerMatrix` function uses exponentiation by squaring to efficiently compute the matrix raised to a power.
// 6. The `multiplyMatrices` function multiplies two matrices and returns the result.
// 7. After raising the transformation matrix to the power of `t`, the function initializes a frequency vector `freq` to count the occurrences of each character in the input string `s`.
// 8. It multiplies the frequency vector with the transformation matrix to get the transformed frequencies.
// 9. Finally, it sums up the transformed frequencies to get the total length of the string after transformations.
// 10. The result is returned modulo `mod` to avoid overflow.

// 11. The time complexity of this solution is O(26^3 * log(t)), where 26^3 is the time complexity for matrix multiplication and log(t) is for exponentiation.
// 12. The space complexity is O(26^2) for the transformation matrix and O(26) for the frequency vector.
// 13. The overall complexity is efficient for the given constraints, making it suitable for large inputs.
// 14. The solution handles large numbers using `__int128_t` to prevent overflow during matrix multiplication.
// 15. The final result is returned as an integer, ensuring it fits within the constraints of the problem.
// 16. The function is designed to work with the constraints provided in the problem statement, ensuring correctness and efficiency.
