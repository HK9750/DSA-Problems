// Leetcode 1922. Count Good Numbers

// Binary Exponentiation or Fast Exponentiation is a technique to compute a^b in O(log b) time complexity.
// It is used to calculate large powers of numbers efficiently.

class Solution
{
public:
    const long long mod = 1e9 + 7;
    long long findPower(long long a, long long b)
    {
        if (b == 0)
            return 1;

        long long half = findPower(a, b / 2);
        long long res = (half * half) % mod;

        if (b % 2 == 1)
        {
            res = (res * a) % mod;
        }

        return res;
    }
    int countGoodNumbers(long long n)
    {
        return (findPower(5, (n + 1) / 2) * findPower(4, n / 2)) % mod;
    }
};

// Explaination:

// 1. The function `findPower` calculates a^b % mod using binary exponentiation.
// 2. The `countGoodNumbers` function calculates the number of good numbers based on the given formula:
// The even index digits can be 0, 2, 4, 6, or 8 (5 choices), and the odd index digits can be 2 , 3, 5 and 7 (4 choices) because only prime numbers are allowed.
// 3. The total number of good numbers is calculated as (5^(n+1)/2) * (4^(n/2)) % mod, where n is the length of the number.
// 4. The result is returned as an integer.
// 5. The time complexity of the solution is O(log n) due to the binary exponentiation method used in `findPower`.
// 6. The space complexity is O(1) as we are using a constant amount of space but the recursion stack space can go up to O(log n) in the worst case.