// Leetcode 2843. Count Symmetric Integers

class Solution
{
public:
    bool solve(int num)
    {
        string numStr = to_string(num);
        int n = numStr.size();

        if (n % 2 != 0)
            return false;

        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < n / 2; i++)
        {
            sum1 += numStr[i] - '0';
        }

        for (int i = n / 2; i < n; i++)
        {
            sum2 += numStr[i] - '0';
        }

        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if (solve(i))
                count++;
        }
        return count;
    }
};

// Explaination:

// 1. The function `solve` checks if a number is symmetric by comparing the sum of the first half of its digits with the sum of the second half.
// 2. The function `countSymmetricIntegers` iterates through the range from `low` to `high`, calling `solve` for each number and counting how many are symmetric.
// 3. The function returns the total count of symmetric integers in the given range.
// 4. The time complexity is O(n * m), where n is the range size and m is the number of digits in the largest number.
// 5. The space complexity is O(1) since we are using a constant amount of space for variables.