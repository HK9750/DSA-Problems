// Leetcode 2523. Closest Prime Numbers In Range

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        if (right < 2)
            return {-1, -1};

        vector<bool> is_prime(right + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= right; i++)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= right; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        vector<int> primes_in_range;
        for (int i = max(2, left); i <= right; i++)
        {
            if (is_prime[i])
            {
                primes_in_range.push_back(i);
            }
        }

        if (primes_in_range.size() < 2)
            return {-1, -1};

        int min_diff = INT_MAX, ans1 = -1, ans2 = -1;

        for (size_t i = 1; i < primes_in_range.size(); i++)
        {
            int diff = primes_in_range[i] - primes_in_range[i - 1];
            if (diff < min_diff)
            {
                min_diff = diff;
                ans1 = primes_in_range[i - 1];
                ans2 = primes_in_range[i];
            }
        }

        return {ans1, ans2};
    }
};

// Explaination:

// 1. First we will find all the prime numbers in the range [left, right] using Sieve of Eratosthenes.
// 2. Then we will find the closest prime numbers in the range [left, right] by iterating over the prime numbers and finding the minimum difference between them.
// 3. Return the closest prime numbers.
