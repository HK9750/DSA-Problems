// Leetcode 2698. Find The Punishment Number Of An Integer

class Solution
{
public:
    bool isValidPartition(string s, int target, int index, int sum)
    {
        if (index == s.size())
            return sum == target;

        int num = 0;
        for (int j = index; j < s.size(); ++j)
        {
            num = num * 10 + (s[j] - '0');
            if (num + sum > target)
                break;
            if (isValidPartition(s, target, j + 1, sum + num))
                return true;
        }
        return false;
    }

    int punishmentNumber(int n)
    {
        int totalSum = 0;
        for (int i = 1; i <= n; ++i)
        {
            int square = i * i;
            if (isValidPartition(to_string(square), i, 0, 0))
            {
                totalSum += square;
            }
        }
        return totalSum;
    }
};

// Explaination:

// We are using backtracking to solve this problem. We are checking if the partition is valid or not by checking if the sum is equal to the target.
// We are using a helper function to check if the partition is valid or not. We are passing the string, target, index, and sum as arguments to the helper function.
// We are using a for loop to iterate through the string and calculate the number by multiplying it by 10 and adding the current digit.
// We are checking if the number + sum is greater than the target. If it is, we break out of the loop.
// We are calling the helper function recursively with the updated index, sum, and number.
// We are returning true if the partition is valid.
// We are calculating the total sum by iterating through the numbers from 1 to n and checking if the partition is valid.
// We are returning the total sum as the punishment number.