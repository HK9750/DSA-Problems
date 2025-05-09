// Leetcode 3343. Count Number of Balanced Permutations

class Solution
{
    static const int mod = 1e9 + 7;
    using ll = long long;
    vector<ll> fact, inv, invFact;

    void precompute(int n)
    {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % mod;

        inv.assign(n + 1, 1);
        for (int i = 2; i <= n; i++)
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;

        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            invFact[i] = invFact[i - 1] * inv[i] % mod;
    }

public:
    int countBalancedPermutations(const string &s)
    {
        int n = s.size(), sum = 0;
        for (char c : s)
            sum += c - '0';
        if (sum % 2 == 1)
            return 0;

        precompute(n);
        int halfSum = sum / 2, halfLen = n / 2;
        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLen + 1));
        dp[0][0] = 1;

        vector<int> digits(10);
        for (char c : s)
        {
            int d = c - '0';
            digits[d]++;
            for (int i = halfSum; i >= d; i--)
                for (int j = halfLen; j > 0; j--)
                    dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % mod;
        }

        ll res = dp[halfSum][halfLen];
        res = res * fact[halfLen] % mod * fact[n - halfLen] % mod;
        for (int i : digits)
            res = res * invFact[i] % mod;
        return res;
    }
};

// Explaination:

// 1. The problem is about counting the number of balanced permutations of a string `s` consisting of digits.
// 2. A balanced permutation is defined as a permutation where the sum of the digits in the first half is equal to the sum of the digits in the second half.
// 3. The function `countBalancedPermutations` takes a string `s` as input and returns the number of balanced permutations modulo `1e9 + 7`.
// 4. The function first calculates the total sum of the digits in the string `s`.
// 5. If the total sum is odd, it returns `0` because it's impossible to split an odd sum into two equal parts.
// 6. The function `precompute` is called to precompute the factorials, modular inverses, and inverse factorials up to `n`.
// 7. The `dp` vector is initialized to store the number of ways to achieve a certain sum with a certain number of digits.
// 8. The first element of `dp` is set to `1`, indicating that there is one way to achieve a sum of `0` with `0` digits.
// 9. The function iterates through each digit in the string `s`, updating the `dp` vector to count the number of ways to achieve different sums with different numbers of digits.
// 10. The variable `res` is initialized to the number of ways to achieve the target sum with half the length of the string.
// 11. The result is multiplied by the factorial of half the length of the string and the factorial of the remaining length.
// 12. The result is also divided by the factorial of each digit's count to account for duplicate digits.
// 13. Finally, the result is returned modulo `1e9 + 7`.
// 14. The time complexity of the solution is O(n^2), where n is the length of the string `s`, due to the nested loops in the `dp` calculation.