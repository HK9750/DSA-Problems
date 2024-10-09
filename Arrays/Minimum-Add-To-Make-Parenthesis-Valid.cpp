// Leetcode 921 - Minimum Add to Make Parentheses Valid

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int open = 0, mismatch = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else
            {
                if (open)
                    --open;
                else
                    mismatch++;
            }
        }
        return open + mismatch;
    }
};

// Explaination:

// We are given a string s consisting of characters '(' and ')'. We have to find the minimum number of parentheses we need to add to make the string valid.
// We will iterate over the characters of the string s.
// If the current character is '(', we will increment the open count.
// If the current character is ')', we will check if the open count is greater than 0. If it is, we will decrement the open count. Otherwise, we will increment the mismatch count.
// At the end of the iteration, we will return the sum of the open count and the mismatch count as the answer.
