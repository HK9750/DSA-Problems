// Leetcode 2601. Prime Subtraction Operation
// Solution 1 - Using Sieve of Eratosthenes Algorithm
// Solution 2 - Using Sieve of Eratosthenes Algorithm
// Solution 3 - Using Sieve of Atkin Algorithm

class Solution
{
public:
    bool primeSubOperation(vector<int> &A)
    {
        bool prime[1001] = {[0 ... 1000] = true};
        vector<int> primes;
        for (int i = 2; i <= 1000; ++i)
        {
            if (!prime[i])
                continue;
            primes.push_back(i);
            int j = i * i;
            for (; j <= 1000; j += i)
                prime[j] = false;
        }
        for (int i = 0; i < A.size(); ++i)
        {
            int prev = i == 0 ? -1 : A[i - 1],
                j = lower_bound(begin(primes), end(primes), A[i]) -
                    begin(primes) - 1;
            while (j >= 0 && A[i] - primes[j] <= prev)
                --j;
            if (j >= 0)
                A[i] -= primes[j];
            if (A[i] <= prev)
                return false;
        }
        return true;
    }
};

// Explanation:

// We will first find all the prime numbers from 2 to 1000. We will use the sieve of Eratosthenes algorithm to find all the prime numbers. We will store all the prime numbers in the vector primes.
// Now, we will iterate over the array A. For each element A[i], we will find the largest prime number less than A[i] and subtract it from A[i]. We will do this until A[i] is greater than the previous element A[i-1]. If we are unable to find any prime number less than A[i] such that A[i] - primes[j] is greater than A[i-1], then we will return false.
// If we are able to find a prime number for each element A[i] such that A[i] - primes[j] is greater than A[i-1], then we will return true.

class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        int maxElement = getMaxElement(nums);

        // Create Sieve of Eratosthenes array to identify prime numbers
        vector<bool> sieve(maxElement + 1, true);
        sieve[1] = false;
        for (int i = 2; i <= sqrt(maxElement + 1); i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j <= maxElement; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        // Check if array can be made strictly increasing by subtracting prime numbers
        int currValue = 1;
        int i = 0;
        while (i < nums.size())
        {
            int difference = nums[i] - currValue;

            // Return false if current number is already smaller than required value
            if (difference < 0)
            {
                return false;
            }

            // Move to next number if difference is prime or zero
            if (sieve[difference] == true || difference == 0)
            {
                i++;
                currValue++;
            }
            else
            {
                currValue++;
            }
        }
        return true;
    }

private:
    // Helper method to find maximum element in array
    int getMaxElement(vector<int> &nums)
    {
        int max = -1;
        for (int num : nums)
        {
            if (num > max)
            {
                max = num;
            }
        }
        return max;
    }
};

// Explanation:

// We will first find the maximum element in the array nums. We will use this maximum element to create a sieve of Eratosthenes array to identify prime numbers.
// We will iterate over the array nums. For each element nums[i], we will find the difference between nums[i] and the current value currValue. If the difference is less than 0, then we will return false as the current number is already smaller than the required value. If the difference is prime or zero, then we will move to the next number. Otherwise, we will increment the current value and check the difference again.
// If we are able to iterate over the entire array nums without returning false, then we will return true. This means that the array can be made strictly increasing by subtracting prime numbers.

class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        int maxElement = getMaxElement(nums);

        // Sieve of Atkin
        vector<bool> sieve(maxElement + 1, false);
        if (maxElement > 2)
            sieve[2] = true;
        if (maxElement > 3)
            sieve[3] = true;

        for (int x = 1; x * x <= maxElement; x++)
        {
            for (int y = 1; y * y <= maxElement; y++)
            {
                int n = (4 * x * x) + (y * y);
                if (n <= maxElement && (n % 12 == 1 || n % 12 == 5))
                {
                    sieve[n] = !sieve[n];
                }

                n = (3 * x * x) + (y * y);
                if (n <= maxElement && n % 12 == 7)
                {
                    sieve[n] = !sieve[n];
                }

                n = (3 * x * x) - (y * y);
                if (x > y && n <= maxElement && n % 12 == 11)
                {
                    sieve[n] = !sieve[n];
                }
            }
        }

        for (int i = 5; i * i <= maxElement; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j <= maxElement; j += i * i)
                {
                    sieve[j] = false;
                }
            }
        }

        int currValue = 1;
        int i = 0;
        while (i < nums.size())
        {
            int difference = nums[i] - currValue;

            if (difference < 0)
            {
                return false;
            }

            if (sieve[difference] == true || difference == 0)
            {
                i++;
                currValue++;
            }
            else
            {
                currValue++;
            }
        }
        return true;
    }

private:
    int getMaxElement(vector<int> &nums)
    {
        int max = -1;
        for (int num : nums)
        {
            if (num > max)
            {
                max = num;
            }
        }
        return max;
    }
};

// Explanation:
// We will first find the maximum element in the array nums. We will use this maximum element to create a sieve of Atkin array to identify prime numbers.
// We will iterate over the array nums. For each element nums[i], we will find the difference between nums[i] and the current value currValue. If the difference is less than 0, then we will return false as the current number is already smaller than the required value. If the difference is prime or zero, then we will move to the next number. Otherwise, we will increment the current value and check the difference again.
// If we are able to iterate over the entire array nums without returning false, then we will return true. This means that the array can be made strictly increasing by subtracting prime numbers.
