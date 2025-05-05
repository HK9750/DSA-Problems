// Leetcode 790. Domino and Tromino Tiling

class Solution
{
public:
    int M = 1e7 + 7;
    int numTilings(int n)
    {
        if (n == 1 || n == 2)
            return n;

        vector<int> t(n + 1, 0);

        t[1] = 1;
        t[2] = 2;
        t[3] = 5;

        for (int i = 4; i <= n; i++)
        {
            t[i] = (2 * t[i - 1] % M + t[i - 3] % M) % M;
        }

        return t[n];
    }
};

// Explaination:

// 1. The problem is about tiling a 2 x n board using dominoes and trominoes.
// 2. A domino covers two squares, and a tromino covers three squares. We need to find the number of ways to tile the board using these pieces.
// 3. The function `numTilings` takes an integer `n` as input, which represents the length of the board.
// 4. We define a constant `M` to handle large numbers and prevent overflow during calculations.
// 5. We handle the base cases for `n = 1`, `n = 2`, and `n = 3` separately, as they have known results.
// 6. For `n = 1`, there is only one way to tile the board (using a single domino).
// 7. For `n = 2`, there are two ways to tile the board (using two dominoes or one tromino).
// 8. For `n = 3`, there are five ways to tile the board (using three dominoes, one tromino and one domino, etc.).
// 9. For larger values of `n`, we use a dynamic programming approach to calculate the number of ways to tile the board.
// 10. We create a vector `t` of size `n + 1` to store the number of ways to tile the board for each length from 0 to n.
// 11. We initialize the first three values of `t` based on the base cases.
// 12. We then iterate from `i = 4` to `n`, calculating the number of ways to tile the board using the recurrence relation:
//     - `t[i] = (2 * t[i - 1] + t[i - 3]) % M`
//     - This relation accounts for the two cases: placing a domino vertically or horizontally, and placing a tromino.
// 13. Finally, we return the value of `t[n]`, which represents the number of ways to tile the board of length `n`.
// 14. The time complexity of this solution is O(n), as we are iterating through the range from 4 to n once. The space complexity is O(n) due to the use of the vector `t` to store the results for each length.
