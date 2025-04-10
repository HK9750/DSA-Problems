// Leetcode 2999. Count the Number of Powerful Integers

// Approach Combinatoral Mathematics

class Solution
{
public:
    long long solve(string &str, string &s, int limit)
    {
        long long count = 0;

        if (str.size() < s.size())
            return count;

        int remC = str.size() - s.size();
        string remStr = str.substr(remC);

        for (int i = 0; i < remC; i++)
        {
            int digit = str[i] - '0';

            if (digit <= limit)
            {
                count += digit * pow(limit + 1, remC - i - 1);
            }
            else
            {
                count += pow(limit + 1, remC - i);
                return count;
            }
        }
        if (remStr >= s)
            count++;

        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s)
    {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};

// Explaination

// Let's start with example start = 3101, finish = 6000, limit = 4, s = "1".
// The first step is to convert the start and finish numbers into strings.
// This allows us to easily access each digit of the number and perform operations on them.
// Then we create a function that returs powerful integers in the range [0, finish].
// The function takes the finish number, the string s, and the limit as input parameters.
// The function first check s if the length of the string representation of the number is less than the length of s which is a suffix of the number.
// If it is, we return 0 as there are no powerful integers in this case.
// Next, we calculate the number of digits in the remaining part of the number by subtracting the length of s from the length of str.
// We then create a new string remStr that contains the remaining digits of the number after removing the suffix s.
// This string will be used to compare with the suffix s later on.
// We then loop through each digit of the number and check if it is less than or equal to the limit.
// If it is, we calculate the number of powerful integers that can be formed with the remaining digits by multiplying the digit by (limit + 1) raised to the power of the number of remaining digits minus one.
// This is because for each digit, we can choose any digit from 0 to limit for the remaining digits.
// We add this value to the count variable which keeps track of the total number of powerful integers found so far.
// If the digit is greater than the limit, we add (limit + 1) raised to the power of the number of remaining digits to the count variable and return it as we have found all powerful integers in this case.
// Finally, we check if the remaining string remStr is greater than or equal to the suffix s. If it is, we increment the count variable by 1 as we have found one more powerful integer in this case.
// We return the count variable which contains the total number of powerful integers found in the range [0, finish].
// The final step is to call the function with the start and finish numbers and subtract the result of the function called with start - 1 from the result of the function called with finish.
// This gives us the total number of powerful integers in the range [0, start - 1] as we are looking for the range [start, finish] in which start is included.
// The final result is returned as the output of the function numberOfPowerfulInt.
// The time complexity of this approach is O(n) where n is the number of digits in the finish number. This is because we are iterating through each digit of the number once to calculate the count of powerful integers.
// The space complexity is O(1) as we are not using any additional data structures to store the results. The only space used is for the string representations of the numbers and the count variable.
// Overall, this approach is efficient and works well for the given problem.
