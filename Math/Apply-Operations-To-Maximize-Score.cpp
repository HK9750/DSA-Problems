// Leetcode 2818. Apply Operations to Maximize Score
// One of the hardest question that i have ever tried to solve on leetcode

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        vector<int> primeScores = findPrimeScores(nums);
        vector<int> nextGreater = findNextGreater(primeScores);
        vector<int> prevGreater = findPrevGreater(primeScores);
        int n = nums.size();
        vector<long long> subarrays(n, 0);
        for (int i = 0; i < n; i++)
        {
            subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
        }
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++)
        {
            sortedNums[i] = {nums[i], i};
        }
        sort(sortedNums.begin(), sortedNums.end(), greater<>());
        long long score = 1;
        int idx = 0;
        while (k > 0)
        {
            auto [num, i] = sortedNums[idx];
            long long operations = min((long long)k, subarrays[i]);
            score = (score * findPower(num, operations)) % MOD;
            k -= operations;
            idx++;
        }
        return score;
    }

private:
    const int MOD = 1e9 + 7;

    long long findPower(long long a, long long b)
    {
        if (b == 0)
            return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) % MOD;
        if (b & 1)
            result = (result * a) % MOD;
        return result;
    }

    vector<int> getPrimes(int limit)
    {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
        for (int i = 2; i * i <= limit; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= limit; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= limit; i++)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
            }
        }
        return primes;
    }

    vector<int> findPrimeScores(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(maxElement);
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for (int prime : primes)
            {
                if ((long long)prime * prime > num)
                    break;
                if (num % prime != 0)
                    continue;
                primeScores[i]++;
                while (num % prime == 0)
                {
                    num /= prime;
                }
            }
            if (num > 1)
            {
                primeScores[i]++;
            }
        }
        return primeScores;
    }

    vector<int> findNextGreater(vector<int> &primeScores)
    {
        int n = primeScores.size();
        vector<int> nextGreater(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i])
            {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextGreater;
    }

    vector<int> findPrevGreater(vector<int> &primeScores)
    {
        int n = primeScores.size();
        vector<int> prevGreater(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && primeScores[st.top()] < primeScores[i])
            {
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevGreater;
    }
};

// Explaination:

// 1. Find the prime scores of each number in the array using the Sieve of Eratosthenes algorithm.
// 2. Find the next greater and previous greater elements for each prime score using a stack. This helps in calculating the number of subarrays that can be formed with each prime score as the maximum element.
// 3. Sort the numbers in descending order based on their values and iterate through them, applying operations to maximize the score.
// 4. For each number, calculate the maximum possible score by applying operations to the prime scores and updating the remaining operations accordingly.
// 5. Return the final score modulo 1e9 + 7.