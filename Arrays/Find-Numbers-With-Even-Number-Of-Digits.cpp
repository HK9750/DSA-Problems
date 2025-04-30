// Leetcode 1295. Find Numbers with Even Number of Digits

class Solution
{
public:
    int getDigits(int n)
    {
        int count = 0;

        while (n > 0)
        {
            n /= 10;
            count++;
        }

        return count;
    }
    int findNumbers(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int digits = getDigits(nums[i]);
            if (digits % 2 == 0)
                ans++;
        }

        return ans;
    }
};

// Explaination:

// 1. We are given an array of integers and we need to count the number of integers that have an even number of digits.
// 2. We define a helper function `getDigits` that takes an integer `n` as input and returns the number of digits in `n` by repeatedly dividing `n` by 10 until it becomes 0, while incrementing a counter variable `count`.
// 3. In the main function `findNumbers`, we initialize a variable `ans` to store the count of integers with even number of digits.
// 4. We iterate through the array `nums` using a for loop, and for each integer, we call the `getDigits` function to get the number of digits in that integer.
// 5. If the number of digits is even (i.e., `digits % 2 == 0`), we increment the `ans` variable by 1.
// 6. Finally, we return the `ans` variable which contains the count of integers with even number of digits in the array.
// 7. The time complexity of this solution is O(n * d), where n is the number of elements in the array and d is the maximum number of digits in any integer in the array. The space complexity is O(1) since we are using a constant amount of extra space.