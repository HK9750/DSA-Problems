// Leetcode 2145. Count the Hidden Sequences

class Solution
{
public:
    int numberOfArrays(vector<int> &diff, int lower, int upper)
    {
        long sum = 0, maxi = 0, mini = 0;
        for (int i : diff)
        {
            sum += i;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        return max(0L, upper - lower - maxi + mini + 1);
    }
};

// Explaination:

// The problem is about counting the number of hidden sequences based on the given differences and the range defined by lower and upper bounds.
// Why we need to find the maximum and minimum and sum of the differences?
// The sum of the differences gives us the total change in value from the starting point, and the maximum and minimum values help us determine the range of possible starting points for the hidden sequences.
// The formula used in the solution is:
// return max(0L, upper - lower - maxi + mini + 1);
// This formula calculates the number of valid starting points for the hidden sequences based on the given lower and upper bounds, taking into account the maximum and minimum values of the differences.
// The result is returned as the final count of hidden sequences that can be formed within the specified range.
// The use of max(0L, ...) ensures that we do not return a negative count in case the range is invalid or too small to accommodate any hidden sequences.
// The final result is the number of valid hidden sequences that can be formed based on the given differences and the specified range.
// The time complexity of this solution is O(n), where n is the length of the diff array, as we are iterating through the array once to calculate the sum, maximum, and minimum values. The space complexity is O(1) since we are using a constant amount of extra space for the variables.