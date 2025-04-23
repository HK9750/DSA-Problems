// Leetcode 1399. Count Largest Group

class Solution
{
    int findSum(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            sum += (n % 10);
            n /= 10;
        }

        return sum;
    }

public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> mp;
        int maxi = -1;
        for (int i = 1; i <= n; i++)
        {
            if (i < 10)
            {
                mp[i]++;
                maxi = max(maxi, mp[i]);
            }
            else
            {
                int s = findSum(i);
                mp[s]++;
                maxi = max(maxi, mp[s]);
            }
        }
        int count = 0;
        for (auto &number : mp)
        {
            if (number.second == maxi)
                count++;
        }
        return count;
    }
};

// Explaination:

// The code defines a function `countLargestGroup` that counts the number of groups with the largest size based on the sum of digits of numbers from 1 to n. It uses a hash map to store the frequency of each digit sum and finds the maximum frequency. Finally, it counts how many digit sums have that maximum frequency and returns that count.
// The helper function `findSum` calculates the sum of digits of a given number. The main function iterates through numbers from 1 to n, computes their digit sums, and updates the frequency map accordingly. The time complexity is O(n) and space complexity is O(n) in the worst case.
// The solution is efficient and works well within the given constraints (1 <= n <= 10^4).